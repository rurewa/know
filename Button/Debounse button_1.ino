// Debounse button
// V 1.0

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

Button button;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  button.checkState(); // Использование объекта с методом проверки состояний кнопки
}
