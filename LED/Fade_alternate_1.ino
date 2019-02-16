#include <Arduino.h>

const int led = 6;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  static int brightness = 0;
  static int fadeAmount = 5;
  analogWrite(led, brightness);
  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(50);
}
