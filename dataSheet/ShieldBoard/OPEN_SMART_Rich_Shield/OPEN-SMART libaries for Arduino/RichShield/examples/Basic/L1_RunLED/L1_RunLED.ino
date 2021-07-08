/************************************************* *************************************************
* OPEN-SMART Rich Shield Lesson 1:  Run four LED
* You can learn how to turn on and turn off the LED.
*
* The following functions are available:
*
* led.on(uint8_t num);//num can be 1, 2, 3, 4 that is consistent with the LED number
* led.off(uint8_t num);
*
************************************************** *******************************************************/

#include <Wire.h>
#include "RichShieldLED.h"

#define LED1 7
#define LED2 6
#define LED3 5
#define LED4 4
LED led(LED1,LED2,LED3,LED4);


void setup() {
  
}

void loop() {
 
  for(uint8_t i=1;i < 5; i++)
  {
    led.on(i);//turn on LED i
    delay(500);
    led.off(i);//turn off it.
  }
 
}
