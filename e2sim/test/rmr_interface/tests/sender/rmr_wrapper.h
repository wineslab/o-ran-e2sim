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

int epoll_to = 1;// global default epoll timout -- 1ms
char*	eparm;							// generic env pointer

struct rmr_context {
        void* mrc;
    	int rcv_fd;     // pollable fd
    	struct epoll_event epe;                 // event definition for event to listen to
    	struct epoll_event events[10];          // wait on 10 possible events
    	int     ep_fd;
	int max_payload_size;			// ++SCOTT
	rmr_mbuf_t*		sbuf;					// send buffer
	rmr_mbuf_t*		rbuf;					// received buffer
};


struct rmr_context * rmr_init_wrapper(char* lport){

    	struct rmr_context *rmr_c = malloc(sizeof (struct rmr_context));
	fprintf( stderr, "[INFO] glistening for replies on %s\n", lport );


    	rmr_c->mrc = rmr_init(lport, RMR_MAX_RCV_BYTES, RMRFL_NONE );			// setup RMr and get a context (rmr_c.mrc)
    	rmr_c->ep_fd=-1;

	//polling related initializations
	rmr_c->rcv_fd = rmr_get_rcvfd( rmr_c->mrc );// get the fd to poll for messages received
	if( rmr_c->rcv_fd < 0 ) {
		fprintf( stderr, "[FAIL] unable to set up polling fd\n" );
		exit( 1 );
	}

	if( (rmr_c->ep_fd = epoll_create1( 0 )) < 0 ) {
		fprintf( stderr, "[FAIL] unable to create epoll fd: %d\n", errno );
		exit( 1 );
	}
        rmr_c->epe.events = EPOLLIN;
    	rmr_c->epe.data.fd = rmr_c->rcv_fd;

	if( epoll_ctl( rmr_c->ep_fd, EPOLL_CTL_ADD, rmr_c->rcv_fd, &rmr_c->epe ) != 0 )  {
		fprintf( stderr, "[FAIL] epoll_ctl status not 0 : %s\n", strerror( errno ) );
		exit( 1 );
	}
	//end of polling related initializations

	//++SCOTT------ next lines until !!SCOTT
	rmr_c->max_payload_size = 240; 										//default
	if( (eparm = getenv( "DEMO_MAX_PAYLOAD_BYTES" )) != NULL ) {
		rmr_c->max_payload_size = atoi(eparm); 						// override with env
	}
	//!!SCOTT

	//~~SCOTT next line
	rmr_c->sbuf = rmr_alloc_msg( rmr_c->mrc, rmr_c->max_payload_size );		// allocate largest payload to send
	rmr_c->rbuf = NULL;

 	return rmr_c;
}

void rmr_send_wrapper (struct rmr_context *rmr_c, int mtype, char* message) {
	//--SCOTT int max_payload_size = 240; //default
	//--SCOTT if( (eparm = getenv( "DEMO_MAX_PAYLOAD_BYTES" )) != NULL ) {
		//--SCOTT max_payload_size = atoi(eparm);
	//--SCOTT }

	//~~SCOTT  next line
	snprintf( rmr_c->sbuf->payload, rmr_c->max_payload_size, "%s", message);			// simple send message -- replace with real content

	rmr_c->sbuf->mtype = mtype;										// fill in message meta data
	rmr_c->sbuf->len =  strlen( rmr_c->sbuf->payload ) + 1;					// actual length of payload (count the nil end of string)
	rmr_c->sbuf->state = 0;

	//retry send for a few times before giving up
	long	natter = 0;						// natter on for errors only once in a while
	if( (rmr_c->sbuf = rmr_send_msg( rmr_c->mrc, rmr_c->sbuf )) != NULL ) {// unlikely, but might get a null pointer back if NNG really is buggered
		if( rmr_c->sbuf->state != RMR_OK ) {
			if( errno == EAGAIN ) {
				while( rmr_c->sbuf->state != RMR_OK && errno == EAGAIN ) {// NNG likes to refuse sends, just keep trying on eagain
					rmr_send_msg( rmr_c->mrc, rmr_c->sbuf );
				}
			} else {// most likely connection refused, don't natter on
				if( time( NULL ) > natter ) {
					fprintf( stderr, "[WARN] send failed, pausing (%s)\n", strerror( errno ) );
					natter = time( NULL ) + 2;
				}
				sleep( 1 );
			}
		}
	} else {
		if( time( NULL ) > natter ) {
			fprintf( stderr, "[WARN] send failed, pausing (%s)\n", strerror( errno ) );
			natter = time( NULL ) + 2;
		}
		sleep( 1 );
	}

}

int rmr_poll_for_message(struct rmr_context *rmr_c){	
	int 	nready;
	int 	i;
	int return_type =0;
	//start polling the channel to read the acknowledgment
	//~~SCOTT  next line
	
	nready = epoll_wait( rmr_c->ep_fd, rmr_c->events, 10, epoll_to );	// wait up to epoll_to ms for a response
	for( i = 0; i < nready && i < 10; i++ ) {           // loop through to find what is ready
		if( rmr_c->events[i].data.fd == rmr_c->rcv_fd ) {             // RMr has something
			errno = 0;
			rmr_c->rbuf = rmr_rcv_msg( rmr_c->mrc, rmr_c->rbuf );			// something ready; this should not block
			if( rmr_c->rbuf ) {
	//			fprintf( stderr, "<TEST> acknowledgment received:%s\n",rmr_c->rbuf->payload);
				return_type = 1; //the message has been acknowledged
			}
		}
	}
	return return_type;
}

void rmr_close_wrapper (struct rmr_context *rmr_c){

	rmr_close( rmr_c->mrc );
	free(rmr_c);
}
