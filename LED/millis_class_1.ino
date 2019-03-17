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
                // Если millis() минус 0 и больше или равно 0, выполняем:
                if (currentMillis - previousMillis >= _interval) {
                    previousMillis = currentMillis; // Предыдущее время меняется на текущее
                    return ready = !ready; // Инвертируем флаг и возвращаем флаг
                }
                else { ready = false; return ready; } // Иначе возвращаем значение флага

        }
};

TimerOne Test5000ms(5000);
TimerOne Test1000ms(1000);

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
    if(Test5000ms.callback()) {
      digitalWrite(13, HIGH);
      Serial.println(5000);
    }
    while(Test1000ms.callback()){
      digitalWrite(13, LOW);
      Serial.println(1000);
    }
}