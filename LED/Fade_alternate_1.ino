#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Arduino_dev_board v 2.0
// Fade an LED v 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
const int led = 9;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  static int brightness = 0; // Яркость светодиода
  static int fadeAmount = 5; // Шаг изменения ШИМ
  analogWrite(led, brightness);
  //  Выполняется прибавление на 5 пока не достигает brightness 255
  brightness += fadeAmount; // Идеинтично brightness = brightness + fadeAmount
  // Когда brightness достигает 255, выполняется вычитание до 0
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(50);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //