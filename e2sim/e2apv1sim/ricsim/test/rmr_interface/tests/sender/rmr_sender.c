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


// :vim ts=4 sw=4 noet:

/*
	Mnemonic:	rmr_sender2.c
	Abstract:	Very simple test sender that polls and deals with responses
				in between sends (from a single process).

	Date:		18 February 2018
	Author:		E. Scott Daniels

	Modified:	18 Mar 2019 - changes to support demo
*/

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <time.h>
#include <rmr/rmr.h>
#include "rmr_wrapper.h"


void usage( char* argv0 ) {
	fprintf( stderr, "usage: %s [mtype-max]\n", argv0 );
	fprintf( stderr, "Sender will send messages with rotating msg types from 0 through mtype-max (if supplied)\n" );
	fprintf( stderr, "if not supplied, only mtype 0 is sent\n" );
	fprintf( stderr, "The default listen port for return messages is 43086; this can be changed by setting DUMMY_SENDER_RMR_RCV_PORT  in the environment.\n" );
	fprintf( stderr, "The sender will send forever unless DEMO_SENDER_MAX is set in the environment which causes termination after max messages.\n" );
	fprintf( stderr, "The sender will poll for received messages after each send. The amount of time waited is controlled with DEMO_SENDER_PTO (ms) in the env. Use 0 for non-blocking poll.\n" );
}

int main( int argc, char** argv ) {
	struct rmr_context *rmr_c; //obtain our enhanced rmr_context
	int 	mtype = 0;						// we can loop through several message types
	long	count = 0;
	char*	lport = "43086";				// default listen port
	long	rcount = 0;						// number of acks received

	if( (eparm = getenv( "DUMMY_SENDER_RMR_RCV_PORT" )) != NULL ) {
		lport = strdup( eparm );
	}

     	rmr_c =	rmr_init_wrapper(lport);

	while( ! rmr_ready( rmr_c->mrc ) ) {
		fprintf( stderr, "<TEST> waiting for RMr to indicate ready\n" );
		sleep( 1 );
	}
	fprintf( stderr, "[OK]   initialisation complete\n" );

    	while( 1 ) {
		usleep( 10 );			// simulate some work being done
		char* message = "foo 111";

		if(rmr_send_wrapper (rmr_c, mtype, message ) == 1) {
			//message successfully received in the receive buffer
			char reply[1024];
			strcpy(reply,rmr_c->rbuf->payload);
			fprintf( stderr, "Acknowledgment received with content:%s\n",rmr_c->rbuf->payload);
			rcount++;
		}
		count++;

		if( (count % 5000) == 0 ) {
			fprintf( stdout, "[INFO] total sent: %ld total received: %ld drops=%ld\n", count, rcount, count - rcount );
		}

	}

	fprintf( stderr, "[INFO] sender is terminating having sent %ld messages\n", count );
	rmr_close_wrapper(rmr_c);

	return 0;
}
