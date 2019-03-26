// Black line movement for Nano motors board
// V 2.0
#include <Arduino.h>
int ENA = 10;
const int MotorRight = 12;
int ENB = 9;
const int MotorLeft = 11;
const int SensorLeft = 8;
const int SensorMiddle= 7;
const int SensorRight = 6;

int diy = 100; // чтобы не дёргался на одном месте

void _foward() {
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, HIGH);
}

void _left() {
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, LOW);
}

void _right() {
  digitalWrite(MotorRight, LOW);
  digitalWrite(MotorLeft, HIGH);
}

void _foward_left() {
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, HIGH);
  delay(diy);
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, LOW);
  delay(diy);
}

void _foward_right() {
  digitalWrite(MotorRight, HIGH);
  digitalWrite(MotorLeft, HIGH);
  delay(diy);
  digitalWrite(MotorRight, LOW);
  digitalWrite(MotorLeft, HIGH);
  delay(diy);
}

void setup()
{
  Serial.begin(9600);
  pinMode(MotorRight, OUTPUT);
  pinMode(MotorLeft, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // скорость моторов
  analogWrite(ENA, 75);
  analogWrite(ENB, 75);
}

void loop()
{
  do {
    bool SL = digitalRead(SensorLeft); // Левый датчик
    bool SM = digitalRead(SensorMiddle); // Средний датчик
    bool SR = digitalRead(SensorRight); // Правый датчик
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