/* 
 * File:   main.c
 * Author: t4suar00
 *
 * Created on 23. syyskuuta 2014, 15:41
 */


#include <stdlib.h>
#include <linux/unistd.h>
#include <wiringPi.h>
#include <unistd.h>

/*
 * 
 */

void lightButton(int button);
void allLights(int mode);

int leds [] = { 0, 0, 0, 0, 0 } ;
int nLeds;

int main(int argc, char** argv) {
    int i;
    int x;
        
    nLeds = sizeof(leds) / sizeof(int);
    
    wiringPiSetup();
//    printf("hoi\n");
    printf("Leds: %i\n", nLeds);
//    Setup the outputs
    for(i = 0; i < nLeds; i++) {
        pinMode(i, OUTPUT);
    }
//    Setup the inputs
//    for(i = 0; i < nLeds; i++) {
//        pinMode(i, INPUT);
//    }
    
    
//Cycle through every led one by one
    for(x = 0; x < 10; x++) {
        for(i = 0; i < nLeds; i++) {
            digitalWrite(i, HIGH);
            delay(20);
        }
        
        for(i = 0; i < nLeds; i++) {
            digitalWrite(i, LOW);
            delay(20);
        }
        delay(50);
    }

    delay(200);

    //Blink all the lights
    for(x = 0; x < 3; x++) {
        allLights(HIGH);
        delay(50);
        allLights(LOW);
        delay(200);
    }
    
    for(;;) {
        lightButton(8);
        delay(20);
    }
    
    return (EXIT_SUCCESS);
}

void lightButton(int button) {
    if(digitalRead(button) == HIGH) return;
    
    allLights(HIGH);
    
    while(digitalRead(button) == LOW) delay(20);
    
    allLights(LOW);
}

void allLights(int mode) {
    int i;
    for(i = 0; i < nLeds; i++) {
            digitalWrite(i, mode);
    }
}