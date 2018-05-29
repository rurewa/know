// Управление светодиодом с кнопки (циклично)

const int led = 13;  // Контакт 13 для подключения светодиода
const int button=2; // Контакт 2 для подключение кнопки

void setup()
{
  pinMode(led, OUTPUT); // Настраиваем led как выход
  pinMode(button, INPUT); // Настраиваем button как вход
}

void loop()
{
  if (digitalRead(button) == LOW) // Если кнопка не нажата
  {
    digitalWrite(led, LOW); // светодиод выключен
  }
  else
  {
    digitalWrite(led, HIGH); // иначе светодиод включен
  }
}
