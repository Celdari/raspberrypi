/* 
 * File:   main.c
 * Author: t4suar00
 *
 * Created on 23. syyskuuta 2014, 15:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>



/*
 * 
 */
int main(int argc, char** argv) {
    printf("Hello");
    wiringPiSetup();
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);
    return (EXIT_SUCCESS);
}

