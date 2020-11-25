// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Max Sech. China car. Biathlon Sport.
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <NewPing.h>

const int PIN_ECHO = 17;
const int PIN_TRIG = 18;

NewPing sonar(PIN_TRIG,PIN_ECHO);

const int ENA = 3;
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;

const int SPEED_LEFT = 100;
const int SPEED_RIGHT = 100;

void turnGo(int speed_left, int speed_right, int times);
void turnBack(int speed_left, int speed_right, int times);
void turnStop(int times);
void turnLeft(int speed_left, int speed_right, int times);
void turnRight(int speed_left, int speed_right, int times);

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  Serial.println(sonar.ping_cm());

  turnGo(SPEED_LEFT, SPEED_RIGHT, 1000);
  turnStop(500);
  turnBack(SPEED_LEFT, SPEED_RIGHT, 1000);
  turnStop(500);
  turnRight(SPEED_LEFT, SPEED_RIGHT, 1000);
  turnStop(500);
  turnLeft(SPEED_LEFT, SPEED_RIGHT, 1000);
  turnStop(500);

}

void turnGo(int speed_left, int speed_right, int times) {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed_right);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(times);
}

void turnBack(int speed_left, int speed_right, int times) {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed_right);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(times);
}

void turnStop(int times) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(times);
}

void turnLeft(int speed_left, int speed_right, int times) {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed_right);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(times);
}

void turnRight(int speed_left, int speed_right, int times) {
  analogWrite(ENA, speed_left) ;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed_right);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(times);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //