// For robocar from China
// V 1.0 for kegelring end sumo
#include <Arduino.h>
#include <NewPing.h>
const int ENA = 3;
const int in1 = 5;
const int in2 = 6;
const int ENB = 9; 
const int in3 = 7;
const int in4 = 8;
const int SensorMiddle= 11;
const int trig = 4;
const int echo = 13;
NewPing sonar(trig, echo);

void setup() 
{
    Serial.begin(9600);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(trig, OUTPUT);
    analogWrite(ENA, 125);
    analogWrite(ENB, 125);
}

void loop() 
{
    int SM = digitalRead(SensorMiddle);
    Serial.println(sonar.ping_cm()); // Отладка
    //Serial.println(SM); // Отладка
    if (sonar.ping_cm() >= 40)
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(400);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(250);
    }
    else if (SM == HIGH)
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(1000);
    }
    else
    {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        //delay(250);
    }
delay(150);    
}
