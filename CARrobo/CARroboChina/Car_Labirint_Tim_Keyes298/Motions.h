// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот для прохождения лабиринта. Файл с кодом поведения 
// Автор - Тимофей Чичерин
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
#include <Arduino.h>
#include <NewPing.h>

const unsigned int ECHO_PIN = 8;
const unsigned int TRIG_PIN = 7;

NewPing sonar(TRIG_PIN, ECHO_PIN, 400); // Максимальное расстояние видимости

int E1 = 10;     // Motor A1
int M1 =  12;     // Motor A2 (left motor)

int E2 =  11;     // Motor B1
int M2 =  13;     // Motor B2 (right motor)

int SPEED = 160;  // Speed PWM 0 - 255
const int Left = 17, Middle = 18, Right = 19;

void forward()
{
    digitalWrite(M1, !HIGH);
    digitalWrite(M2, !HIGH);
    analogWrite(E1, SPEED);
    analogWrite(E2, SPEED);
}

void backward()
{
    digitalWrite(M1, !LOW);
    digitalWrite(M2, !LOW);
    analogWrite(E1, SPEED);
    analogWrite(E2, SPEED);
}

void left()
{
    digitalWrite(M1, !LOW);
    digitalWrite(M2, !HIGH);
    analogWrite(E1, SPEED);
    analogWrite(E2, SPEED);
}

void right()
{
    digitalWrite(M1, !HIGH);
    digitalWrite(M2, !LOW);
    analogWrite(E1, SPEED);
    analogWrite(E2, SPEED);
}

void forward_left()
{

    right();
    delay(650);
}

void stop()
{
    analogWrite(E1, 0);
    analogWrite(E2, 0);
}
void avtoroute()
{
  int front = digitalRead(Middle);
  int left1 = digitalRead(Left);
  int right1 = digitalRead(Right);
  int MaxDistation = 17;
  int Distation = sonar.ping_cm();
  int flag = 0;

  if(left1 == LOW && front == HIGH && right1 == LOW) flag = 0; //010
  else if(left1 == HIGH && front == HIGH && right1 == LOW) flag = 2; // 110
  else if(left1 == LOW && front == HIGH && right1 == HIGH) flag = 1; // 011
  else if(left1 == HIGH && front == LOW && right1 == LOW) flag = 2; //100
  else if(left1 == LOW && front == LOW && right1 == HIGH) flag = 1; // 001
  else if(left1 == HIGH && front == HIGH && right1 == HIGH) flag = 0;//111
  else if(left1 == HIGH && front == LOW && right1 == HIGH) flag = 0; //101
  else flag = 4;
  switch(flag)
  {
      case 0: backward(); break;
      case 1: left(); break;
      case 2: right(); break;
      case 3: forward_left(); break;
      case 4: forward();break;
  }
  if(Distation <= MaxDistation)
  {
      forward_left();
  }
}
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// END FILE
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //