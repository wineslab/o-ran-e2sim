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

/*! \file e2sim_sctp.h
 */

#ifndef E2SIM_SCTP_H
#define E2SIM_SCTP_H

void *handle_connection(void *thread_data);

int sctp_start_server(const char *server_ip_str, const int server_port);

int sctp_start_client(const char *server_ip_str, const int server_port);

int sctp_send_to_socket(int sockfd, const void *buf, size_t len);

//int sctp_recv_from_socket(int sockfd, void *buf, size_t buf_size);

//test only
void client_send_multiple_test_msg(int client_fd);

#endif
