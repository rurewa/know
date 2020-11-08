// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Управление яркостью светодиода с помощью задержки из класса
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>

class TimerOne {
    private:
        unsigned long currentMillis = 0; // Текущее время
        unsigned long previousMillis = 0; // Предыдущее время
        bool ready = false; // Флаг

    public:
        unsigned int _interval; // Интервал
        TimerOne(unsigned int interval) {
            _interval = interval; //
        }

        bool callback() { // Конструктор
                currentMillis = millis();
                if (currentMillis - previousMillis >= _interval) {
                    previousMillis = currentMillis;
                    return ready = !ready; // Инвертируем флаг
                }
                else { ready = false; return ready; } // Возвращаем значение флага

        }
};

//TimerOne Test5000ms(5000);
TimerOne Test1000ms(1000);

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
    static int up = 0;
    static int down = 5;
    if (Test1000ms.callback()) {
      analogWrite(9, up);
      up += down;
      // Когда up < 255 происходит приращение на 5. Когда up >=255
      // происходит выполнение up += -down
      if(up <= 0 || up >= 255) {
      down = -down; // up += -down. 255 + (-5) = 250 и т.д.
      }
      Serial.println(up);
    }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //