/*****************************************************************************
#                                                                            *
# Copyright 2019 AT&T Intellectual Property                                  *
# Copyright 2019 Nokia                                                       *
#                                                                            *
# Licensed under the Apache License, Version 2.0 (the "License");            *
# you may not use this file except in compliance with the License.           *
# You may obtain a copy of the License at                                    *
#                                                                            *
#      http://www.apache.org/licenses/LICENSE-2.0                            *
#                                                                            *
# Unless required by applicable law or agreed to in writing, software        *
# distributed under the License is distributed on an "AS IS" BASIS,          *
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
# See the License for the specific language governing permissions and        *
# limitations under the License.                                             *
#                                                                            *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>		//for close()
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>	//for inet_ntop()
#include <assert.h>

#include "e2sim_sctp.hpp"

#include <cerrno>

int sctp_start_server(const char *server_ip_str, const int server_port)
{
  if(server_port < 1 || server_port > 65535) {
      LOG_E("Invalid port number (%d). Valid values are between 1 and 65535.\n", server_port);
      exit(EXIT_FAILURE);
  }

  int server_fd, af;
  struct sockaddr* server_addr;
  size_t addr_len;

  struct sockaddr_in  server4_addr;
  memset(&server4_addr, 0, sizeof(struct sockaddr_in));

  struct sockaddr_in6 server6_addr;
  memset(&server6_addr, 0, sizeof(struct sockaddr_in6));

  if(inet_pton(AF_INET, server_ip_str, &server4_addr.sin_addr) == 1)
  {
    server4_addr.sin_family = AF_INET;
    server4_addr.sin_port   = htons(server_port);

    server_addr = (struct sockaddr*)&server4_addr;
    af          = AF_INET;
    addr_len    = sizeof(server4_addr);
  }
  else if(inet_pton(AF_INET6, server_ip_str, &server6_addr.sin6_addr) == 1)
  {
    server6_addr.sin6_family = AF_INET6;
    server6_addr.sin6_port   = htons(server_port);

    server_addr = (struct sockaddr*)&server6_addr;
    af          = AF_INET6;
    addr_len    = sizeof(server6_addr);
  }
  else {
    LOG_E("inet_pton()");
    exit(EXIT_FAILURE);
  }

  if((server_fd = socket(af, SOCK_STREAM, IPPROTO_SCTP)) == -1) {
    LOG_E("socket");
    exit(EXIT_FAILURE);
  }

  //set send_buffer
  // int sendbuff = 10000;
  // socklen_t optlen = sizeof(sendbuff);
  // if(getsockopt(server_fd, SOL_SOCKET, SO_SNDBUF, &sendbuff, &optlen) == -1) {
  //   LOG_E("getsockopt send");
  //   exit(EXIT_FAILURE);
  // }
  // else
  //   LOG_D("[SCTP] send buffer size = %d\n", sendbuff);


  if(bind(server_fd, server_addr, addr_len) == -1) {
    LOG_E("bind");
    exit(EXIT_FAILURE);
  }

  if(listen(server_fd, SERVER_LISTEN_QUEUE_SIZE) != 0) {
    LOG_E("listen");
    exit(EXIT_FAILURE);
  }

  assert(server_fd != 0);

  LOG_I("[SCTP] Server started on %s:%d", server_ip_str, server_port);

  return server_fd;
}

int sctp_start_client(const char *server_ip_str, const int server_port, const int client_port)
{
  int client_fd;

  struct sockaddr* server_addr;
  size_t server_addr_len;

  struct sockaddr_in  server4_addr{};
  memset(&server4_addr, 0, sizeof(struct sockaddr_in));

  struct sockaddr_in6 server6_addr{};
  memset(&server6_addr, 0, sizeof(struct sockaddr_in6));

  if(inet_pton(AF_INET, server_ip_str, &server4_addr.sin_addr) == 1)
  {
    server4_addr.sin_family = AF_INET;
    server4_addr.sin_port   = htons(server_port);
    server_addr = (struct sockaddr*)&server4_addr;
    server_addr_len    = sizeof(server4_addr);
  }
  else if(inet_pton(AF_INET6, server_ip_str, &server6_addr.sin6_addr) == 1)
  {
    server6_addr.sin6_family = AF_INET6;
    server6_addr.sin6_port   = htons(server_port);
    server_addr = (struct sockaddr*)&server6_addr;
    server_addr_len    = sizeof(server6_addr);
  }
  else {
    LOG_E("inet_pton() server, error message: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if((client_fd = socket(AF_INET6, SOCK_STREAM, IPPROTO_SCTP)) == -1)
  {
     LOG_E("Socket creation, error message: %s", strerror(errno));
     exit(EXIT_FAILURE);
  }

  // int sendbuff = 10000;
  // socklen_t optlen = sizeof(sendbuff);
  // if(getsockopt(client_fd, SOL_SOCKET, SO_SNDBUF, &sendbuff, &optlen) == -1) {
  //   LOG_E("getsockopt send");
  //   exit(1);
  // }
  // else
  //   LOG_D("[SCTP] send buffer size = %d\n", sendbuff);

  //--------------------------------
  //Bind before connect
  auto optval = 1;
  if(setsockopt(client_fd, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof optval) != 0 ){
    LOG_E("setsockopt port, error message: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval) != 0) {
    LOG_E("setsockopt addr, error message: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

    struct sockaddr_in6  client6_addr {};
    client6_addr.sin6_family = AF_INET6;
    client6_addr.sin6_port   = htons(client_port);
    client6_addr.sin6_addr   = in6addr_any;

  LOG_I("[SCTP] Binding client socket with source port %d", client_port);
  if(bind(client_fd,(struct sockaddr*) &client6_addr,sizeof(client6_addr)) == -1) {
    LOG_E("bind");
    exit(EXIT_FAILURE);
  }
  // end binding ---------------------

  LOG_I("[SCTP] Connecting to server at %s:%d ...", server_ip_str, server_port);
  if(connect(client_fd, server_addr, server_addr_len) == -1) {
    LOG_E("[SCTP] Connection error: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }
  assert(client_fd != 0);

  LOG_I("[SCTP] Connection established");

  return client_fd;
}

int sctp_accept_connection(const char *server_ip_str, const int server_fd)
{
  LOG_I("[SCTP] Waiting for new connection...");

  struct sockaddr client_addr;
  socklen_t       client_addr_size;
  int             client_fd;

  //Blocking call
  client_fd = accept(server_fd, &client_addr, &client_addr_size);

  if(client_fd == -1){
    LOG_E("accept()");
    close(client_fd);
    exit(EXIT_FAILURE);
  }

  //Retrieve client IP_ADDR
  char client_ip6_addr[INET6_ADDRSTRLEN], client_ip4_addr[INET_ADDRSTRLEN];
  if(strchr(server_ip_str, ':') != NULL) //IPv6
  {
    struct sockaddr_in6* client_ipv6 = (struct sockaddr_in6*)&client_addr;
    inet_ntop(AF_INET6, &(client_ipv6->sin6_addr), client_ip6_addr, INET6_ADDRSTRLEN);
    LOG_I("[SCTP] New client connected from %s", client_ip6_addr);
  }
  else {
    struct sockaddr_in* client_ipv4 = (struct sockaddr_in*)&client_addr;
    inet_ntop(AF_INET, &(client_ipv4->sin_addr), client_ip4_addr, INET_ADDRSTRLEN);
    LOG_I("[SCTP] New client connected from %s", client_ip4_addr);
  }

  return client_fd;
}

int sctp_send_data(int &socket_fd, sctp_buffer_t &data)
{
  LOG_D("in sctp send data func\n");
  LOG_D("data.len is %d", data.len);
  int sent_len = send(socket_fd, data.buffer, data.len, 0);
  LOG_D("after getting sent_len\n");

  if(sent_len == -1) {
    LOG_E("[SCTP] sctp_send_data, error message: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }

  return sent_len;
}

int sctp_send_data_X2AP(int &socket_fd, sctp_buffer_t &data)
{
  /*
  int sent_len = sctp_sendmsg(socket_fd, (void*)(&(data.buffer[0])), data.len,
                  NULL, 0, (uint32_t) X2AP_PPID, 0, 0, 0, 0);

  if(sent_len == -1) {
    LOG_E("[SCTP] sctp_send_data");
    exit(1);
  }
  */
  return 1;
}

/*
Receive data from SCTP socket
Outcome of recv()
-1: exit the program
0: close the connection
+: new data
*/
int sctp_receive_data(int &socket_fd, sctp_buffer_t &data)
{
  // Clear out the data before receiving
  memset(data.buffer, 0, MAX_SCTP_BUFFER);
  data.len = 0;

  // Receive data from the socket
  int recv_len = recv(socket_fd, &data.buffer, sizeof(data.buffer), 0);

  if(recv_len == -1)
  {
    LOG_E("[SCTP] recv: %s", strerror(errno));
    exit(EXIT_FAILURE);
  }
  else if (recv_len == 0)
  {
    LOG_E("[SCTP] Connection closed by remote peer");
    if(close(socket_fd) == -1)
    {
      LOG_E("[SCTP] close, error message: %s", strerror(errno));
    }
    return -1;
  }

  data.len = recv_len;

  return recv_len;
}
