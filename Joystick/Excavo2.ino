#include <Arduino.h>
#include <AFMotor.h> // Фирменная библиотека Adafruit Motor Shield
// https://github.com/adafruit/Adafruit-Motor-Shield-library

// Для экскаватора
// V 1.1

int8_t valueX = 0, valueY= 0, value2X = 0; // Два джойстика

AF_DCMotor Motor2(2); // Объект мотора 2 из библиотеки
AF_DCMotor Motor3(3); // Объект мотора 3 из библиотеки
AF_DCMotor Motor4(4); // Объект мотора 4 из библиотеки

void Motor2_X() // Мотор2 по X
{
  value2X = map (analogRead(A2), 0, 1023, -127, 127);

  if (value2X >= -10 && valueX <= 10)  
    {
      Motor2.run(RELEASE);
    }
  if (value2X > 11)
    {
      Motor2.run(FORWARD);
      Motor2.setSpeed(valueX);
    }
  if (value2X < -11)
    {
      Motor2.run(BACKWARD);
      Motor2.setSpeed(-valueX);
    }
}

void Motor3_X() // Мотор по X
{
  valueX = map (analogRead(A0), 0, 1023, -127, 127);

  if (valueX >= -10 && valueX <= 10)  
    {
      Motor3.run(RELEASE);
    }
  if (valueX > 11)
    {
      Motor3.run(FORWARD);
      Motor3.setSpeed(valueX);
    }
  if (valueX < -11)
    {
      Motor3.run(BACKWARD);
      Motor3.setSpeed(-valueX);
    }
}

void Motor4_Y() // Мотор по Y
{
  valueY = map (analogRead(A1), 0, 1023, -127, 127);

  if (valueY >= -10 && valueY <= 10)  
    {
      Motor4.run(RELEASE);
    }
  if (valueY > 11)  
    {
      Motor4.run(FORWARD);
      Motor4.setSpeed(valueY);
    }
  if (valueY < -11)  
    {
      Motor4.run(BACKWARD);
      Motor4.setSpeed(-valueY);
    }
}

void setup()
{
  Motor3.run(RELEASE);
  Motor4.run(RELEASE);
}

void loop() 
{  
  Motor3_X();
  Motor4_Y();  
}
