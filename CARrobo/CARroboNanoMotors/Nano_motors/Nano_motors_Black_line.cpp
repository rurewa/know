// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Black line movement for Nano motors board
// V 2.1
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

#include <Arduino.h>
int ENA = 10; // PWM
const int MotorRight = 12; // Direction
int ENB = 9; // PWM
const int MotorLeft = 11; // Direction

const int SensorLeft = 8, SensorMiddle= 7, SensorRight = 6; // Датчики отражения

int diy = 100; // чтобы не дёргался на одном месте

void _foward() { // Вперёд
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, HIGH);
}

void _left() { // Влево
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, LOW);
}

void _right() { // Вправо
  digitalWrite(MotorRight, LOW);
  digitalWrite(MotorLeft, HIGH);
}

void _foward_left() { // Вперёд и влево
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, HIGH);
  delay(diy);
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, LOW);
  delay(diy);
}

void _foward_right() { // Вперёд и вправо
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, HIGH);
  delay(diy);
  digitalWrite(MotorRight, LOW);
  digitalWrite(MotorLeft, HIGH);
  delay(diy);
}

void testIR() { // Проверка датчиков отражения
  bool SL = digitalRead(SensorLeft), SM = digitalRead(SensorMiddle), SR = digitalRead(SensorRight);
  Serial.print("Left: "); Serial.print(SL); Serial.print(" Middle: "); Serial.print(SM); Serial.print(" Right: "); Serial.println(SR);
  delay(100);
}

void avtoroute() {  // Поведение
  do {
    bool SL = digitalRead(SensorLeft), SM = digitalRead(SensorMiddle), SR = digitalRead(SensorRight);
    if((!SL) && (SM) && (!SR)) { _foward(); Serial.print("FOWARD: "); } // Если M на чёрном, а L и R на белом - прямо!
    else if((SL) && (!SM) && (!SR)) { _left(); Serial.print("LEFT: "); } // Если M и R на белом - влево!
    else if((!SL) && (SM) && (SR)) { _right(); Serial.print("RIGHT: "); } // Если M и L на белом - вправо!
    else if((SL) && (SM) && (!SR)) { _left(); Serial.print("LEFT: "); } // Если M и L на чёрном - влево!
    else if((!SL) && (SM) && (SR)) { _right(); Serial.print("RIGHT: "); } // Если M и R на чёрном - вправо!
    else if((SL) && (SM) && (SR)) { _foward_left(); Serial.print("FOWARD & LEFT: "); } // Если все на чёрном - вперёд и влево!
    else { _foward_right(); Serial.print("FOWARD & RIGHT: "); } // Если все на белом - вперёд и вправо!
  }
  while(true);
}

void setup() {
  Serial.begin(9600);
  pinMode(MotorRight, OUTPUT);
  pinMode(MotorLeft, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // скорость моторов
  analogWrite(ENA, 135);
  analogWrite(ENB, 135);
}

void loop() {
  avtoroute(); // Поведение
  // testIR(); // Проверка датчиков отражения
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //