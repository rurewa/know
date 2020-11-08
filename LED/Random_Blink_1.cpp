#include <Arduino.h>
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Arduino_dev_board v 2.0
// Random Blink v 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

int leds[5] = {8, 9, 10, 11, 12};

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < 5; i++)
    pinMode(leds[i], OUTPUT);
}

void loop() {
  int RANDOM;
  RANDOM = random(0, 5);

  digitalWrite(leds[RANDOM], !digitalRead(leds[RANDOM]));
  Serial.println(RANDOM);
  delay(100);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //