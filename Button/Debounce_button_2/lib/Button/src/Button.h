// проверка, что библиотека еще не подключена
#ifndef Button_h	// если библиотека Button не подключена
#define Button_h	// тогда подключаем ее
#include <Arduino.h>

const int switchPin = 13;
const int ledPin = 8;

class Button // Класс, содержащий переменные состояний кнопки и метод их обработки
{
  public: // Модификатор. Доступ открыт всем, кто видит определение данного класса
    boolean lastButton = LOW; // Предыдущее состояние кнопки
    boolean currentButton = LOW; // Текущее сосстояние кнопки
    boolean ledOn = false; // Текущее состояние светодиода(вкл/выкл)
  void checkState(); // Метод проверки состояния кнопки
};
#endif
