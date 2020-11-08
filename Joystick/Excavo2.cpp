#include <Arduino.h>
#include <AFMotor.h> // Фирменная библиотека Adafruit Motor Shield
// https://github.com/adafruit/Adafruit-Motor-Shield-library

// Для экскаватора
// V 1.2

int8_t joy1Y = 0, joy3X= 0, joy4X = 0; // Три джойстика

AF_DCMotor Motor1(1); // Объект мотора 2 из библиотеки
AF_DCMotor Motor3(3); // Объект мотора 3 из библиотеки
AF_DCMotor Motor4(4); // Объект мотора 4 из библиотеки

void Motor1_Y() // Мотор2 по оси Y
{
  joy1Y = map (analogRead(A0), 0, 1023, -127, 127);

  if (joy1Y >= -10 && joy1Y <= 10)  
    {
      Motor1.run(RELEASE);
    }
  if (joy1Y > 11)
    {
      Motor1.run(FORWARD);
      Motor1.setSpeed(joy1Y);
    }
  if (joy1Y < -11)
    {
      Motor1.run(BACKWARD);
      Motor1.setSpeed(-joy1Y);
    }
}

void Motor3_X() // Мотор по оси X
{
  joy3X = map (analogRead(A1), 0, 1023, -127, 127);

  if (joy3X >= -10 && joy3X <= 10)  
    {
      Motor3.run(RELEASE);
    }
  if (joy3X > 11)
    {
      Motor3.run(FORWARD);
      Motor3.setSpeed(joy3X);
    }
  if (joy3X < -11)
    {
      Motor3.run(BACKWARD);
      Motor3.setSpeed(-joy3X);
    }
}

void Motor4_X() // Мотор по X
{
  joy4X = map (analogRead(A2), 0, 1023, -127, 127);

  if (joy4X >= -10 && joy4X <= 10)  
    {
      Motor4.run(RELEASE);
    }
  if (joy4X > 11)  
    {
      Motor4.run(FORWARD);
      Motor4.setSpeed(joy4X);
    }
  if (joy4X < -11)  
    {
      Motor4.run(BACKWARD);
      Motor4.setSpeed(-joy4X);
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
  Motor1_Y();
  Motor3_X();
  Motor4_X();  
}
