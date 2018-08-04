#include "Arduino.h"
#include "Button.h"

boolean debounce(boolean lastButton) // Значение функции debounce (true или false) зависит от значения функции lastButton
{
  boolean current = digitalRead(switchPin); // Чтение состояния кнопки
  if (lastButton != current)                // Если найдены отличия
  {
    delay(5);                               // Ждем 5мс
    current = digitalRead(switchPin);       // Читаем снова
  }
  return current;                           // Возвращаем текущее состояние
}

void Button::checkState() // Метод, содержащийся в классе Button
{
    currentButton = debounce(lastButton); // Считываем предыдущее состояние из функции
    // Если предыдущее LOW а текущее HIGH
    if (lastButton == LOW && currentButton == HIGH)
      {
        ledOn = !ledOn; // Инвертируем значение состояния светодиода
      }
    lastButton = currentButton; // Изменяем предыдущее состояние кнопки для повторения цикла
    digitalWrite(ledPin, ledOn); // Меняем статус состояния светодиода
}
