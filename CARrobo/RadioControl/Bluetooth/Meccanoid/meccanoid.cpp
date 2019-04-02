// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes управляемый Bluetooth
// и смартфоном
// Код приёмника
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Wire.h>
#include "MeccaBrain.h" // Библиотека сервопривода

#define STEP 8 // Шаг для сервопривода

MeccaBrain servo(16); // Пин для сервопривода

const int E1 = 10;      // Motor A1 PWM
const int M1 =  12;     // Motor A2 (left motor)
const int E2 =  11;     // Motor B1 PWM
const int M2 =  13;     // Motor B2 (right motor)

int SPEED = 155;  // Speed PWM 0 - 255

void go() { // Вперёд
  digitalWrite(M1, LOW);
  analogWrite(E1, SPEED);
  digitalWrite(M2, LOW);
  analogWrite(E2, SPEED);
}

void back() { // Назад
  digitalWrite(M1, HIGH);
  analogWrite(E1, SPEED);
  digitalWrite(M2, HIGH);
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

void stop() { // Стоп
  analogWrite(E1, 0);
  analogWrite(E2, 0);
}

void EyesOn() { // Глаза включены
  digitalWrite(14, HIGH);
}

void EyesOff() { // Глаза выключены
  digitalWrite(14, LOW);
}

void hornOn() { // Сигнал включён
  digitalWrite(15, HIGH);
}

void hornOff() { // Сигнал выключен
  digitalWrite(15, LOW);
}

void servoMeccanoON()  { // Сервопривод
  servo.communicate();
  servo.setServoColor(0, 0xF4); //
  servo.setServoColor(1, 0xF2); //

  for (int i=0; i<239; i = i+ STEP) {
    servo.communicate();
    servo.setServoPosition(0, i);
    servo.setServoPosition(1, 239 - i);
  }
}

void servoMeccanoOFF()  { // Сервопривод
  servo.communicate();
  servo.setServoColor(1, 0xF4); //
  servo.setServoColor(0, 0xF2); //

  for (int i=239; i>0; i= i-STEP) {
    servo.communicate();
    servo.setServoPosition(0, i);
    servo.setServoPosition(1, 239 - i);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  for (int i=0; i<51; i++) { // Сервопривод
    servo.communicate();
  }
}

void loop() {
  char data = 0;
  if(Serial.available() > 0) {
    data = (char)Serial.read();
    delay(10);
    Serial.print(data);
    Serial.print("\n");
    switch (data)
    {
      case 'F': // Вперёд
        go();
        break;
      case 'B': // Назад
        back();
        break;
      case 'S': // Стоп
        stop();
        break;
      case 'L': // Влево
        turnLeft();
        break;
      case 'R': // Вправо
        turnRight();
        break;
      case 'W': // Глаза включены
        EyesOn();
        break;
      case 'w': // Глаза выключены
        EyesOff();
        break;
      case 'V': // Голос включён
        hornOn();
        break;
      case 'v': // Голос выключен
        hornOff();
        break;
      case 'X':
        servoMeccanoON(); // Руку поднял
        break;
      case 'x':
        servoMeccanoOFF(); // Руку опустил
        break;
      default:
        break;
    }
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //