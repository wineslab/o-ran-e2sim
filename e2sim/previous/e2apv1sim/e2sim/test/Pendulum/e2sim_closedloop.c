/*
 *
 * Copyright 2019 AT&T Intellectual Property
 * Copyright 2019 Nokia
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>             //for close()
#include <arpa/inet.h>  //for inet_ntop()

#include "e2sim_defs.h"
#include "e2sim_sctp.h"
#include "x2ap_message_handler.h"

//OSN 2019
#include "Pendulum_asn_codec.h"
#include "adruino_serial.h"

//rmr
#include <errno.h>
#include <sys/epoll.h>
#include <rmr/rmr.h>
#include "rmr_wrapper.h"

static void pendulum_control_E2_agent(int client_fd)
{
 fprintf(stderr, "--------------------------------------\n");
 fprintf(stderr, "E2 AGENT - START PENDULUM CONTROL\n");
 fprintf(stderr, "--------------------------------------\n");

 uint8_t   *buffer;
 uint32_t  len;
 clock_t   begin;
 double    rtt; //ms

 uint8_t recv_buf[MAX_SCTP_BUFFER];
 int     recv_len;

 double angle;
 double torque;
 long   sqn;
 int    count = 0;

 //serial
 // int serial_fd;
 char serial_buffer[MAX_SERIAL_BUFFER];
 // serial_fd = start_serial_inferface(DEFAULT_BAUDRATE, DEFAULT_SERIAL_PORT);
 //
 // char *delay_str_prev = "$0#\n";
 // //char *delay_str_new;
 //
 // int MSG_NUM = 10;
 //
 // //Always start with 0 delay
 // serialport_write(serial_fd, "$0#\n");

 // for(int i = 0; i < MSG_NUM; i++)
 while(1)
 {

   fprintf(stderr, "----------------\n");
   count += 1;
   buffer  = NULL;
   len     = 0;

   // //1.Read from serial
   // serial_readline(serial_fd, serial_buffer, MAX_SERIAL_BUFFER);
   // if(serial_buffer[0] == '\n')
   // {
   //   //fprintf(stderr, "RECEIVED EOL\n");
   //   continue;
   // }
   // //fprintf(stderr, "[Adruino] %s", serial_buffer);
   usleep(5*1000);

   snprintf(serial_buffer, sizeof(serial_buffer)-1, "E2 AGENT PING");

   begin = clock();

   //2. Encode pendulum angle to ASN1 message

   len = pendulum_create_asn_msg(&buffer, 0, 0, 0, serial_buffer);

   //3. Send ASN1 message to socket
   if(sctp_send_to_socket(client_fd, buffer, (size_t)len) > 0){
     fprintf(stderr, "Sent ASN1 message to E2 Termination\n");
   }

   // 4. Receive response from E2 Termination
   memset(recv_buf, 0, sizeof(recv_buf));
   recv_len = 0;
   recv_len = recv(client_fd, &recv_buf, sizeof(recv_buf), 0);
   if(recv_len == -1)
   {
     perror("recv()");
     return;
   }

   char *recv_str;
   recv_str = pendulum_get_strval(recv_buf, recv_len);
   fprintf(stderr, "Received response message #%d from xApp: %s\n", count, recv_str);

   // 5. TODO: Send response to serial
   // Compare if delay has changed:
   // if(strcmp(delay_str_prev, recv_str) != 0) {
   //   serial_writeline(serial_fd, recv_str);
   // }

   //serial_writeline(serial_fd, recv_str);

   //Write to a file
   FILE *f;
   f = fopen("arduino_delay.txt", "w");
   fprintf(f, "%s", recv_str);
   fclose(f);

   begin = clock() - begin;
   rtt = 1000*((double)begin)/CLOCKS_PER_SEC; // in ms
   fprintf(stderr, "E2Agent-RIC-E2Agent RTT = %f ms\n", rtt);

 }

 close(client_fd);
}

int main(int argc, char *argv[])
{
 fprintf(stderr, "E2 AGENT - PENDULUM CONTROL. Version %s\n", VERSION);

 // char *recv_str = "9";
 // int delay;
 //
 // printf("delay = %d\n", atoi(recv_str));
 //
 // long delay = 22.5;
 //
 // printf("delay = %d\n", (int)delay);
 // return 0;

 // test_rmr(); return 0;
 // test_adruino_serial(); return 0;

 char* server_ip         = DEFAULT_SCTP_IP;
 int server_port         = X2AP_SCTP_PORT;

 int             server_fd;
 int             client_fd;
 struct sockaddr client_addr;
 socklen_t       client_addr_size;

 //read input
 if(argc == 3) //user provided IP and PORT
 {
   server_ip = argv[1];
   server_port = atoi(argv[2]);
   if(server_port < 1 || server_port > 65535) {
     fprintf(stderr, "Invalid port number (%d). Valid values are between 1 and 65535.\n"            , server_port);
     return -1;
   }
 }
 else if(argc == 2) //user provided only IP
 {
   server_ip = argv[1];
 }
 else if(argc == 1)
 {
   server_ip = DEFAULT_SCTP_IP;
 }
 else
 {
   fprintf(stderr, "Unrecognized option.\n");
   fprintf(stderr, "Usage: %s [SERVER IP ADDRESS] [SERVER PORT]\n", argv[0]);
   return -1;
 }

 server_fd = sctp_start_server(server_ip, server_port);

 fprintf(stderr, "Waiting for connection...\n");
 client_fd = accept(server_fd, &client_addr, &client_addr_size);
 if(client_fd == -1){
   perror("accept()");
   close(client_fd);
   return -1;
 }

 //Todo: retrieve client ip addr
 struct sockaddr_in* client_ipv4 = (struct sockaddr_in*)&client_addr;
 char client_ip_addr[INET_ADDRSTRLEN];
 inet_ntop(AF_INET, &(client_ipv4->sin_addr), client_ip_addr, INET_ADDRSTRLEN);

 fprintf(stderr, "New client connected from %s\n", client_ip_addr);

 // while(1) //put while loop if want to receive from multiple clients
 // {
   uint8_t recv_buf[MAX_SCTP_BUFFER];
   int     recv_len = 0;

   memset(recv_buf, 0, sizeof(recv_buf));

   fprintf(stderr, "------------------------\n");
   recv_len = recv(client_fd, &recv_buf, sizeof(recv_buf), 0);
   if(recv_len == -1)
   {
     perror("recv()");
     return -1;
   }
   else if(recv_len == 0)
   {
     fprintf(stderr, "\nConnection from %s closed by remote peer\n", client_ip_addr);
     if(close(client_fd) == -1)
     {
       perror("close");
     }
     return -1;
   }

   //fprintf(stderr, "Received a message of size %d\n", recv_len);

   //TODO: check PPID here before calling x2ap handler

   sctp_data_t response = {NULL, 0};
   x2ap_eNB_handle_message(recv_buf, recv_len, &response);

   //=======================================================================
   //reply to client
   assert(response.data != NULL);
   if(sctp_send_to_socket(client_fd, response.data, (size_t)response.len) > 0){
     fprintf(stderr, "Sent X2 SETUP RESPONSE \n");
   } else{
     perror("send to socket");
     return -1;
   }

   fprintf(stderr, "X2 Setup Completed \n");

   //=========================================================================
   // Pendulum interaction
   // Send pendulum state to E2 Termination and receive response
   pendulum_control_E2_agent(client_fd);
 // } //end while

 close(client_fd);

 return 0;
}
