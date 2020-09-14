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

#ifndef ADRUINO_SERIAL_H
#define ADRUINO_SERIAL_H

#include "arduino-serial-lib.h"

#define MAX_SERIAL_BUFFER       256
#define DEFAULT_SERIAL_PORT     "/dev/ttyACM0"
#define DEFAULT_BAUDRATE        115200
#define SERIAL_EOL_CHAR         '\n'
#define SERIAL_TIMEOUT          5000 //ms

int start_serial_inferface(int baudrate, char *serial_port);

int serial_readline(int fd, char* buf, int buf_max);

int serial_writeline(int fd, char* buf);

//For testing only
void test_adruino_serial(void);

#endif
