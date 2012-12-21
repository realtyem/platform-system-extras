/*
** Copyright 2011, Chris Trotman (@solarnz)
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** thtt or Too Hot To Touch is used to check the last modified time of a file,
** and then update the last modified time to the current value. If the last
** modified time was less than 240 seconds, then it exits with failure
** otherwise it will exit with a normal exit value.
**
** This is useful in init scripts on android for checking when the last time
** a boot script ran. E.g an overclocking script may be restarting the device
** and you want to detect if the device has already rebooted in the last 4
** minutes.
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <utime.h>
#include <errno.h>


int main (int argc, char *argv[]) {
    if (argc < 2)
        exit(EXIT_FAILURE);
    char *buffer = argv[1];
    FILE *fp;
    struct stat lastRanFile;

    if (stat(buffer, &lastRanFile) == 0){
        if (lastRanFile.st_mtime + 240 < time(NULL)){
            utime(buffer, NULL);
            exit (EXIT_SUCCESS);
        }else {
            utime(buffer, NULL);
            exit (EXIT_FAILURE);
        }
    }else {
        fp = fopen (buffer, "w");
        fclose(fp);
    }
    utime(buffer, NULL);

    exit (EXIT_SUCCESS);
}
