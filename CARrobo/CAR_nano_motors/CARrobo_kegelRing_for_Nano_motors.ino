// For robocar Nano motors board
// V 1.0 for kegelring end sumo
#include <Arduino.h>
#include <NewPing.h>
#include <Servo.h>
Servo myservo;
const int ENA = 10;
const int MotorRight = 12;
const int ENB = 9; 
const int MotorLeft = 11;
const int SensorMiddle= 7;
const int echo = 3;
const int trig = 5;
NewPing sonar (trig, echo, 200);

void setup()
{
  Serial.begin(9600);
  //myservo.attach(13);
  pinMode(MotorRight, OUTPUT); 
  pinMode(MotorLeft, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  myservo.write(90);
}

void loop()
{
    int SM = digitalRead(SensorMiddle);
    Serial.println(sonar.ping_cm()); // Отладка
    Serial.println(SM);
    // Если расстояние до объекта < 40 см.
    if (sonar.ping_cm() > 0 && (sonar.ping_cm()) <= 40) // Вперёд!
    {
      digitalWrite(MotorRight, HIGH);
      analogWrite(ENA, 155);
      digitalWrite(MotorLeft, HIGH);
      analogWrite(ENB, 155);
      delay(3000);
      digitalWrite(MotorRight, LOW);
      analogWrite(ENA, 155);
      digitalWrite(MotorLeft, LOW);
      analogWrite(ENB, 155);
      delay(3000);
    }
    else if (SM == HIGH) // Назад!
    {
      digitalWrite(MotorRight, LOW);
      analogWrite(ENA, 155);
      digitalWrite(MotorLeft, LOW);
      analogWrite(ENB, 155);
      delay(3000);
    }
    else // Иначе ищем цель
    {
      digitalWrite(MotorRight, LOW);
      analogWrite(ENA, 155);
      digitalWrite(MotorLeft, HIGH);
      analogWrite(ENB, 155);
      delay(200);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      delay(200);
    }
}
