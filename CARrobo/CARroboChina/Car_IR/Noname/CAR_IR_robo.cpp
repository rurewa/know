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
#define FORWARD 0x511DBB
#define LEFT  0x52A3D41F
#define RIGHT 0x20FE4DBB
#define STOP  0xD7E84B1B
#define BACKWARD  0xA3C8EDDB
#define FORWARDLEFT 0xC101E57B
#define FORWARD2  0x97483BFB
#define FORWARDRIGHT  0xF0C41643
#define LEFT2 0x9716BE3F
#define STOP2 0x3D9AE3F7
#define RIGHT2  0x6182021B
#define BACKWARDLEFT 0x8C22657B
#define BACKWARD2 0x488F3CBB
#define BACKWARDRIGHT 0x449E79F
#define STOP3 0x1BC0157B
#define STOP4 0x32C6FDF7
#define STOP5 0x3EC3FC1B
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
