// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Счётчик с кратным нажатию приращением, ограничителем по количеству приращений и простым "антидребегом"
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
int MODE = 0; // Значение статуса режима RGB светодиода
const int COUNT = 5; // Предельное число режимов
bool currentState = false; // Текущее состояние кнопки
bool lastState = false; // Флаг предыдущего состояния кнопки. Служит для синхронизации между подпрограммами

void blueMode();
void greenMode();
void redMode();
void offMode();

void setup() {
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(17); // Опрашиваем кнопку
  if(currentState == true && lastState == false) // Если текущее состояние отличается от предыдущего
    {
      delay(5); // Ждём немного (для стабилизации кнопки после эффекта "дребезга")
      currentState = digitalRead(17); // Снова опрашиваем кнопку для подтверждения
      if(currentState != lastState) // Если текущее состояние подтверждается
      {
        while (MODE++ >= COUNT) { MODE = 0; } // Запускаем счётчик с ограничителем
        // Предыдущее состояние уже стало true! Поэтому меняем значение, чтобы больше не повторялось
        lastState = currentState;
        Serial.println(MODE);
      }
    }
  // Если текущее состояние кнопки false, то предыдущее состояние, по логике, должно быть true!
  if (currentState == false) { lastState = currentState; }

  //lastState = currentState;

    /*if(digitalRead(17) == true && !flag)
    {
        delay(10);
        int hp = digitalRead(17);
        if(hp == true)
        {
            flag = true;
            switch(MODE)
            {
                case 1:
                    blueMode();
                    break;
                case 2:
                    greenMode();
                    break;
                case 3:
                    redMode();
                    break;
                default:
                    offMode();
                    break;
            }
            if(MODE != COUNT) MODE++;
            else MODE = 0;
            Serial.println(MODE);
        }
    }
    if(digitalRead(17) == false) flag = false;*/
}

void blueMode()
{
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
}

void greenMode()
{
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
}

void redMode()
{
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
}

void offMode()
{
  digitalWrite(RLED, LOW);
  digitalWrite(GLED, LOW);
  digitalWrite(BLED, LOW);
}

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //