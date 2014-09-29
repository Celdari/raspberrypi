/* 
 * File:   main.c
 * Author: t4suar00
 *
 * Created on 29. syyskuuta 2014, 13:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <wiringPiSPI.h>
#include <errno.h>

#define SPEED_SPI 1000000
#define CHANNEL 0
/*
 * 
 */
int fd;
unsigned char buff[1];

int main(int argc, char** argv) {    
    if (fd = wiringPiSPISetup (CHANNEL, 1000000) < 0) {
        fprintf (stderr, "SPI Setup failed: %s\n", strerror (errno));
        return 1;
    }    
    
    while(1) {
       fd = wiringPiSPIDataRW(CHANNEL, buff, 1);
       printf("%i\n", *buff);
       delay(1000);
    }
    
    return (EXIT_SUCCESS);
}

