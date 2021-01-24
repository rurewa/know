// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Egor D. China car. Biathlon, KegelRing Egor D.
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <Arduino.h>
#include <NewPing.h>

const int VOICE = 11;

const int ENA = 9;
const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 7;
const int IN4 = 8;
const int ENB = 3;
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
NewPing sonarUp(PIN_TRIG_UP, PIN_ECHO_UP, 45); // 50 - это максимальная дальность сонара

const int SPEED_LEFT_TURN = 255; // Скорость левого мотора
const int SPEED_RIGHT_TURN = 255; // Скорость правого мотора
// Из-за разницы в скорости моторов, приходится это компенсировать с помощью ШИМ
const int SPEED_RIGHT_MOVE = 125; // Скорость левого мотора
const int SPEED_LEFT_MOVE = 155; // Скорость правого мотора

// Функции движения
void go(int speed_left_move, int speed_right_move, int times); // Движение вперёд
void backMove(int speed_left_move, int speed_right_move, int times); // Движение назад
void turnStop(int times); // Стоп
void turnLeft(int speed_left_turn, int speed_right_turn, int times); // Движение влево
void turnRight(int speed_left_turn, int speed_right_turn, int times); // Движение Вправо
void backMoveFlag(bool flag); // Джвижение назад не обращая внимания на квадрат в центре
void sensTest(int times); // Тест нижних датчиков отражения
void VOICEMove(); // Алгоритм проверки обнаружения перпятствия со звуковым сигналом

const int IR_SENS = 4; // Датчик определения цвета кегли. Пока не используется

static int sensState = 0;

//static bool flag = false; // Флаг для того, чтобы при движении назад он не считал квадрат в центре поля

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
  pinMode(VOICE, OUTPUT);
  delay(250); // Задержка для стабилизации
}

void loop() {
  //sensTest(10);
  int distance = sonarDown.ping_cm(); // Запись данных из сонара
  static bool sLeft = 0; static bool sCenter = 0; static bool sRight = 0; // Черная 1, белый 0
  sLeft = digitalRead(SENS_LEFT); sCenter = digitalRead(SENS_CENTER); sRight = digitalRead(SENS_RIGHT);
  if (sLeft == 1 && sCenter == 1 && sRight == 1) { sensState = 1; } // 111
  if (sLeft == 1 && sCenter == 0 && sRight == 0) { sensState = 2; } // 100
  if (sLeft == 0 && sCenter == 1 && sRight == 0) { sensState = 3; } // 010
  if (sLeft == 0 && sCenter == 0 && sRight == 1) { sensState = 4; } // 001
  if (sLeft == 0 && sCenter == 1 && sRight == 1) { sensState = 5; } // 011
  if (sLeft == 1 && sCenter == 1 && sRight == 0) { sensState = 6; } // 110

  if (distance < 30) {
    go(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE, 1400);
    while (sensState == 1 || sensState == 2 || sensState == 3 || sensState == 4 || sensState == 5 || sensState == 6) {
      backMove(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE, 1400);
      break;
    }
  }
  else {
    turnLeft(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 100);
    turnStop(250);
  }
}

void backMoveFlag(bool flag) {
  flag = true;
  if (flag == true) {
    backMove(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE, 1500);
    turnStop(500);
    go(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 500);
    flag = false;
  }
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

void turnStop(int times) {
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

void voiceMove() { // Функция предназначени для тестирования сонара и моторов одновременно
  bool sLeft = 0; bool sCenter = 0; bool sRight = 0;
  // Функция, которая осуществляет цикличный поворот робота влево
  // и, в случае обнаружения спереди препятствия, даёт звуковой сигнал
  int distance = sonarDown.ping_cm();

  if (distance < 25) { // Если дистанция до кегли меньше 30 см.
    //delay(5); // Немного ждём (для стабилизации)
    analogWrite(VOICE, 75); // Включаем сигнал. 0-255 тональность звука
    //Serial.print(distance); // Выводим в Монитор порта расстояние доп репятствия с нижнего сонара (для диагностики)
    //Serial.println(" TurnGo!"); // Отправляем сообщение в Монитор порта (для диагностики)
    turnStop(350); // Останавливаем движение
    turnLeft(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 100); // Поворачиваем влево
  }
  else { // Если расстояние до ближайшей кегли больше 30 сантиметров, то
    delay(5); // Немного ждём (для стабилизации)
    analogWrite(VOICE, 0); // Выключаем сигнал.
    Serial.print(sLeft == 0 && sCenter == 1 && sRight == 0); // Выводим в Монитор порта расстояние доп репятствия с нижнего сонара (для диагностики)
    Serial.println(" TurnLeft!"); // Отправляем сообщение в Монитор порта (для диагностики)
    turnLeft(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 5); // Поворачиваем влево
  }
}
/*
  void backMove(bool flag) { // backMove(false);
  turnBack(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 1300);
  sensTest(0);
  flag = true;
  if (flag == true) {
    turnStop(500);
    turnBack(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 100);
    turnStop(500);
    turnGo(SPEED_LEFT_TURN, SPEED_RIGHT_TURN, 500);
    flag = false;
  }
}
*/
/* // Новая реализация логики движения робота
int sensStat = 0;
if (sLeft == 1 && sCenter == 1 && sRight == 1) { sensStat = 1; } // 111
if (sLeft == 1 && sCenter == 0 && sRight == 0) { sensStat = 2; } // 100
if (sLeft == 0 && sCenter == 1 && sRight == 0) { sensStat = 3; } // 010
if (sLeft == 0 && sCenter == 0 && sRight == 1) { sensStat = 4; } // 001
if (sLeft == 0 && sCenter == 1 && sRight == 1) { sensStat = 5; } // 011
if (sLeft == 1 && sCenter == 1 && sRight == 0) { sensStat = 6; } // 110
if (sLeft == 0 && sCenter == 0 && sRight == 0) { sensStat = 7; } // 000
switch (sensStat)
{
case 1:
  backMove();
  break;
case 2:
  backMove();
  break;
case 3:
  backMove();
  break;
case 4:
  backMove();
  break;
case 5:
  backMove();
  break;
case 6:
  backMove();
  break;
default:
  turnGo(SPEED_LEFT_MOVE, SPEED_RIGHT_MOVE, 400); // 000
  sensTest(0);
  break;
}
*/


/* // Диагностика нижнего сонара
  Serial.print("DOWN: ");
  Serial.println(sonarDown.ping_cm());
  */
  /*// Для диагностики фронтального датчика отражения
  bool irStat = digitalRead(IR_SENS); // Белый-0 Чёрный-1
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
