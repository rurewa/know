// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Egor D. China car. Biathlon, KegelRing Egor D.
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Arduino.h>
#include <NewPing.h>

const int voice = 11;

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
NewPing sonarUp(PIN_TRIG_UP, PIN_ECHO_UP, 100);

const int SPEED_LEFT = 225; // Скорость левого мотора
const int SPEED_RIGHT = 225; // Скорость правого мотора

void turnGo(int speed_left, int speed_right, int times);
void turnBack(int speed_left, int speed_right, int times);
void turnStop(int times);
void turnLeft(int speed_left, int speed_right, int times);
void turnRight(int speed_left, int speed_right, int times);
void turnAngle(int speed_left, int speed_right, int times);
void sensTest(int times);
void voiceMove(); // Алгоритм проверки обнаружения перпятствия со звуковым сигналом

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
  pinMode(voice, OUTPUT);
}

void loop() {
  //sensTest(10);
  bool sLeft = 0; bool sCenter = 0; bool sRight = 0; // Черная 1, белый 0
  sLeft = digitalRead(SENS_LEFT); sCenter = digitalRead(SENS_CENTER); sRight = digitalRead(SENS_RIGHT);

  if (sLeft == 1 && sCenter == 1 && sRight == 1) { // 111
    turnBack(SPEED_LEFT, SPEED_RIGHT, 1300);
    analogWrite(voice, 75); // Включаем сигнал. 0-255 тональность звука
    sensTest(0);
    if (sLeft == 1 && sCenter == 1 && sRight == 1) {
      turnStop(2000);
      turnBack(SPEED_LEFT, SPEED_RIGHT, 250);
    }
  }
  else if (sLeft == 1 && sCenter == 0 && sRight == 0) { // 100. Сделать короткий поворот вправо
    turnBack(SPEED_LEFT, SPEED_RIGHT, 1300);
    analogWrite(voice, 75); // Включаем сигнал. 0-255 тональность звука
    sensTest(0);
    if (sLeft == 1 && sCenter == 0 && sRight == 0) {
      turnStop(2000);
      turnBack(SPEED_LEFT, SPEED_RIGHT, 250);
    }
  }
  else if (sLeft == 0 && sCenter == 1 && sRight == 0) { // 010
    turnBack(SPEED_LEFT, SPEED_RIGHT, 1300);
    analogWrite(voice, 75); // Включаем сигнал. 0-255 тональность звука
    sensTest(0);
    if (sLeft == 0 && sCenter == 1 && sRight == 0) {
      turnStop(2000);
      turnBack(SPEED_LEFT, SPEED_RIGHT, 250);
    }
  }
  else if (sLeft == 0 && sCenter == 0 && sRight == 1) { // 001. Сделать короткий поворот влево
    turnBack(SPEED_LEFT, SPEED_RIGHT, 1300);
    analogWrite(voice, 75); // Включаем сигнал. 0-255 тональность звука
    sensTest(0);
    if (sLeft == 0 && sCenter == 0 && sRight == 1) {
      turnStop(2000);
      turnBack(SPEED_LEFT, SPEED_RIGHT, 250);
    }
  }
  else {
    turnGo(SPEED_LEFT, SPEED_RIGHT, 50); // 000
    analogWrite(voice, 0); // Включаем сигнал. 0-255 тональность звука
    sensTest(0);
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

void voiceMove() {
  // Функция, которая осуществляет цикличный поворот робота влево
  // и, в случае обнаружения спереди препятствия, даёт звуковой сигнал
  int distance = sonarDown.ping_cm();

  if (distance < 25) { // Если дистанция до кегли меньше 30 см.
    //delay(5); // Немного ждём (для стабилизации)
    analogWrite(voice, 75); // Включаем сигнал. 0-255 тональность звука
    //Serial.print(distance); // Выводим в Монитор порта расстояние доп репятствия с нижнего сонара (для диагностики)
    //Serial.println(" TurnGo!"); // Отправляем сообщение в Монитор порта (для диагностики)
    turnStop(350); // Останавливаем движение
    turnLeft(SPEED_LEFT, SPEED_RIGHT, 100); // Поворачиваем влево
  }
  else { // Если расстояние до ближайшей кегли больше 30 сантиметров, то
    delay(5); // Немного ждём (для стабилизации)
    analogWrite(voice, 0); // Выключаем сигнал.
    Serial.print(distance); // Выводим в Монитор порта расстояние доп репятствия с нижнего сонара (для диагностики)
    Serial.println(" TurnLeft!"); // Отправляем сообщение в Монитор порта (для диагностики)
    turnLeft(SPEED_LEFT, SPEED_RIGHT, 5); // Поворачиваем влево
  }
}

/* // Диагностика нижнего сонара
  Serial.print("DOWN: ");
  Serial.println(sonarDown.ping_cm());
  */
  /*// Для диагностики фронтального датчика отражения
  bool irStat = digitalRead(irSens); // Белый-0 Чёрный-1
  Serial.println(irStat);
  */

  /* // Диагностика моторов
  turnGo(SPEED_LEFT, SPEED_RIGHT, 9000);
  turnStop(500);
  turnLeft(SPEED_LEFT, SPEED_RIGHT, 1970);
  turnGo(SPEED_LEFT, SPEED_RIGHT, 9000);
  turnStop(500);
  turnRight(SPEED_LEFT, SPEED_RIGHT, 2000);
  turnStop(500);
  turnBack(SPEED_LEFT, SPEED_RIGHT, 9000);
  turnStop(500);
  */

  //sensTest(100); // Для диагностики датчиков отражения
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
