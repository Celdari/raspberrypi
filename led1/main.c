/* 
 * File:   main.c
 * Author: t4suar00
 *
 * Created on 23. syyskuuta 2014, 15:41
 */


#include <stdlib.h>
#include <wiringPi.h>




/*
 * 
 */
int main(int argc, char** argv) {
    int i = 0;
    
    wiringPiSetup();
    pinMode(0, OUTPUT);
    
    for(i = 0; i < 4; i++) {
        printf("On\n");
        digitalWrite(0, HIGH);
        delay(1000);
        printf("Off\n");
        digitalWrite(0, LOW);
        delay(1000);
    }
    
    
    return (EXIT_SUCCESS);
}

