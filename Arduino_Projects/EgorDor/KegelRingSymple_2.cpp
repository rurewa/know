// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Egor D. China car. Biathlon, KegelRing Egor D. New version.
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
NewPing sonarDown(PIN_TRIG_DOWN, PIN_ECHO_DOWN, 100);
NewPing sonarUp(PIN_TRIG_UP, PIN_ECHO_UP, 100);
// Настройка скорости моторов при поворотах
// Из-за разницы в скорости моторов приходится это компенсировать с помощью ШИМ
const int SPEED_LEFT_TURN = 200; // Скорость левого мотора
const int SPEED_RIGHT_TURN = 175; // Скорость правого мотор
// Настройка скорости моторов при движении вперёд
const int SPEED_RIGHT_MOVE = 142; // Скорость левого мотора
const int SPEED_LEFT_MOVE = 150; // Скорость правого мотора
// Настройка скорости моторов при движении назад
const int SPEED_LEFT_BACK_MOVE = 150; // Скорость правого мотор
const int SPEED_RIGHT_BACK_NOVE = 140; // Скорость правого мотора
// Функции движения
void go(int speed_left_move, int speed_right_move); // Движение вперёд
void backMove(int speed_left_move, int speed_right_move, int times); // Движение назад
void moveStop(int times); // Стоп
void turnLeft(int speed_left_turn, int speed_right_turn); // Движение влево
void turnRight(int speed_left_turn, int speed_right_turn); // Движение Вправо
void sensTest(int times); // Тест нижних датчиков отражения

const int IR_SENS = 4; // Датчик определения цвета кегли. Пока не используется

//bool flagState = false; // Флаг состояния

long long timering = 0;

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
  int distance = sonarDown.ping_cm(); // Запись данных из сонара
  Serial.println(distance); // Диагностика сонара
  static bool sLeft = 0, sCenter = 0, sRight = 0; // Нижние датчики отражения. Черная 1 (не светит), белый 0 (светит)
  // Запись в датчики отражения
  sLeft = digitalRead(SENS_LEFT); sCenter = digitalRead(SENS_CENTER); sRight = digitalRead(SENS_RIGHT);
  if (distance >= 1 && distance <= 65) { // Первая проверка расстояния до кегли
    moveStop(300);
    if (distance >= 1 && distance <= 65) { // Дополнительная проверка расстояния до кегли
      timering = millis(); // Записываем время движения вперёд
      go(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE); // Двигаемся к кегле с целью её вытолкнуть за круг
      // Черный 1, белый 0
      while ((sLeft == true) && (sCenter == true) && (sRight == true)) { // Если наехал на черную линию
        moveStop(300);
        analogWrite(VOICE, 200); // Сигнал для диагностики
        long long backTimering = millis() + timering; // Время для движения назад
        backMove(SPEED_LEFT_BACK_MOVE, SPEED_RIGHT_BACK_NOVE, backTimering); // Движемся назад
        break;
      }
    }
  }
  else {
    turnLeft(SPEED_LEFT_TURN, SPEED_RIGHT_TURN); // Вращаемся на месте влево для поиска кегли
    analogWrite(VOICE, 0); // Сигнал для диагностики
  }
  //Serial.println(distance); // Диагностика сонара
}

void go(int speed_left_move, int speed_right_move) {
  analogWrite(ENA, speed_left_move);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed_right_move);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
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

void turnLeft(int speed_left_turn, int speed_right_turn) {
  analogWrite(ENA, speed_left_turn);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, speed_right_turn);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight(int speed_left_turn, int speed_right_turn) {
  analogWrite(ENA, speed_left_turn) ;
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, speed_right_turn);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
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
