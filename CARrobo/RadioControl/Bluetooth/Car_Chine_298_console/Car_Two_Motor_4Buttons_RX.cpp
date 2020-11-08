// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes управляемый Bluetooth
// и кнопками с пульта. Для фишкомёта.
// Код приёмника
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int in1 = 5;
const int in2 = 6;
const int in3 = 7;
const int in4 = 8;

const int en1 = 9;
const int en2 = 10;

int SPEED = 245;  // Speed PWM 0 - 255

void go() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en1, SPEED);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en2, SPEED);
}

void back() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(en1, SPEED);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(en2, SPEED);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(en1, SPEED);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(en2, SPEED);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en1, SPEED);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(en2, SPEED);
}

void stop() {
  analogWrite(en1, 0);
  analogWrite(en2, 0);
}

void setup() {
  Serial.begin(38400);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
}

void loop() {
  char state = 0;  
  while (Serial.available() > 0) {
    state = Serial.read();
  }
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
