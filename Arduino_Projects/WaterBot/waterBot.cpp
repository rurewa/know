// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Автоналивалка
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

bool inIR = 0;

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);
  //Serial.begin(9600);
}

void loop() {
  inIR = digitalRead(3);
  //Serial.println(inIR);
  if (inIR == 0) {
    digitalWrite(11, HIGH);
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(11, LOW);
    digitalWrite(2, LOW);
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //