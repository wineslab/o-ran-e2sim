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
#include "e2sim_defs.h"
#include <unistd.h>

#include "adruino_serial.h"

int main(int argc, char *argv[])
{
  int   fd;
  char  buf[MAX_SERIAL_BUFFER];

  fd = start_serial_inferface(DEFAULT_BAUDRATE, DEFAULT_SERIAL_PORT);

  while(1)
  {
    //usleep(5*1000); //sleep 5ms between read
    sleep(1);

    FILE *f;
    f = fopen("arduino_delay.txt", "r");
    assert(f);

    fread(buf, 1, sizeof(buf), f);

    printf("delay content = %s \n", buf);

    serial_writeline(fd, buf);

    fclose(f);
  }

  return 0;
}
