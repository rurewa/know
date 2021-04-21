// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Egor D. China car. Biathlon, KegelRing Egor D. 20 mm/ black line
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <NewPing.h>

const int ENA = 9;
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 3 ;
const int SENS_LEFT   = 14;
const int SENS_CENTER = 15;
const int SENS_RIGHT  = 16;

const int PIN_ECHO = 17;
const int PIN_TRIG = 18;

NewPing sonar(PIN_TRIG,PIN_ECHO);
// Разница в скорости левой и правой стороны ~ 30
const int SPEED_LEFT = 70;
const int SPEED_RIGHT = 100;

void moveGo(int speed_left, int speed_right, int times);
void moveBack(int speed_left, int speed_right, int times);
void moveStop(int times);
void turnLeft(int speed_left, int speed_right, int times);
void turnRight(int speed_left, int speed_right, int times);
void sensTest(int times);
void moveTest();

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
}

void loop() {
  //Serial.println(sonar.ping_cm());
  //moveTest();
  do {
    bool sLeft = digitalRead(SENS_LEFT);
    bool sCenter = digitalRead(SENS_CENTER);
    //bool sRight = digitalRead(SENS_RIGHT); // Дополнительный датчик отражения
    if ((sLeft == false) && (sCenter == true)) { // 01 Вправо!
      turnRight(SPEED_LEFT, SPEED_RIGHT, 180);
      moveGo(SPEED_LEFT, SPEED_RIGHT, 45);
    }
    else if ((sLeft == true) && (sCenter == false)) { // 10 Влево!
      turnLeft(SPEED_LEFT, SPEED_RIGHT, 150);
      moveGo(SPEED_LEFT, SPEED_RIGHT, 60); // 65
    }
    else if ((sLeft == true) && (sCenter == true)) { // 11 Вперёд!
      moveGo(SPEED_LEFT, SPEED_RIGHT, 35);
    }
    else { // 00 Вперёд!
      moveGo(SPEED_LEFT, SPEED_RIGHT, 35);
    }
  }
  while (true);
  //sensTest(100); // Для диагностики датчиков отражения
}

void moveGo(int speed_left, int speed_right, int times) {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed_right);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(times);
}

void moveBack(int speed_left, int speed_right, int times) {
  analogWrite(ENA, speed_left);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed_right);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(times);
}

void moveStop(int times) {
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

void moveTest() {
  moveGo(SPEED_LEFT, SPEED_RIGHT, 4000);
  moveStop(2000);
  moveBack(SPEED_LEFT, SPEED_RIGHT, 4000);
  moveStop(2000);
  turnLeft(SPEED_LEFT, SPEED_RIGHT, 2000);
  moveStop(2000);
  turnRight(SPEED_LEFT, SPEED_RIGHT, 2000);
  moveStop(2000);
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
