// For robocar from China
// V 1.0 for kegelring end sumo
#include <NewPing.h>
const int ENA = 3;
const int in1 = 5;
const int in2 = 6;
const int ENB = 9; 
const int in3 = 7;
const int in4 = 8;
const int SensorMiddle= 11;
const int echo = 2;
const int trig = 4;
NewPing sonar (trig, echo, 200);

void setup() 
{
    Serial.begin(9600);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    analogWrite(ENA, 155);
    analogWrite(ENB, 155);
}

void loop() 
{
    /*Serial.println(sonar.ping_cm()); // Отладка
    Serial.println(SM);
    delay(150);*/
    int SM = digitalRead(SensorMiddle);
    // Если расстояние до объекта < 20 см.
    if (sonar.ping_cm() < 40) // Вперёд!
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(300);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(1000);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(1000);
    }
    else if (SM == HIGH) // Назад!
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(500);
    }
    else // Иначе ищем цель
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(500);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(500);
    }
}
