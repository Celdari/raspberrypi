/* 
 * File:   main.c
 * Author: t4suar00
 *
 * Created on 23. syyskuuta 2014, 15:41
 */

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int NUMBER_OF_DEVICES = 2;

int main(void) {
    DIR *dir;
    struct dirent *dirent;
    char dev[NUMBER_OF_DEVICES][16]; // Dev IDs
    char devPath[NUMBER_OF_DEVICES][128]; // Path to device
    char buf[NUMBER_OF_DEVICES][256]; // Data from device
    char tmpData[6]; // Temp C * 1000 reported by device 
    char path[] = "/sys/bus/w1/devices";
    int i, n = 0;
    ssize_t numRead;

    dir = opendir(path);
    if (dir != NULL) {
        //        for(i = 0; (dirent = readdir(dir)); i++)
        while ((dirent = readdir(dir)))
            // 1-wire devices are links beginning with 28-
            if (dirent->d_type == DT_LNK &&
                    strstr(dirent->d_name, "28-") != NULL) {
                strcpy(dev[n], dirent->d_name);
                printf("\nDevice: %s", dev[n]);
                n++;
            }

        (void) closedir(dir);
    } else {
        perror("Couldn't open the w1 devices directory");
        return 1;
    }

    // Assemble path to OneWire device
    for (i = 0; i < n; i++)
        sprintf(devPath[i], "%s/%s/w1_slave", path, dev[i]);
    // Read temp continuously
    // Opening the device's file triggers new reading
    printf("\n");
    while (1) {
        printf("\n");
        for (i = 0; i < n; i++) {
            int fd = open(devPath[i], O_RDONLY);
            if (fd == -1) {
                perror("Couldn't open the w1 device.");
                return 1;
            }
            while ((numRead = read(fd, buf, 256)) > 0) {
                strncpy(tmpData, strstr(buf, "t=") + 2, 5);
                float tempC = strtof(tmpData, NULL);
                printf("Device: %s  - ", dev[i]);
                printf("Temp: %.3f C  ", tempC / 1000);
                printf("%.3f F\n", (tempC / 1000) * 9 / 5 + 32);

                
            }
            close(fd);
        }
    }
    /* return 0; --never called due to loop */
}