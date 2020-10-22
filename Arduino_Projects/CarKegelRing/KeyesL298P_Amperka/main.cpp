// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Амперка.
// D2, D3, D5, D6, D7, D9 - условно-свободны. Имеют одельные разъёмы на шилде
// D8 - не используется.
// Motor shield использует четыре контакта 10, 11, 12, 13 для управления моторами
// D4 - зумер, D9 - Servo
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
// Left motor
const int SPEED_1 = 10;
const int DIR_1 = 12;
// Right motor
const int SPEED_2 = 11;
const int DIR_2 = 13;
// SPEED PWM motors
const int SPEED_LEFT = 40;
const int SPEED_RIGHT = 40;

void go(int SPEED_LEFT, int SPEED_RIGHT);
void back(int SPEED_LEFT, int SPEED_RIGHT);
void left(int SPEED_LEFT, int SPEED_RIGHT);
void right(int SPEED_LEFT, int SPEED_RIGHT);
void stops(int TIMES);

void sensTest(int times); // Тест сенсоров черной линии

void setup() {
  pinMode(SPEED_1, OUTPUT);
  pinMode(DIR_1, OUTPUT);
  pinMode(SPEED_2, OUTPUT);
  pinMode(DIR_2, OUTPUT);
}

void loop() {
  go(SPEED_LEFT, SPEED_RIGHT);
  delay(1000);
  stops(1000);
  back(SPEED_LEFT, SPEED_RIGHT);
  delay(1000);
  stops(1000);
  left(SPEED_LEFT, SPEED_RIGHT);
  delay(1000);
  stops(1000);
  right(SPEED_LEFT, SPEED_RIGHT);
  delay(1000);
  stops(1000);
}

void go(int SPEED_LEFT, int SPEED_RIGHT) {
  digitalWrite(DIR_1, HIGH);
  analogWrite(SPEED_1, SPEED_LEFT);
  digitalWrite(DIR_2, HIGH);
  analogWrite(SPEED_2, SPEED_RIGHT);
}

void back(int SPEED_LEFT, int SPEED_RIGHT) {
  digitalWrite(DIR_1, LOW);
  analogWrite(SPEED_1, SPEED_LEFT);
  digitalWrite(DIR_2, LOW);
  analogWrite(SPEED_2, SPEED_RIGHT);
}

void stops(int TIMES) {
  analogWrite(SPEED_1, 0);
  analogWrite(SPEED_2, 0);
  delay(TIMES);
}

void left(int SPEED_LEFT, int SPEED_RIGHT) {
  digitalWrite(DIR_1, LOW);
  analogWrite(SPEED_1, SPEED_LEFT);
  digitalWrite(DIR_2, HIGH);
  analogWrite(SPEED_2, SPEED_RIGHT);
}

void right(int SPEED_LEFT, int SPEED_RIGHT) {
  digitalWrite(DIR_1, HIGH);
  analogWrite(SPEED_1, SPEED_LEFT);
  digitalWrite(DIR_2, LOW);
  analogWrite(SPEED_2, SPEED_RIGHT);
}

/*void sensTest(int times) {
  bool sensLeft = digitalRead(PIN_SENS_L);
  bool sensRight = digitalRead(PIN_SENS_R);
  bool sensMiddle = digitalRead(PIN_SENS_M);
  Serial.print(sensLeft);
  Serial.print(" ");
  Serial.print(sensMiddle);
  Serial.print(" ");
  Serial.println(sensRight);
  delay(times);
}*/
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //