#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Arduino_dev_board v 2.0 for kids
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
  // Когда brightness < 255 происходит приращение на 5. Когда brightness >=255
  // происходит выполнение brightness += -fadeAmount
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(50);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //