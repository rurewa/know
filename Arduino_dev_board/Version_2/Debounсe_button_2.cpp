// Debounсe button 2 for Arduino dev board 2.0
// V 1.0

const int button = 13;
const int led = 8;

boolean buttonState;      // Текущее состояние кнопки
boolean buttonPrevState;  // Предыдущее состояние кнопки
boolean ledState;         // Состояние светодиода

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(button); // Записываем состояние кнопки в переменную buttonState
  if (buttonPrevState == HIGH && buttonState == LOW)
  {
    // Предыдущее состояние кнопки - отжата, а текущее - нажата
    ledState = !ledState;        // Инвертируем состояние светодиода
    digitalWrite(led, ledState); // Управляем светодиодом
  }
  buttonPrevState = buttonState; // Присваиваем предыдущему состоянию кнопки текущее
}
