// Buttons leds rattling sticking 1
// V 1.0
int switchPin = 7;
int ledPin = 9;
boolean lastButton = LOW; // Предыдущее состояние кнопки
boolean currentButton = LOW; // Текущее сосстояние кнопки
boolean ledOn = false; // Текущее состояние светодиода(вкл/выкл)

void setup()
{
  pinMode(ledPin, OUTPUT);
}
/*
* Функция сглаживания дребезка кнопки
* принимает в качестве аргумента предыдущее 
* состояние кнопки и выдаёт фактическое
*/
boolean debounce(boolean last)
{
  // Считтать состояние кнопки
  boolean current = digitalRead(switchPin); 
  if (last != current) // Если изменилось
  {
    delay(5); // Ждём 5 мс.
    current = digitalRead(switchPin); // Считываем состояние кнопки
  }
  return current; // Возвращаем состояние кнопки
}

void loop()
{
  // Считываем предыдущее состоние из функции
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledOn = !ledOn; // Инвертируем значение состояния светодиода
  }
  lastButton = currentButton;  
  digitalWrite(ledPin, ledOn); // Меняем статус состояния светодиода
}
