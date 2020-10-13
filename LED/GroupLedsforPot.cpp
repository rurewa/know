// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Простая светодиодная волна от потенциометра
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
#include <Arduino.h>

const int PINS_LEDS[5] = {8, 9, 10, 11, 12};

void setup() {
  for (int i = 0; i <= 4; i++) {
    pinMode(PINS_LEDS[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  const int PIN_POT = A7;
  int valPot = analogRead(PIN_POT);
  int countLeds = map (valPot, 0, 1023, 0, 5);

  for (int i = 0; i <= 5; i++) {
    if (i < countLeds) {
      digitalWrite(PINS_LEDS[i], HIGH);
    }
    else {
      digitalWrite(PINS_LEDS[i], LOW);
    }
  }
  Serial.println(countLeds);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
