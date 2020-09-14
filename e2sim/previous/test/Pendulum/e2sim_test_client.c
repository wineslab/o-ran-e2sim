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
#include <string.h>
#include <time.h>
#include <unistd.h>		//for close()
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>	//for inet_ntop()
#include <assert.h>

#include "e2sim_defs.h"
#include "e2sim_sctp.h"
#include "x2ap_message_handler.h"

#include "x2ap_generate_messages.h"

//OSN 2019
#include "Pendulum_asn_codec.h"

//rmr
#include <errno.h>
#include <sys/epoll.h>
#include <rmr/rmr.h>
#include "rmr_wrapper.h"

//time
#include <sys/time.h>

//these are the metrics being sent to the a1 mediator
int ave_ric_rtt_last_epoch=0;
int ave_msg_rate_last_epoch=0;
int ave_pendulum_msg_rate_last_epoch=0;

int total_rtt_current_epoch=0;
int total_messages_current_epoch=0;
int total_pendulum_messages_current_epoch=0;

int total_rtt_entries_current_epoch=0;

int epoch_duration = 1;//in seconds

long rtt_epoch_start_time =0;

long msg_rate_epoch_start_time =0;
long pendulum_msg_rate_epoch_start_time = 0;

long current_timestamp_in_us(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}
void update_rtt_metrics(long rtt){//called every time there is a new rtt measurement
	if(rtt_epoch_start_time == 0)
		rtt_epoch_start_time = current_timestamp_in_us(); //start of a new epoch

	total_rtt_current_epoch = total_rtt_current_epoch+rtt;
	total_rtt_entries_current_epoch++;

	if((current_timestamp_in_us() - rtt_epoch_start_time) > (epoch_duration*1000000)){//an epoch has passed
		ave_ric_rtt_last_epoch = total_rtt_current_epoch/total_rtt_entries_current_epoch;
		total_rtt_current_epoch =0;
		rtt_epoch_start_time = 0;
	}
}

void update_msg_rate_metrics(){
	if(msg_rate_epoch_start_time == 0)
		msg_rate_epoch_start_time= current_timestamp_in_us(); //start of a new epoch
	total_messages_current_epoch++;
	if((current_timestamp_in_us() - msg_rate_epoch_start_time) > (epoch_duration*1000000)){//an epoch has passed
		ave_msg_rate_last_epoch = total_messages_current_epoch;
		total_messages_current_epoch =0;
		msg_rate_epoch_start_time =0;
	}
}

void update_pendulum_control_rate()
{
	if(pendulum_msg_rate_epoch_start_time == 0)
		pendulum_msg_rate_epoch_start_time = current_timestamp_in_us(); //start of a new epoch
	total_pendulum_messages_current_epoch++;

	if((current_timestamp_in_us() - pendulum_msg_rate_epoch_start_time) > (epoch_duration*1000000)){//an epoch has passed
		ave_pendulum_msg_rate_last_epoch = total_pendulum_messages_current_epoch;
		total_pendulum_messages_current_epoch = 0;
		pendulum_msg_rate_epoch_start_time = 0;
	}

}

void send_metrics_to_a1_med(struct rmr_context *rmr_c){
	 int mtype=103;
	 char* metrics= malloc(1024);
	 int time_int = current_timestamp_in_us()/1000000;
	 //int ave_msg_rate_last_epoch=500;
	 snprintf(metrics, 1024, "{%s:%d, %s:%d, %s:%d, %s:%d}", \
	 									"\"latency\"", ave_ric_rtt_last_epoch/1000, \
										"\"ricload\"",ave_msg_rate_last_epoch, \
										"\"load\"",ave_pendulum_msg_rate_last_epoch, \
										"\"time\"",time_int);
	 rmr_send_wrapper(rmr_c, mtype, metrics);
	 printf("Sent message of type:%d to a1_med with content:%s\n",mtype,metrics);
}

void forward_to_load_consumer(struct rmr_context *rmr_c){//the content does not matter
	 int mtype=105;
	 char* load_message="dummy load";
	 rmr_send_wrapper(rmr_c, mtype, load_message);
	 printf("Sent message of type:%d to load consumer with content:%s\n",mtype,load_message);
}

static void pendulum_control_E2_Termination(int client_fd)
{
  printf("--------------------------------------\n");
  printf("E2 TERMINATION - START PENDULUM CONTROL\n");
  printf("--------------------------------------\n");

  uint8_t *send_buffer;
  uint8_t recv_buffer[1024];
  uint32_t send_len;
  uint32_t recv_len;

  clock_t begin = clock();
  double rtt;
  double rtt_stats[100000];
  long   recv_count = 0;
  long   fail_count = -1; //ignore the first message (see adruino code)

  long   sqn;
  int    count = 0;

  //=================================

  //Setup context
  struct rmr_context *rmr_c; //obtain our enhanced rmr_context
  int 	mtype = 0;						// we can loop through several message types
  char*	lport = "43086";				// default listen port
  long	rcount = 0;						// number of acks received

  if( (eparm = getenv( "E2TERM_RMR_RCV_PORT" )) != NULL ) {
                lport = strdup( eparm );
  }

  rmr_c = rmr_init_wrapper(lport);

  while( ! rmr_ready( rmr_c->mrc ) ) {
    fprintf( stderr, "<TEST> waiting for RMR to indicate ready\n" );
    sleep( 1 );
  }
  fprintf( stderr, "[OK]   initialisation complete\n" );


  //==================================
  long loop_start_time = 0;
  while(1){
    printf("----------------\n");
    count += 1;
    loop_start_time = current_timestamp_in_us();
    //0. Receiving ASN message from E2 Agent
    memset(recv_buffer, 0, sizeof(recv_buffer));
    printf("Time to receive asn message after starting main loop: %ld microseconds \n",current_timestamp_in_us() - loop_start_time);
    recv_len = 0;

    printf(" 1Time to receive asn message after starting main loop: %ld microseconds \n",current_timestamp_in_us() - loop_start_time);
    //long time_of_message_from_e2agent = current_timestamp_in_us();

    if((recv_len = recv(client_fd, &recv_buffer, sizeof(recv_buffer), 0)) == -1) {
        perror("recv");
        return;
    }

    long time_of_message_from_e2agent = current_timestamp_in_us();

    printf(" 2Time to receive asn message after starting main loop: %ld microseconds \n",current_timestamp_in_us() - loop_start_time);
    if(recv_len == 0) {
        rmr_close_wrapper(rmr_c);

        printf("Connection from closed by remote peer.\n");
        if(close(client_fd) == -1) {
            perror("close");
        }
        return;
    }

    printf(" 3Time to receive asn message after starting main loop: %ld microseconds \n",current_timestamp_in_us() - loop_start_time);
    // begin = clock() - begin;
    // rtt = 1000*((double)begin)/CLOCKS_PER_SEC; // in ms
    //printf("E2Term-Adruino-E2Term = %f ms\n", rtt);

    //2. Decode ASN message and Extract pendulum angle
    char *recv_str;
    recv_str = pendulum_get_strval(recv_buffer, recv_len);
    // if( (strcmp(recv_str, "-1") == 0) || (strcmp(recv_str, "") == 0) )

    if(strcmp(recv_str, "\n") == 0)
    {
      printf("RECEIVED EOL\n");
    }

    printf(" 4Time to receive asn message after starting main loop: %ld microseconds \n",current_timestamp_in_us() - loop_start_time);
    // if(atof(recv_str) <= 0)
    // {
    //   printf("FAILLLLLL\n");
    //   fail_count += 1;
    // }
    // else {
    //   rtt_stats[recv_count] = atof(recv_str);
    //   recv_count++;
    // }

    printf("Time to receive angle message from arduino after starting main loop: %ld microseconds \n",current_timestamp_in_us() - loop_start_time);
    printf("Received message #%d from Adruino: %s\n", count, recv_str);
    //printf("Last reported RTT (Adruino-RIC-Adruino): %f ms, fail_count = %ld\n",
    // atof(recv_str)/1000, fail_count);

    // 3. [BHARATH] send_to_xApp(&pendulum_state, &response)
    // while(1) {
    // usleep( 10 );
    // char* message = "foo 111";
    char reply[1024];
    int got_pend_control=0;
    rmr_send_wrapper(rmr_c, mtype, recv_str );
    printf("Sent message of type:%d to pendulum xApp with content:%s\n",mtype,recv_str);
    long angle_receive_time =0;
    while (got_pend_control == 0){
	    if(rmr_poll_for_message(rmr_c) == 1) {
		    update_msg_rate_metrics();
		    switch(rmr_c->rbuf->mtype) {
			    case 33 :
    		    	            angle_receive_time = current_timestamp_in_us();
				    got_pend_control=1;
				    update_pendulum_control_rate(); //add this
				    strcpy(reply,rmr_c->rbuf->payload);
				    printf("Received control message from pendulum xapp with message type: %d and content %s\n",rmr_c->rbuf->mtype, reply);
				    break;
			    case 102 :
				    printf("Received METRIC request from A1 mediator with message type: %d and content %s\n",rmr_c->rbuf->mtype,rmr_c->rbuf->payload);
				    send_metrics_to_a1_med(rmr_c);
				    break;
			    case 104 :
				    printf("***************************Received load from load generator****************************");
				    forward_to_load_consumer(rmr_c);
				    break;
			    default :
				    continue;
		    }
	    }

    }
    printf("Time to receive control message from xapp after starting main loop: %ld microseconds \n",current_timestamp_in_us() - loop_start_time);
//    snprintf(reply, 1024, "$%d#\n", (int)ave_ric_rtt_last_epoch/1000);
    send_len = pendulum_create_asn_msg(&send_buffer, 0, 0, 0, reply);
    printf("Time to create asn message after receiving angle: %ld microseconds\n",current_timestamp_in_us() - angle_receive_time);
    begin = clock();

    //6. Send ASN1 message to socket
    if(sctp_send_to_socket(client_fd, send_buffer, (size_t)send_len) > 0){
      printf("Sent ASN1 response to E2 Agent\n");
    }
    long time_of_reply_to_e2agent = current_timestamp_in_us();
    printf("Time to send asn message after receiving angle: %ld microseconds \n",current_timestamp_in_us() - angle_receive_time);
    long rtt = (time_of_reply_to_e2agent - time_of_message_from_e2agent);
    ave_ric_rtt_last_epoch = rtt;
    printf("RIC RTT is %lf milliseconds\n", rtt/1000.0);
    //update_rtt_metrics(rtt);
  }

  rmr_close_wrapper(rmr_c);

}

