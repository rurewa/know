#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop() {
  static int up = 0;
  static int down = 5;
  static unsigned long oneTime = millis();
  if(millis() >= oneTime) {
    analogWrite(9, up);
    up += down;
    if(up <= 0 || up >= 255) {
      down = -down;
    }
    oneTime = millis() + 200;
    Serial.println(up);
  }
}