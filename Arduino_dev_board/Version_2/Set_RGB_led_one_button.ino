// Set RGB-led for Arduino dev board 2.0
// V 1.0
const int ledR = 11;
const int ledG = 10;
const int ledB = 9;
const int button = 13;
boolean lastButton = LOW; // Предыдущий статус кнопки
boolean currentButton = LOW; // Текущий статус кнопки
int ledMode = 0; // Значение статуса RGB-светодиода

void setup()
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

boolean debounce (boolean last)
{
  boolean current = digitalRead(button); // Считываем состояние кнопки
  if (last != current) // Если изменилось
  {
    delay(5); // Немного ждём
    current = digitalRead(button); // Снова считываем состояние кнопки
  }
  return current; // Возвращаем состояние кнопки
}

void setMode(int mode)
{
  // Красный
  if (mode == 1)
  {
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
  }
  // Зелёный
  else if (mode == 2)
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, HIGH);
    digitalWrite(ledB, LOW);
  }
  //  Синий
  else if (mode == 3)
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH);
  }
  // Пурпупный (Красный + Синий)
  else if (mode == 4)
  {
    digitalWrite(ledR, 127);
    digitalWrite(ledG, 0);
    digitalWrite(ledB, 127);
  }
  // Бирюзовый (Синий + Зелёный)
  else if (mode == 5)
  {
    digitalWrite(ledR, 0);
    digitalWrite(ledG, 127);
    digitalWrite(ledB, 127);
  }
  // Оранжевый (Зелёный + Красный)
  else if (mode == 6)
  {
    digitalWrite(ledR, 127);
    digitalWrite(ledG, 127);
    digitalWrite(ledB, 0);
  }
  // Белый (Зелёный + Красный + Синий)
  else if (mode == 7)
  {
    digitalWrite(ledR, 85);
    digitalWrite(ledG, 85);
    digitalWrite(ledB, 85);
  }
  // Выключен (mode = 0)
  else
  {
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, LOW);
  }
}

void loop()
{
  currentButton = debounce(lastButton); // Чтение состояние кнопки
  if (lastButton == LOW && currentButton == HIGH) // Если кнопка нажата
  {
    ledMode++; // Приращиваем к переменной статуса светодиода
  }
  lastButton = currentButton; // Обновление предыдущего состояния кнопки
  if (ledMode == 8)
  {
  ledMode = 0; //
  }
  setMode (ledMode); // Изменяем режим светодиода
}
