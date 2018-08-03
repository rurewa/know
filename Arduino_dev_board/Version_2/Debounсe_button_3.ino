// Debounсe button using Class & Metod for Arduino dev board 2.0
// V 1.0

const int led = 8;
const int inPin = 13;

class Button // Класс, содержащий переменные состояний кнопки и метод их обработки
{
  public: // Модификатор. Доступ открыт всем, кто видит определение данного класса
    boolean buttonState;      // Текущее состояние кнопки
    boolean buttonPrevState;  // Предыдущее состояние кнопки
    boolean ledState; // Состояние светодиода (вкл/выкл)
    void checkState(); // Метод, содержащий функцию проверки состояния кнопки
};

void Button::checkState() // Метод, содержащийся в классе Button
{
  buttonState = digitalRead(inPin); // Записываем состояние кнопки в переменную buttonState
  if (buttonPrevState == LOW && buttonState == HIGH)
  {
    // Если предыдущее состояние кнопки - отжата, а текущее - нажата
    delay(20); // Небольшая задержка для стабилизирования сигнала
    ledState = !ledState;        // Инвертируем состояние светодиода
    digitalWrite(led, ledState); // Управляем светодиодом
  }
  buttonPrevState = buttonState; // Изменяем предыдущее состояние кнопки для повторения цикла
}

Button button; // Объект кнопки

void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  button.checkState(); // Для объекта button циклично работает метод checkState()
}
