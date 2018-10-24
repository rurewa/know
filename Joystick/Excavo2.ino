#include <Arduino.h>
#include <AFMotor.h> // Фирменная библиотека Adafruit Motor Shield
// https://github.com/adafruit/Adafruit-Motor-Shield-library

// Для экскаватора
// V 1.2

int8_t value1X = 0, value3X= 0, value4Y = 0; // Три джойстика

AF_DCMotor Motor1(1); // Объект мотора 2 из библиотеки
AF_DCMotor Motor3(3); // Объект мотора 3 из библиотеки
AF_DCMotor Motor4(4); // Объект мотора 4 из библиотеки

void Motor1_X() // Мотор2 по X
{
  value1X = map (analogRead(A0), 0, 1023, -127, 127);

  if (value1X >= -10 && value1X <= 10)  
    {
      Motor1.run(RELEASE);
    }
  if (value1X > 11)
    {
      Motor1.run(FORWARD);
      Motor1.setSpeed(value1X);
    }
  if (value1X < -11)
    {
      Motor1.run(BACKWARD);
      Motor1.setSpeed(-value1X);
    }
}

void Motor3_X() // Мотор по X
{
  value3X = map (analogRead(A1), 0, 1023, -127, 127);

  if (value3X >= -10 && value3X <= 10)  
    {
      Motor3.run(RELEASE);
    }
  if (value3X > 11)
    {
      Motor3.run(FORWARD);
      Motor3.setSpeed(value3X);
    }
  if (value3X < -11)
    {
      Motor3.run(BACKWARD);
      Motor3.setSpeed(-value3X);
    }
}

void Motor4_Y() // Мотор по Y
{
  value4Y = map (analogRead(A2), 0, 1023, -127, 127);

  if (value4Y >= -10 && value4Y <= 10)  
    {
      Motor4.run(RELEASE);
    }
  if (value4Y > 11)  
    {
      Motor4.run(FORWARD);
      Motor4.setSpeed(value4Y);
    }
  if (value4Y < -11)  
    {
      Motor4.run(BACKWARD);
      Motor4.setSpeed(-value4Y);
    }
}

void setup()
{
  Motor1.run(RELEASE);
  Motor3.run(RELEASE);
  Motor4.run(RELEASE);
}

void loop() 
{  
  Motor1_X();
  Motor3_X();
  Motor4_Y();  
}
