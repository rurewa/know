// Устранение дребезга кнопки

const int led = 9;  //
const int button = 2; //
boolean lastButton = LOW; // Переменная сохранения предыдущего состояния кнопки
boolean currentButton = LOW;  // Переменная сохранения текущего состояния кнопки
boolean ledOn = false;  // Текущее состояние светодиода (включен/выключен)

void setup()

{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

boolean debounce(boolean last)  //  Функция сглаживания дребезга принимает текущее 
                                //  состояние кнопки и выдаёт фактическое
{
  boolean current = digitalRead(button);  //Считать состояние кнопки
  if (last != current)  // Если тизменилось...
  {
    delay(15);  // Ждём 5 секунд
    current = digitalRead(button);  // Считываем состояние кнопки
    return current; // Возвращаем состояние кнопки
  }
}

void loop()

{
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)  // Если нажатие
  {
    ledOn = !ledOn; // Инвертировать значениессостояния светодиода
  }
  lastButton = currentButton; // Изменить статус
  digitalWrite(led, ledOn); // состояния светодиода
}
