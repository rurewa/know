// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Egor D. China car. Biathlon, KegelRing Egor D.
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Arduino.h>
#include <NewPing.h>

const int zoomer = 11;

const int ENA = 3;
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 9;
const int SENS_LEFT   = 14;
const int SENS_CENTER = 15;
const int SENS_RIGHT  = 16;
// Нижний сонар
const int PIN_ECHO_DOWN = 12; // 12
const int PIN_TRIG_DOWN = 13; // 13
// Верхний сонар
const int PIN_ECHO_UP = 17; // 17
const int PIN_TRIG_UP = 18;  // 18

NewPing sonarDown(PIN_TRIG_DOWN, PIN_ECHO_DOWN, 400);
NewPing sonarUp(PIN_TRIG_UP, PIN_ECHO_UP, 400);

const int SPEED_LEFT = 185; // Скорость левого мотора
const int SPEED_RIGHT = 185; // Скорость правого мотора

void turnGo(int speed_left, int speed_right, int times);
void turnBack(int speed_left, int speed_right, int times);
void turnStop(int times);
void turnLeft(int speed_left, int speed_right, int times);
void turnRight(int speed_left, int speed_right, int times);
void turnAngle(int speed_left, int speed_right, int times);
void sensTest(int times);

const int irSens = 4; // Датчик определения цвета кегли

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(PIN_TRIG_UP, OUTPUT);
  pinMode(PIN_TRIG_DOWN, OUTPUT);
}
void loop() {
  //Serial.print("DOWN: ");
  //Serial.println(sonarDown.ping_cm()); // Диагностика нижнего сонара
 
  //bool irStat = digitalRead(irSens); // Белый-0 Чёрный-1
  //Serial.println(irStat); // Для диагностика фронтального датчика отражения
  //bool sLeft = digitalRead(SENS_LEFT);
  //bool sCenter = digitalRead(SENS_CENTER);
  //bool sRight = digitalRead(SENS_RIGHT);
  //Serial.print(sLeft); // Белый-0 Чёрный-1
  //Serial.print(sCenter);
  //Serial.println(sRight);
  turnGo(SPEED_LEFT, SPEED_RIGHT, 9000);
  turnStop(500);
  turnLeft(SPEED_LEFT, SPEED_RIGHT, 1970);
  turnGo(SPEED_LEFT, SPEED_RIGHT, 9000);
  turnStop(500);
  turnRight(SPEED_LEFT, SPEED_RIGHT, 2000);
  turnStop(500);
  //turnBack(SPEED_LEFT, SPEED_RIGHT, 9000);
 // turnStop(500);
  //sensTest(100); // Для диагностики датчиков отражения

  if (sonarUp.ping_cm() <= 15) {
    turnLeft(SPEED_LEFT, SPEED_RIGHT, 500);
    turnStop(500);
    analogWrite(zoomer, 200); // 0-255 тональность звука
  }
  else {
    turnLeft(SPEED_LEFT, SPEED_RIGHT, 5);
    analogWrite(zoomer, 0);
  }
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

void turnAngle(int speed_left, int speed_right, int times) {
  analogWrite(ENA, speed_left) ;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed_right);
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
  Serial.print(sCenter = digitalRead(SENS_CENTER));
  Serial.print(" ");
  Serial.print("Right: ");
  Serial.println(sRight = digitalRead(SENS_RIGHT));
  delay(times);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
