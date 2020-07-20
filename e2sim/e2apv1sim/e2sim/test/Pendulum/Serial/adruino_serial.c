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

#include "stdio.h"
#include <string.h>
#include <unistd.h>

#include "adruino_serial.h"

int start_serial_inferface(int baudrate, char *serial_port)
{
  int fd = -1;

  fd = serialport_init(serial_port, baudrate);
  if(fd == -1) {
    fprintf(stderr, "couldn't open serial port %s\n", serial_port);
    return -1;
  } else {
    fprintf(stderr, "Openning serial port: %s ...\n", serial_port);
  }

  serialport_flush(fd); // take 2 seconds
  fprintf(stderr, "Serial port ready!\n");

  return fd;

}

int serial_readline(int fd, char* buf, int buf_max)
{
  if( fd == -1 ){
    perror("serial port not opened");
    return -1;
  }

  memset(buf, 0, buf_max);

  do {
     serialport_read_until(fd, buf, SERIAL_EOL_CHAR, buf_max, SERIAL_TIMEOUT);
  } while( buf[0] == '\n' );

  // serialport_read_until(fd, buf, SERIAL_EOL_CHAR, buf_max, SERIAL_TIMEOUT);

  return 0;
}

int serial_writeline(int fd, char* buf)
{
  if(buf[strlen(buf)-1] != SERIAL_EOL_CHAR){
    //append EOL to buf
    int len = strlen(buf);
    buf[len] = SERIAL_EOL_CHAR;
    buf[len+1] = '\0';
  }

  serialport_write(fd, buf);

  return 0;
}

//For testing only
void test_adruino_serial(void)
{
  int   fd;
  char  buf[MAX_SERIAL_BUFFER];

  fd = start_serial_inferface(DEFAULT_BAUDRATE, DEFAULT_SERIAL_PORT);

  while(1){
    fprintf(stderr, "[E2 Agent]: ");
    fgets(buf, MAX_SERIAL_BUFFER, stdin);

    // serialport_write(fd, "hello\n");
    //serialport_write(fd, buf);
    serial_writeline(fd, buf);

    serial_readline(fd, buf, MAX_SERIAL_BUFFER);
    fprintf(stderr, "[Adruino] %s", buf);
  }

  return;
}
