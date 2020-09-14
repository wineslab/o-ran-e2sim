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
	Mnemonic:	rmr_rcvr2.c
	Abstract:	Very simple test listener built on RMr libraries. It does nothing
				but return the message it recevied back to the sender.

				Define these environment variables to have some control:
					RMR_SEED_RT -- path to the static routing table
					RMR_RTG_SVC -- host:port of the route table generator

				One command line parm is accepted: stats frequency.  This is a number, n,
				which causes stats to be generated after every n messages. If set to 0
				each message is written when received and no stats (msg rate) is generated.

	Date:		11 February 2018
	Author:		E. Scott Daniels

	Mods:		18 Mar 2019 -- simplified for demo base.
*/

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <rmr/rmr.h>

typedef struct {
    int32_t mtype;                      // message type  ("long" network integer)
    int32_t plen;                       // payload length
    unsigned char xid[RMR_MAX_XID];     // space for user transaction id or somesuch
    unsigned char sid[RMR_MAX_SID];     // sender ID for return to sender needs
    unsigned char src[RMR_MAX_SRC];     // name of the sender (source)
    struct timespec ts;                 // timestamp ???
} mhdr_t;


int main( int argc, char** argv ) {
    void* mrc;      					// msg router context
    rmr_mbuf_t* msg = NULL;				// message received
	int i;
	char*	listen_port;
	char*	tok;
	int		must_ack = 1;				// flag -- if set we rts all messages
	mhdr_t* hdr;
	int last_seq = 0;					// sequence number from last message
	int this_seq;						// sequence number on this message
	int count = 0;						// count of msg since last status
	long long tcount = 0;				// total count of messages
	time_t ts;
	time_t lts;
	int stat_freq = 20000;				// write stats after reciving this many messages
	int	first_seq = -1;					// first sequence number we got to report total received
	int	max_rt = 1000;					// max times we'll retry an ack

	if( (tok = getenv( "RMR_RCV_ACK" )) != NULL ) {
		must_ack = atoi( tok );
	}

	if( (listen_port = getenv( "PENDULUM_XAPP_RMR_RCV_PORT" )) == NULL ) {
		listen_port = "4560";
	}

	if( argc > 1 ) {
		stat_freq = atoi( argv[1] );
	}
	fprintf( stderr, "<TEST> stats will be reported every %d messages\n", stat_freq );

    mrc = rmr_init( listen_port, RMR_MAX_RCV_BYTES, RMRFL_NONE );	// start your engines!
	if( mrc == NULL ) {
		fprintf( stderr, "<TEST> ABORT:  unable to initialise RMr\n" );
		exit( 1 );
	}

	while( ! rmr_ready( mrc ) ) {
		fprintf( stderr, "<TEST> waiting for RMr to show ready\n" );
		sleep( 1 );
	}
	fprintf( stderr, "<TEST> RMr now shows ready\n" );

	lts = time( NULL );
	fprintf( stderr, "<TEST> listening on %s acking %s\n", listen_port, must_ack != 0 ? "on" : "off"  );

	//rmr_set_stimeout( mrc, 50 );
    while( 1 ) {
		sleep (2 );
		msg = rmr_rcv_msg( mrc, msg );						// block until one arrives
		if( msg == NULL ) {
			continue;				// shouldn't happen, but don't crash if we get nothing
		}
		if( msg->mtype < 0 || msg->state != RMR_OK ) {
			fprintf( stderr, "[WRN] bad msg:  state=%d  errno=%d\n", msg->state, errno );
			continue;			// just loop to receive another
		}

		if( stat_freq == 0 ) {				// mechanism to dump all received messages for quick testing
			fprintf( stdout, "<TEST> msg received: type = %d len = %d (%s)\n", msg->mtype, msg->len, msg->payload );	// assume a nil term string in payload
		}

		count++;		// messages received for stats output
		tcount++;

		//if( stat_freq >= 1000 ) {
    if(1) {
			//if( (count % stat_freq) == 0  ) {
      if(1) {
				ts = time( NULL );
				if( ts - lts ) {

					fprintf( stderr, "<TEST> %7lld received %5lld msg/s over the last %3lld seconds  mrt=%d, with content=%s\n",
							(long long) last_seq - first_seq, (long long) (count / (ts-lts)), (long long) ts-lts, max_rt,msg->payload );
					lts = ts;
					count = 0;
				}
			}
		}

		if( must_ack ) {				// send back a response
			//fprintf( stdout, "<TEST> msg: type = %d len = %d; acking\n", msg->mtype, msg->len );
			//msg->len = snprintf( msg->payload, 1024, "bar %lld", tcount );				// ack with bar and counter
      msg->len = snprintf( msg->payload, 1024, "Reply hello back to Arduino!\n");
      // msg->len = snprintf( msg->payload, 1024, "OK\n");


      //msg->mtype = 999; //only to be used if rts is not possible

			//msg = rmr_send_msg (mrc, msg); //only to be used if rts is not possible

       msg = rmr_rts_msg( mrc, msg ); 								// this is a retur to sender; preferred
			//if( (msg = rmr_send_msg( mrc, msg )) != NULL ) { 			// this is a routed send; not preferred, but possible
			 if( (msg = rmr_rts_msg( mrc, msg )) != NULL ) {
				//----- checking too many times here has been problematic and causes what appears to be race condidtions in NNG threads; for now max_rt should be small
				max_rt = 2;
				while( max_rt > 0 && msg->state != RMR_OK && errno == EAGAIN ) {		// NNG likes to refuse sends, just keep trying on eagain
					max_rt--;
					rmr_rts_msg( mrc, msg );
          //rmr_send_msg (mrc, msg);
				}
			}
		}

    }
}
