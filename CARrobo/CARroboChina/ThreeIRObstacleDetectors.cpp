// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Движение по лабиринту с помощью 3-х IR датчиков препятствия
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

const int E1 = 10;      // Motor A1 PWM
const int M1 =  12;     // Motor A2 (left motor)
const int E2 =  11;     // Motor B1 PWM
const int M2 =  13;     // Motor B2 (right motor)

int SPEED = 185;  // Speed PWM 0 - 255

// Временные константы служат для точного задания времени на поворот, разворот, движение вперед
// в миллисекундах.
/*const int time_90 = 190;
const int time_10 = 20;
const int time_180 = 380;
const int time_10cm = 100;*/

// Номера портов, к которым подключены датчики препятствия.
int  Left = 17, Middle = 18, Right = 19;

void go() { // Вперёд
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
  analogWrite(E2, SPEED);
}

void turnLeft() { // Влево
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
  analogWrite(E2, SPEED);
}

void turnRight() { // Вправо
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
  analogWrite(E2, SPEED);
}

void avtoroute() {  // Поведение
  bool d_Left, d_Middle, d_Right;
  d_Left = digitalRead(Left); d_Middle = digitalRead(Middle); d_Right = digitalRead(Right);
  // Ищем правую сторону.
  // Если ни один датчик не сработал.
  if(d_Left && d_Middle && d_Right) {
    turnRight(); //поворот вправо.
    Serial.print(" Right: ");
    delay(3); //time_10cm/5);
    go(); // едем вперед.
    Serial.print(" Foward: ");
    delayMicroseconds(500);
  }
  else {
    //Если сработал один из передних датчиков.
    if(((!d_Left) || (!d_Middle)) && (d_Right)) {
      // поворачиваем направо на 90 градусов.
      turnRight();
      Serial.print(" Right: ");
      //delay(time_10);
      delayMicroseconds(500);
    }
    else
    //Если сработал один из передних датчиков и правый.
    if(((!d_Left) || (!d_Middle)) && (!d_Right)) {
      // поворачиваем налево на 90 градусов.
      turnLeft();
      Serial.print("Left: ");
      //delay(time_10);
      delayMicroseconds(500);
    }
    else { // Отклоняемся от правой стороны
      // Если сработал правый датчик.
      turnLeft(); //подворот влево.
      Serial.print("Left: ");
      delay(3); //time_90/5);
      go(); // едем вперед.
      Serial.print(" Foward: ");
      delayMicroseconds(500);
    }
  }
// Регулировка скорости робота.
//  delayMicroseconds(100);

}

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}
// Основная программа.
void loop() {
  avtoroute();
  // Код проверки датчиков
  /*bool d_Left, d_Middle, d_Right;
  d_Left = digitalRead(Left); d_Middle = digitalRead(Middle); d_Right = digitalRead(Right);
  Serial.print("Left: ");
  Serial.print(d_Left);
  Serial.print(" Middle: ");
  Serial.print(d_Middle);
  Serial.print(" Right: ");
  Serial.println(d_Right);
  delay(50);*/
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //