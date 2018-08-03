// Debounсe two button using Class & Metod for Arduino dev board 2.0
// V 1.0

const int led1 = 8;
const int led2 = 9;
const int inPin1 = 13; // Кнопка 1
const int inPin2 = 2; // Кнопка 2 (на Arduino pin A2)

class Button // Класс, содержащий переменные состояний кнопки и метод их обработки
{
  public: // Модификатор. Доступ открыт всем, кто видит определение данного класса
    boolean buttonState1;      // Текущее состояние кнопки 1
    boolean buttonState2;      // Текущее состояние кнопки 2
    boolean buttonPrevState1;  // Предыдущее состояние кнопки 1
    boolean buttonPrevState2;  // Предыдущее состояние кнопки 1
    boolean ledState; // Состояние светодиода (вкл/выкл)
  void checkState(); // Метод проверки состояния кнопки
};

void Button::checkState() // Метод, содержащийся в классе Button
{
  buttonState1 = digitalRead(inPin1); // Записываем состояние кнопки в переменную buttonState1
  buttonState2 = analogRead(inPin2) > 700 ? HIGH : LOW; // Для buttonState2. Если аналоговое значение > 700 то HIGH, иначе LOW
  if (buttonPrevState1 == LOW && buttonState1 == HIGH)
  {
    // Если предыдущее состояние кнопки - отжата, а текущее - нажата
    delay(20); // Небольшая задержка для стабилизирования сигнала
    ledState = !ledState;        // Инвертируем состояние светодиода
    digitalWrite(led1, ledState); // Управляем светодиодом 1
  }
  buttonPrevState1 = buttonState1; // Изменяем предыдущее состояние кнопки для повторения цикла
  if (buttonPrevState2 == LOW && buttonState2 == HIGH)
  {
    // Если предыдущее состояние кнопки - отжата, а текущее - нажата
    delay(20); // Небольшая задержка для стабилизирования сигнала
    ledState = !ledState;        // Инвертируем состояние светодиода
    digitalWrite(led2, ledState); // Управляем светодиодом 2
  }
  buttonPrevState2 = buttonState2; // Изменяем предыдущее состояние кнопки для повторения цикла
}

Button button1; // Объект кнопки 1
Button button2; // Объект кнопки 2

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()
{
  button1.checkState(); // Для объекта button1 циклично работает метод checkState()
  button2.checkState(); // Для объекта button2 циклично работает метод checkState()
}
