// For robocar Nano motors board
// V 1.0 for kegelring end sumo
#include <Arduino.h>
#include <NewPing.h>
const int ENA = 10;
const int MotorRight = 12;
const int ENB = 9; 
const int MotorLeft = 11;
const int SensorMiddle= 7;
const int echo = 3;
const int trig = 5;
NewPing sonar (trig, echo, 400);

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(MotorRight, OUTPUT); 
  pinMode(MotorLeft, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
    int SM = digitalRead(SensorMiddle);
    Serial.println(sonar.ping_cm()); // Отладка
    //Serial.println(SM); // Отладка
    // delay(150); // Отладка
    // Если расстояние до объекта > 40 см.
    if (sonar.ping_cm() > 40)
    {
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        delay(600);
        digitalWrite(MotorRight, HIGH);
        analogWrite(ENA, 135);
        digitalWrite(MotorLeft, LOW);
        analogWrite(ENB, 135);
        delay(250);
    }
    else if (SM == HIGH)
    {
        digitalWrite(MotorRight, LOW);
        analogWrite(ENA, 135);
        digitalWrite(MotorLeft, LOW);
        analogWrite(ENB, 135);
        delay(2000);
    }
    else
    {
        digitalWrite(MotorRight, HIGH);
        analogWrite(ENA, 135);
        digitalWrite(MotorLeft, HIGH);
        analogWrite(ENB, 135);
        delay(1000);
    }  
}
