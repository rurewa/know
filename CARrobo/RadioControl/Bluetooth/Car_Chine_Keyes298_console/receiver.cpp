// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes управляемый Bluetooth
// и пультом с кнопками
// Код приёмника
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

#include <Arduino.h>

const int E1 = 10;      // Motor A1 PWM
const int M1 =  12;     // Motor A2 (left motor)
const int E2 =  11;     // Motor B1 PWM
const int M2 =  13;     // Motor B2 (right motor)

int SPEED = 135;  // Speed PWM 0 - 255

void go() {
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
  analogWrite(E2, SPEED);
}

void back() {
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
  analogWrite(E2, SPEED);
}

void turnLeft() {
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
  analogWrite(E2, SPEED);
}

void turnRight() {
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
  analogWrite(E2, SPEED);
}

void stop() {
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  Serial.begin(38400);
}

void loop() {
  char state = 0;
  while (Serial.available() > 0) {
    state = Serial.read();
  }
  //0Serial.println(state);
  delay(10);

  if (bitRead(state, 0)) {
    go();
  }
  else if (bitRead(state, 1)) {
    back();
  }
  else if (bitRead(state, 2)) {
    turnLeft();
  }
  else if (bitRead(state, 3)) {
    turnRight();
  }
  else {
    stop();
  }
  state ^= state; // очищаем переменную перед следующим циклом
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //