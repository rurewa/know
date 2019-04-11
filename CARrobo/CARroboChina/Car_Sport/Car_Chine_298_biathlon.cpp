// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P драйвера для биатлона
// V 2.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
const int ENA = 3;
const int in1 = 5;
const int in2 = 6;
const int ENB = 9;
const int in3 = 7;
const int in4 = 8;

const int SensorLeft = 14;
const int SensorMiddle= 15;
const int SensorRight = 16;

int turn = 105; // скорость для поворота
int motion = 75; // скорость движения прямо и назад

void _go() { // Прямо
  analogWrite(ENA, motion);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ENB, motion);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void _left() { // Влево
  analogWrite(ENA, turn);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ENB, turn);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void _right() { // Вправо
  analogWrite(ENA, turn);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ENB, turn);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void _back() { // Назад
  analogWrite(ENA, motion);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ENB, motion);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void _goTime(int time) { // Прямо
  analogWrite(ENA, motion);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ENB, motion);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(time);
}

void _backTime(int time) { // Назад
  analogWrite(ENA, motion);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ENB, motion);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(time);
}

void _leftTime(int time) { // Влево
  analogWrite(ENA, turn);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(ENB, turn);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(time);
}

void _rightTime(int time) { // Вправо
  analogWrite(ENA, turn);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(ENB, turn);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(time);
}

void _testMotion() { // Тест моторов
  _goTime(2000);
  _backTime(2000);
  _leftTime(2000);
  _rightTime(2000);
}

void _testIR() { // Тест датчиков отражения
  bool SL = digitalRead(SensorLeft), SM = digitalRead(SensorMiddle), SR = digitalRead(SensorRight);
  Serial.print("Left: "); Serial.print(SL); Serial.print(" Middle: "); Serial.print(SM);
  Serial.print(" Right: "); Serial.println(SR);
  delay(100);
}

void autoroute() { // Поведение
  do {
    bool SLeft = !digitalRead(SensorLeft); // Левый датчик
    bool SMiddle = !digitalRead(SensorMiddle); // Средний датчик
    bool SRight = !digitalRead(SensorRight); // Правый датчик

    if((SLeft) && (!SMiddle) && (SRight)) { _go(); Serial.println("FORWARD: "); } // 010
    else if((!SLeft) && (SMiddle) && (SRight)) { _left(); Serial.println("LEFT: "); } // 100
    else if((SLeft) && (SMiddle) && (!SRight)) { _right(); Serial.println("RIGHT: "); } // 001
    else if((!SLeft) && (!SMiddle) && (SRight)) { _left(); Serial.println("LEFT: "); } // 110
    else if((SLeft) && (!SMiddle) && (!SRight)) { _right(); Serial.println("RIGHT: "); } // 011
    else if((!SLeft) && (SMiddle) && (!SRight)) { _left(); Serial.println("LEFT: "); } // 101
    else if((!SLeft) && (!SMiddle) && (!SRight)) { _leftTime(150); _goTime(150); Serial.println("FORWARD & LEFT: "); } // 111
    else { _rightTime(150); _goTime(150); Serial.println("FORWARD: "); } // 000
  }
  while(true);
}


void setup()
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  //_testMotion(); // Тест моторов
  //_testIR(); // Тест датчиков отражения
  autoroute(); // Поведение
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //