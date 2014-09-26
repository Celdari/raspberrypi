/* 
 * File:   main.c
 * Author: t4suar00
 *
 * Created on 23. syyskuuta 2014, 15:41
 */


#include <stdlib.h>
#include <wiringPiI2C.h>
//#include <stdio.h>

#define dID 0X70
/*
 * 
 */

void writeI2C(int value);
int rangeI2C();

int fd;

int main(int argc, char** argv) {
    int value;
    
    if((fd = wiringPiI2CSetup(dID)) < 0)
            return 1;
    
    while(1) {
        writeI2C(0x51);
        delay(700);
        value = rangeI2C();
        printf("Value: %i\n", value);
    }
    return (EXIT_SUCCESS);
}

void writeI2C(int value) {
    wiringPiI2CWriteReg8 (fd, 0, value);
}

int rangeI2C() {
    int range[3];
    
    range[0] = wiringPiI2CReadReg8(fd, 2);
    range[1] = wiringPiI2CReadReg8(fd, 3);
    range[2] = (range[0] << 8) + range[1];
    
    return range[2];
}

