// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes управляемый Bluetooth
// Пульт Joystik Shield от RoboDyn
// Код передатчика
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

int forward = 3;
int backward = 5;
int left = 6;
int right = 4;

void setup() {
  Serial.begin(38400);
}
void loop() {  
  char state = 0;
  if (digitalRead(forward) == 1) bitSet(state, 0);
  if (digitalRead(backward) == 1) bitSet(state, 1);
  if (digitalRead(left) == 1) bitSet(state, 2);
  if (digitalRead(right) == 1) bitSet(state, 3);
  Serial.write(state);
}
