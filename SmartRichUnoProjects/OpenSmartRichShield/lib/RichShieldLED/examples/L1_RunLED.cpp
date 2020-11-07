/************************************************* *************************************************
* OPEN-SMART Rich Shield Lesson 1:  Run four LED
* Example v 1.0
************************************************** *******************************************************/
#include <Arduino.h>
#include <Wire.h>
#include "RichShieldLED.h"

const int LED1 = 7;
const int LED2 = 6;
const int LED3 = 5;
const int LED4 = 4;
LED led(LED1, LED2, LED3, LED4);

void setup() { }

void loop() {
  led.on(1);
  led.on(2);
  led.on(3);
  led.on(4);
  delay(1000);
  led.off(1);
  led.off(2);
  led.off(3);
  led.off(4);
  delay(100);
  for(int i = 1; i < 5; i++) {
    led.on(i);//turn on LED i
    delay(500);
    led.off(i);//turn off it.
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //