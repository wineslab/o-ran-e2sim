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

#include "e2sim_defs.h"
#include <cstring>
#include <getopt.h>
#include <sys/time.h>
#include <time.h>

char *time_stamp() {
    timeval curTime;
    gettimeofday(&curTime, NULL);
    int milli = curTime.tv_usec / 1000;

    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

    const int time_buffer_len = 84;
    static char currentTime[time_buffer_len] = "";
    snprintf(currentTime, time_buffer_len, "%s:%03d", buffer, milli);

    return currentTime;
}

options_t read_input_options_old(int argc, char *argv[]) {
    options_t options;

    options.server_ip = (char *) DEFAULT_SCTP_IP;
    options.server_port = X2AP_SCTP_PORT;

    // Parse command line options
    static struct option long_options[] =
            {
                    {"ipv4",    required_argument, 0, 'i'},
                    {"ipv6",    required_argument, 0, 'I'},
                    {"port",    required_argument, 0, 'p'},
                    {"verbose", no_argument,       0, 'v'},
            };

    while (true) {
        int option_index = 0;

        char c = getopt_long(argc, argv, "i:I:p:", long_options, &option_index);

        if (c == -1)
            break;

        switch (c) {
            case 'i':
                options.server_ip = optarg;
                break;
            case 'I':
                break;
            case 'p':
                options.server_port = atoi(optarg);
                if (options.server_port < 1 || options.server_port > 65535) {
                    LOG_E("Invalid port number (%d). Valid values are between 1 and 65535.\n",
                          options.server_port);
                    exit(EXIT_FAILURE);
                }
                break;

            default:
                LOG_E("Error: unknown input option: %c\n", optopt);
                exit(EXIT_FAILURE);
        }
    }

    return options;
}

void print_parameters(int argc, char *argv[], options_t options) {
    switch (argc) {
        case 6: { // user provided IP, PORT, GNB_ID, CLIENT_PORT and CGI_TYPE
            LOG_I("argc %d, server_ip %s , server_port %s , gnb_id %s , client_port %s , plmn_id %s .",
                  argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
            break;
        }
        case 5: { // user provided IP, PORT, GNB_ID and CLIENT_PORT
            LOG_I("argc %d, server_ip %s , server_port %s , gnb_id %s , client_port %s , plmn_id %s .",
                  argc, argv[1], argv[2], argv[3], argv[4], options.plmn_id);
            break;
        }
        case 4: { // user provided IP, PORT and GNB_ID
            LOG_I("argc %d, server_ip %s , server_port %s , gnb_id %s , client_port %d , plmn_id %s .",
                  argc, argv[1], argv[2], argv[3], options.client_port, options.plmn_id);
            break;
        }
        case 3: { // user provided IP and PORT
            LOG_I("argc %d, server_ip %s , server_port %s , gnb_id %s , client_port %d , plmn_id %s .",
                  argc, argv[1], argv[2], options.gnb_id, options.client_port, options.plmn_id);
            break;
        }
        case 2: { // user provided only IP
            LOG_I("argc %d, server_ip %s , server_port %d , gnb_id %s , client_port %d , plmn_id %s .",
                  argc, argv[1], options.server_port, options.gnb_id, options.client_port, options.plmn_id);
            break;
        }
        case 1: {// default parameters used
            LOG_I("argc %d, server_ip %s , server_port %d , gnb_id %s , client_port %d , plmn_id %s .",
                  argc, options.server_ip, options.server_port, options.gnb_id, options.client_port, options.plmn_id);
            break;
        }

        default: {
            LOG_I("Unrecognized option.\n");
            LOG_I("Usage: %s [SERVER IP ADDRESS] [SERVER PORT] [GNB_ID] [CLIENT_PORT]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }
}

options_t read_input_options(int argc, char *argv[]) {
    char *endChar;
    options_t options;

    options.server_ip = (char *) DEFAULT_SCTP_IP;
    options.server_port = X2AP_SCTP_PORT;
    options.gnb_id = (char *) "1";
    options.client_port = RIC_SCTP_SRC_PORT;
    options.plmn_id = (char *) "111";

    for (int i = 1; i < argc; i++) {
        LOG_D("argv[%d]: %s", i, argv[i]);
    }

    switch (argc) {
        case 6: { // user provided IP, PORT, GNB_ID, CLIENT_PORT and PLMN_ID
            options.plmn_id = strdup(argv[5]);
        }
        case 5: { // user provided IP, PORT, GNB_ID and CLIENT_PORT
            options.client_port = int(std::strtol(argv[4], &endChar, 10));
        }
        case 4: { // user provided IP, PORT and GNB_ID
            options.gnb_id = strdup(argv[3]);
        }
        case 3: { // user provided IP and PORT
            options.server_port = int(std::strtol(argv[2], &endChar, 10));
            if (options.server_port < 1 || options.server_port > 65535) {
                LOG_E("Invalid port number (%d). Valid values are between 1 and 65535.\n",
                      options.server_port);
                exit(EXIT_FAILURE);
            }
        }
        case 2: { // user provided only IP
            options.server_ip = argv[1];
        }
        case 1: {// default parameters used
            break;
        }

        default: {
            LOG_I("Unrecognized option.\n");
            LOG_I("Usage: %s [SERVER IP ADDRESS] [SERVER PORT] [GNB_ID] [CLIENT_PORT] [PLMN_ID]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    print_parameters(argc, argv, options);

    return options;
}
