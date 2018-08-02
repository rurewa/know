// Debounсe button for Arduino dev board 2.0
// V 1.0
/*
  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Debounce
*/

const int buttonPin = 13;
const int ledPin = 8;
// Переменные состояния светодиода и кнопки
int ledState = LOW;         // Текущее состоние светодиода
int buttonState;             // Текущее состояние кнопки
int lastButtonState = LOW;   // Предыдущее состояние кнопки
// Переменные таймера и задержки
unsigned long lastDebounceTime = 0;  // Первоначальное значение таймера
unsigned long debounceDelay = 50;    // Значение переменной отладки

void setup()
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop()
{
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
