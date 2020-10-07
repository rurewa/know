// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Black line movement for China car, biathlon. Egor D.
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int ENA = 3;
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;
const int SENS_LEFT = 14;
const int SENS_CENTER = 15;
const int SENS_RIGHT = 16;

const int SPEED = 150;

void turnGo(int speed, int times);
void turnBack(int speed, int times);
void turnStop(int times);
void turnLeft(int speed, int times);
void turnRight(int speed, int times);
void sensTest(int times);

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  //sensTest(100); // Для диагностики датчиков отражения
  /*
  turnGo(SPEED, 2000);
  turnStop(2000);
  turnBack(SPEED, 2000);
  turnStop(2000);
  turnLeft(SPEED, 2000);
  turnStop(2000);
  turnRight(SPEED, 2000);
  turnStop(2000);
  */
}

void turnGo(int speed, int times) {
  digitalWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENB, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(times);
}

void turnBack(int speed, int times) {
  digitalWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(times);
}

void turnStop(int times) {
  digitalWrite(ENA, 0);
  digitalWrite(ENB, 0);
  delay(times);
}

void turnLeft(int speed, int times) {
  digitalWrite(ENA, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(times);
}

  void turnRight(int speed, int times) {
    digitalWrite(ENA, speed) ;
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(ENB, speed);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(times);
  }

  void sensTest(int times) {
    bool sLeft = 0; bool sCenter = 0; bool sRight = 0;
    Serial.print("Left: ");
    Serial.print(sLeft = digitalRead(SENS_LEFT));
    Serial.print(" ");
    Serial.print("Center: ");
    Serial.print(sLeft = digitalRead(SENS_CENTER));
    Serial.print(" ");
    Serial.print("Right: ");
    Serial.println(sLeft = digitalRead(SENS_RIGHT));
    delay(times);
  }
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
