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
  static int brightness = 0; // Начальная яркость
  static int fadeAmount = 5; // Шаг изменения ШИМ
  analogWrite(led, brightness); // Управление светодиодом
  brightness += fadeAmount; // Циклично +5 или -5
  // Когда brightness <= 255, происходит приращение на 5. Когда brightness >=255
  // происходит выполнение brightness += -fadeAmount (-5)
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // -5
  }
  delay(50);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //