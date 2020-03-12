// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Светодиодная волна при помощи алгоритмов
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int ARRAY_SIZE = 5;
const int ARRAY_PINS_LEDS[ARRAY_SIZE] = {8, 9, 10, 11, 12};

void setup() {
  for (int i = 0; i < ARRAY_SIZE; ++i) {
    pinMode(ARRAY_PINS_LEDS[i], OUTPUT);
  }
}

void loop() {
  static int currentLed = 0;
  static int directWave = 1;

  for (int x = 0; x < ARRAY_SIZE; ++x) {
    digitalWrite(ARRAY_PINS_LEDS[x], LOW);
  }
  digitalWrite(ARRAY_PINS_LEDS[currentLed], HIGH);
  currentLed += directWave;
  if (currentLed == ARRAY_SIZE -1) {
    directWave = -directWave;
  }
  if (currentLed == 0) {
    directWave = 1;
  }
  delay(250);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //