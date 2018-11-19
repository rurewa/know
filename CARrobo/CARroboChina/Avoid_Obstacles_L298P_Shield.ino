// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes избегающий препятствия
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

#include <Arduino.h>
#include <NewPing.h>

const unsigned int ECHO_PIN = 14;
const unsigned int TRIG_PIN = 15;

NewPing sonar(TRIG_PIN, ECHO_PIN, 200);

int E1 = 10;     // Motor A1
int M1 =  12;     // Motor A2 (left motor)

int E2 =  11;     // Motor B1
int M2 =  13;     // Motor B2 (right motor)

int SPEED = 185;  // Speed PWM 0 - 255

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
void Backward(int time) {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, SPEED);
  analogWrite(E2, SPEED);
  delay(time);
}

void Forward (int time) {
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, SPEED);
  analogWrite(E2, SPEED);
  delay(time);
}

void turnLeft(int time) {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  analogWrite(E1, SPEED);
  analogWrite(E2, SPEED);
  delay(time);
}

void turnRight(int time) {
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  analogWrite(E1, SPEED);
  analogWrite(E2, SPEED);
  delay(time);
}

void Stop(int time) {
  analogWrite(E1, 0);
  analogWrite(E2, 0);
  delay(time);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

void setup() {
  pinMode(4, OUTPUT); //Buzzer
  //Setup Channel A
  pinMode(12, OUTPUT); //Motor A1
  //Setup Channel B
  pinMode(13, OUTPUT);  //Motor B1
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  int distance = sonar.ping_cm();

  if ((distance > 1) && (distance < 30)) {

    digitalWrite(4, HIGH);
    Stop(500);
    digitalWrite(4, LOW);
    Backward(400);
    turnLeft(400);
  }
  else {

    digitalWrite(4, LOW);
    Forward(10);
  }
  delay(100);
}