int main(int argc, char* argv[])
{
  // test_rmr(); return 0;

  const char* server_ip   = DEFAULT_SCTP_IP;
  int server_port         = X2AP_SCTP_PORT;

  //read input
  if(argc == 3) //user provided IP and PORT
  {
    server_ip = argv[1];
    server_port = atoi(argv[2]);
    if(server_port < 1 || server_port > 65535) {
      printf("Invalid port number (%d). Valid values are between 1 and 65535.\n", server_port);
      return 1;
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
    printf("Unrecognized option.\n");
    printf("Usage: %s [SERVER IP ADDRESS] [SERVER PORT]\n", argv[0]);
    return 0;
  }

  int client_fd;
  client_fd = sctp_start_client(server_ip, server_port);

  uint8_t *buffer;
  uint32_t  len;

  //Note: put a while(1) loop here if want client to stay
  // for(int i = 0; i < 3; i++)
  // {
    buffer = NULL;
    len = 0;

    printf("------------------------\n");
    clock_t begin;
    begin = clock();

    //Create pdu for x2 message and send to socket
    len = x2ap_generate_x2_setup_request(&buffer);
    if(sctp_send_to_socket(client_fd, buffer, (size_t)len) > 0){
      printf("Sent X2 SETUP REQUEST\n");
    }

    //=======================================================================
    //printf("waiting for server response\n");
    uint8_t recv_buf[MAX_SCTP_BUFFER];
    int recv_len = 0;

    //sctp_recv_from_socket(client_fd, recv_buf, sizeof(recv_buf));
    memset(recv_buf, 0, sizeof(recv_buf));
    recv_len = recv(client_fd, &recv_buf, sizeof(recv_buf), 0);
    if(recv_len == -1)
    {
      perror("recv()");
      return -1;
    }

    //printf("Received a message of size %d\n", recv_len);
    x2ap_eNB_handle_message(recv_buf, recv_len, NULL);

    begin = clock() - begin;
    double time_taken = 1000*((double)begin)/CLOCKS_PER_SEC; // in ms
    printf("Close-loop time: %f ms \n", time_taken);
    printf("X2 Setup Completed \n");

  // } //end iteration

  //=========================================================================
  // Pendulum interaction
  // Receive pendulum state from E2 Agent and send response
  pendulum_control_E2_Termination(client_fd);

  close(client_fd);

  return 0;
}
