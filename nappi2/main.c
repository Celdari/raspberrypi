

#include "RPI.h"
 
int main()
{
    int value;
  if(map_peripheral(&gpio) == -1) 
  {
    printf("Failed to map the physical GPIO registers into the virtual memory space.\n");
    return -1;
  }
 
  // Define pin 17 as output
  INP_GPIO(2);
  OUT_GPIO(17);
 
  while(1)
  {
    // Toggle pin 17 (blink a led!)
    GPIO_SET = 1 << 17;
    sleep(1);
 
    value = GPIO_READ(2);
    while(!value) {
//        delay(20);
        value = GPIO_READ(2);
    }
    
    GPIO_CLR = 1 << 17;
    sleep(1);
  }
 
  return 0; 
}