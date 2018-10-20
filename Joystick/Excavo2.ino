#include <Arduino.h>
#include <AFMotor.h> // Фирменная библиотека Adafruit Motor Shield
// https://github.com/adafruit/Adafruit-Motor-Shield-library

// Для экскаватора
// V 1.1

int8_t valueX = 0, valueY= 0; // Два джойстика

AF_DCMotor Motor3(3); // Объект мотора 3
AF_DCMotor Motor4(4); // Объект мотора 4

void Motor3_X()
{
  // Считываем значения с аналоговых пинов и 
  // преобразуем их из диапазона 0-1023 в диапазон 0-127
  valueX = map (analogRead(A0), 0, 1023, -127, 127);

  // Джойстик по оси X
  // Если положение джойстика находится по центру
  if (valueX >= -10 && valueX <= 10)  
    {
      Motor3.run(RELEASE); // Останавливаем мотор
    }
  if (valueX > 11) // Если положение джойстика по X больше 11  
    {
      Motor3.run(FORWARD); // Крутим мотор3 вперёд
      Motor3.setSpeed(valueX); // Со скоростью от 11 до 127 по ШИМ
    }
  if (valueX < -11) // Если положение джойстика по X меньше 11
    {
      Motor3.run(BACKWARD); // Крутим мотор3 назад
      Motor3.setSpeed(-valueX); // Со скоростью от -11 до -127 по ШИМ
    }
}

void Motor4_Y()
{
  valueY = map (analogRead(A1), 0, 1023, -127, 127);

  // Джойстик по оси Y

  if (valueY >= -10 && valueY <= 10)  
    {
      Motor4.run(RELEASE);
    }
  if (valueY > 11)  
    {
      Motor4.run(FORWARD); // Крутим мотор4 вперёд
      Motor4.setSpeed(valueY);
    }
  if (valueY < -11)  
    {
      Motor4.run(BACKWARD); // Крутим мотор4 назад
      Motor4.setSpeed(-valueY);
    }
}

void setup()
   {
        // Останавливаем моторы 3 и 4
        Motor3.run(RELEASE);
        Motor4.run(RELEASE);
   }

void loop() 
{  
  Motor3_X();
  Motor4_Y();  
}
