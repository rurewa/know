#include <Arduino.h>
// проверка, что библиотека еще не подключена
#ifndef DebButton_h	// если библиотека Button не подключена
#define DebButton_h	// тогда подключаем ее

const int buttonPin = 13;
const int ledPin = 8;

class DebButton // Класс, содержащий переменные состояний кнопки и метод их обработки
{
  public:
    int ledState = LOW;         // Текущее состоние светодиода
    // Переменные состояния светодиода и кнопки
    int buttonState;             // Текущее состояние кнопки
    int lastButtonState = LOW;   // Предыдущее состояние кнопки
    // Переменные таймера и задержки
    unsigned long lastDebounceTime = 0;  // Первоначальное значение таймера
    unsigned long debounceDelay = 50;    // Значение переменной отладки
    void checkState();
};

#endif
