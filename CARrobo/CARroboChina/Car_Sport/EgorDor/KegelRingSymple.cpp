// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Egor D. China car. Biathlon, KegelRing Egor D.
// Что нужно переделать и доделать:
// Переставить сонар выше, на 1-ю полку и утопить за подлицо.
// Установить экран спереди чтобы робот не наезжал на упавшую кеглю
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <NewPing.h> // Библиотека сонара
// Пин динамика
const int VOICE = 11;
// Пины драйвера мотора
const int ENA = 9;
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 3;
// Пины нижних датчиков отражения
const int SENS_LEFT   = 14;
const int SENS_CENTER = 15;
const int SENS_RIGHT  = 16;
// Нижний сонар
const int PIN_ECHO_DOWN = 12; // 12
const int PIN_TRIG_DOWN = 13; // 13
// Верхний сонар
const int PIN_ECHO_UP = 17; // 17
const int PIN_TRIG_UP = 18;  // 18
// Объекты сонаров. 45 - это максимальная дальность сонара
NewPing sonarDown(PIN_TRIG_DOWN, PIN_ECHO_DOWN, 45);
NewPing sonarUp(PIN_TRIG_UP, PIN_ECHO_UP, 45);
// Настройка скорости моторов при поворотах
const int SPEED_LEFT_TURN = 255; // Скорость левого мотора
const int SPEED_RIGHT_TURN = 255; // Скорость правого мотора
// Из-за разницы в скорости моторов приходится это компенсировать с помощью ШИМ
const int SPEED_RIGHT_MOVE = 125; // Скорость левого мотора
const int SPEED_LEFT_MOVE = 175; // Скорость правого мотора
// Функции движения
void go(int speed_left_move, int speed_right_move, int times); // Движение вперёд
void backMove(int speed_left_move, int speed_right_move, int times); // Движение назад
void moveStop(int times); // Стоп
void turnLeft(int speed_left_turn, int speed_right_turn, int times); // Движение влево
void turnRight(int speed_left_turn, int speed_right_turn, int times); // Движение Вправо
void sensTest(int times); // Тест нижних датчиков отражения

const int IR_SENS = 4; // Датчик определения цвета кегли. Пока не используется

void setup() {
  Serial.begin(9600); // Монтор порта: для диагностики и тестирования
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(PIN_TRIG_UP, OUTPUT); // Настройка trig сонара на ВЫХОД
  pinMode(PIN_TRIG_DOWN, OUTPUT);
  pinMode(VOICE, OUTPUT); // Настройка пина для зумера
  delay(250); // Задержка выполнения всего алгоритма для стабилизации.
}

void loop() {
  //sensTest(10); // Тест нажних датчиков отражения
  int distance = sonarDown.ping_cm(); // Запись данных из сонара
  static int sensState = 0; // Флаг состояния нижних датчиков отражения
  static bool sLeft = 0, sCenter = 0, sRight = 0; // Нижние датчики отражения. Черная 1, белый 0
  // Запись в датчики отражения
  sLeft = digitalRead(SENS_LEFT); sCenter = digitalRead(SENS_CENTER); sRight = digitalRead(SENS_RIGHT);
  // Черная 1, белый 0
  if (sLeft == 1 && sCenter == 1 && sRight == 1) { sensState = 1; } // Состояние 111
  if (sLeft == 1 && sCenter == 0 && sRight == 0) { sensState = 2; } // Состояние 100
  if (sLeft == 0 && sCenter == 1 && sRight == 0) { sensState = 3; } // Состояние 010
  if (sLeft == 0 && sCenter == 0 && sRight == 1) { sensState = 4; } // Состояние 001
  if (sLeft == 0 && sCenter == 1 && sRight == 1) { sensState = 5; } // Состояние 011
  if (sLeft == 1 && sCenter == 1 && sRight == 0) { sensState = 6; } // Состояние 110
  // Проверка расстояния до кегли
  if (distance > 0 && distance < 40) { // Если больше 0 и меньше 40 см.
    delay(250); // Задержка для стабилизации
    if (distance < 40) { // Дополнительная проверка расстояния до кегли
      delay(250);
      go(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE, 2000); // Двигаемся к кегле с целью её вытолкнуть за круг
      //backMove(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE, 2000); // Движемся назад
      // Если сработал хоть один нижний датчик отражения, то возвращаемся в квадрат
      if (sensState == 1 || sensState == 2 || sensState == 3 || sensState == 4 || sensState == 5 || sensState == 6) {
        backMove(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE, 2000); // Движемся назад
        //break; // Выходим из цикла
      }
    }
  }
  else { // Если кегля не обнаружена
    turnLeft(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 50); // Вращаемся на месте влево - ищем кеглю
    moveStop(250); // Задержка для стабилизации
  }
  //Serial.println(distance); // Диагностика сонара
}

void go(int speed_left_move, int speed_right_move, int times) {
  analogWrite(ENA, speed_left_move);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed_right_move);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(times);
}

void backMove(int speed_left_move, int speed_right_move, int times) {
  analogWrite(ENA, speed_left_move);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed_right_move);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(times);
}

void moveStop(int times) {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(times);
}

void turnLeft(int speed_left_turn, int speed_right_turn, int times) {
  analogWrite(ENA, speed_left_turn);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed_right_turn);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(times);
}

void turnRight(int speed_left_turn, int speed_right_turn, int times) {
  analogWrite(ENA, speed_left_turn) ;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed_right_turn);
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
//sensTest(100); // Для диагностики датчиков отражения
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
