// Подключение библиотеки IRremote.h.
//#include <IRremote.h> // Подключаем глобально библиотеку из Arduino IDE.
#include "IRremote.h" // Подключаем локально библиотеку из текущего каталога
#include "motor.h" //Функции управления моторами.
// Порт для IR-приемника.
int RECV_PIN = 7;
// Создание IR-приемника.
IRrecv irrecv(RECV_PIN);
//Переменная для хранения кодов кнопок, получаемых от IR-приемника.
decode_results results;
// Хранит время последнего нажатия кнопки.
unsigned long _time;
/////////////
// Опишем коды кнопок макроподстановками:
#define FORWARD 0xFF629D
#define LEFT  0xFF22DD
#define RIGHT 0xFFC23D
#define STOP  0xFF02FD
#define BACKWARD  0xFFA857
#define FORWARDLEFT 0xFF6897
#define FORWARD2  0xFF9867
#define FORWARDRIGHT  0xFFB04F
#define LEFT2 0xFF30CF
#define STOP2 0xFF18E7
#define RIGHT2  0xFF7A85
#define BACKWARDLEFT 0xFF10EF
#define BACKWARD2 0xFF38C7
#define BACKWARDRIGHT 0xFF5AA5
#define STOP3 0xFF4AB5
#define STOP4 0xFF42BD
#define STOP5 0xFF52AD
//Инициализация.
void setup()
{
  // Переменные – номера контактов (пинов) Arduino.
  // Для левых и правых моторов машинки.
  setup_motor_system(2, 3, 4, 5);
  _stop(); //Двигатели остановлены.
  // Запуск IR-приемника.
  irrecv.enableIRIn();
  _time = millis();
 }
// Основная программа.
void loop()
{
  if (irrecv.decode(&results))
  {
    _time = millis();
    switch (results.value) {
      // Вперед
      case FORWARD:
        forward();
        break;
      // Назад
      case BACKWARD:
        backward();
        break;
      // Влево
      case LEFT:
        left();
        break;
      // Вправо
      case RIGHT:
        right();
        break;
        // Вперед
      case FORWARD2:
        forward();
        break;
      // Назад
      case BACKWARD2:
        backward();
        break;
      // Влево
      case LEFT2:
        left();
        break;
      // Вправо
      case RIGHT2:
        right();
        break;
      // Прямо и влево
      case FORWARDLEFT:
        forward_left();
        break;
      // Прямо и вправо
      case FORWARDRIGHT:
        forward_right();
        break;
      // Назад и влево
      case BACKWARDLEFT:
        backward_left();
        break;
      // Назад и вправо
      case BACKWARDRIGHT:
        backward_right();
        break;
      // Стоп
      case STOP:
        _stop();
       break;
      case STOP2:
        _stop();
       break;
      case STOP3:
        _stop();
       break;
      case STOP4:
        _stop();
       break;
      case STOP5:
        _stop();
       break;
    }
    irrecv.resume();
  }
  //Если никакая клавиша не нажата более 0.3сек., то остановка.
  if((millis()-_time)>300) {_stop();}
}//=====================================================================
