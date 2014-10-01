/* 
 * File:   main.c
 * Author: t4suar00
 *
 * Created on 29. syyskuuta 2014, 14:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <wiringPiSPI.h>
#include <errno.h>
#include <gertboard.h>
#include <stdint.h>


#define SPEED_SPI 1000000
#define CHANNEL 5
#define CHIP_SELECT 1
/*
 * 
 */
int readadc(int adcnum);

int fd;

int main(int argc, char** argv) {    
    int i;
    uint32_t x1, tot;
    
    if (fd = wiringPiSPISetup (CHIP_SELECT, 1000000) < 0) {
        fprintf (stderr, "SPI Setup failed: %s\n", strerror (errno));
        return 1;
    }    
    
    while(1) {
        tot = 0;
        for(i = 0; i < 100; i++) {
            //read data and add to total
            x1 = readadc(CHANNEL);
            tot += x1;
            delay(10);
        }
        
        printf("%i\n", tot / 100);
    }
    
    return (EXIT_SUCCESS);
}

int readadc(int adcnum) {
    uint8_t buff[3];
    int adc;
    if ((adcnum > 7) || (adcnum < 0))
        return -1;
    buff[0] = 1;
    buff[1] = (8 + adcnum) << 4;
    buff[2] = 0;
    wiringPiSPIDataRW(CHIP_SELECT, buff, 3);
    adc = ((buff[1]&3) << 8) + buff[2];
    return adc;
}