#include <Arduino.h>
#include <DebButton.h>

void DebButton::checkState()
{
  digitalWrite(ledPin, ledState); // // Устанавливаем состояние светодиода
  // Считываем состояние кнопки
  int reading = digitalRead(buttonPin);
  // Если текущее состояние кнопки не равно предыдущему
  if (reading != lastButtonState)
  {
    // Сбрасываем таймер
    lastDebounceTime = millis();
  }

  // Если таймер меньше значения отладки
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // Если состояние кнопки изменилось
    if (reading != buttonState)
    {
      buttonState = reading;
      // Если состояние кнопки HIGH
      if (buttonState == HIGH)
      {
        ledState = !ledState; // Инверсия состояния светодиода
      }
    }
  }
  // Устанавливаем состояние светодиода
  digitalWrite(ledPin, ledState);
  // Сохраняем значение
  lastButtonState = reading;
}
