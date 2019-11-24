#include <Arduino.h> // Инициализация специфичной для Ардуино библиотеки
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Отладочный стенд с 3-мя моторами и двумя джойстиками
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <AFMotor.h> // Фирменная библиотека Adafruit Motor Shield

AF_DCMotor Motor1(1); // Объект мотора 1
AF_DCMotor Motor2(2); // Объект мотора 2
AF_DCMotor Motor3(3); // Объект мотора 3

int Joy1ValueX = 0, Joy1ValueY= 0; // Джойстик 1 по X и Y
int Joy2ValueX = 0; // Джойстик 2

int sigSwhow1 = 9; // Сигнализация
int sigSwhow2 = 10; // Сигнализация
int sigSwhow3 = 17; // Сигнализация

void setup() {
  Motor1.run(RELEASE); // Останов мотора 1
  Motor2.run(RELEASE); // Останов мотора 2
  Motor3.run(RELEASE); // Останов мотора 3
  pinMode(10, OUTPUT); // Сигнализация 2
  digitalWrite(10, LOW); // Сигнализация выключена
  //Serial.begin(9600); // Инициализация монитора порта. Нужна для диагностики
}

void loop() {
  Joy1ValueX = map (analogRead(A0), 0, 1023, -255, 255); // Преобразование аналогового сигнала в цифровой
  Joy1ValueY = map (analogRead(A1), 0, 1023, -255, 255);
  Joy2ValueX = map (analogRead(A2), 0, 1023, -255, 255);

  // Управление первым джойстиком по X и Y
  if (Joy1ValueX >= -10 && Joy1ValueX <= 10)  {
      Motor1.run(RELEASE); // Останавливаем мотор
      if (Joy1ValueX >= -10 && Joy1ValueX <= 10) {
        digitalWrite(sigSwhow1, LOW); // Сигнализация выключена
      }
      //Serial.println(Joy1ValueX); // Код для диагностики
  }
  if (Joy1ValueX > 11) {  // Если положение джойстика по X больше 11
      Motor1.run(FORWARD); // Крутим мотор 1
      Motor1.setSpeed(Joy1ValueX); // Со скоростью от 11 до 255 по ШИМ
      if (Joy1ValueX > 11) {
        digitalWrite(sigSwhow1, HIGH); // Сигнализация включена
      }
      //Serial.println(Joy1ValueX);
  }
  if (Joy1ValueX < -11) {  // Если положение джойстика по X меньше 11
      Motor1.run(BACKWARD); // Крутим мотор 1 в обратную сторону
      Motor1.setSpeed(-Joy1ValueX); // Со скоростью от -11 до -255 по ШИМ
      if (Joy1ValueX < -11) {
        digitalWrite(sigSwhow1, HIGH);
      }
      //Serial.println(Joy1ValueX);
  }

  if (Joy1ValueY >= -10 && Joy1ValueY <= 10)  {
      Motor2.run(RELEASE);
      if (Joy1ValueY >= -10 && Joy1ValueY <= 10) {
        digitalWrite(sigSwhow1, LOW);
      }
      //Serial.println(Joy1ValueY);
  }
  if (Joy1ValueY > 11) {
      Motor2.run(FORWARD);
      Motor2.setSpeed(Joy1ValueY);
      if (Joy1ValueY > 13) {
        digitalWrite(sigSwhow1, HIGH);
      }
      //Serial.println(Joy1ValueY);
  }
  if (Joy1ValueY < -11) {
      Motor2.run(BACKWARD);
      Motor2.setSpeed(-Joy1ValueY);
      if (Joy1ValueY <= -13) {
        digitalWrite(sigSwhow1, HIGH);
      }
      //Serial.println(Joy1ValueY);
  }

  // Управление вторым джойстиком по X
  if (Joy2ValueX >= -10 && Joy2ValueX <= 10)  {
      Motor3.run(RELEASE);
      if (Joy2ValueX >= -10 && Joy2ValueX <= 10) {
        digitalWrite(sigSwhow1, LOW);
      }
      //Serial.println(Joy2ValueX);
  }
  if (Joy2ValueX > 11) {
      Motor3.run(FORWARD);
      Motor3.setSpeed(Joy2ValueX);
      if (Joy2ValueX > 13) {
        digitalWrite(sigSwhow1, HIGH);
      }
      //Serial.println(Joy2ValueX);
  }
  if (Joy2ValueX < -11) {
      Motor3.run(BACKWARD);
      Motor3.setSpeed(-Joy2ValueX);
      if (Joy2ValueX < -13) {
        digitalWrite(sigSwhow1, HIGH);
      }
      //Serial.println(Joy2ValueX);
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
