// Test driver motors for Nano motors board
// V 1.0
#include <Servo.h>
Servo myservo;
const int ENA = 10;
const int in2 = 12;
const int ENB = 9;
const int in3 = 11;
const int SensorLeft = 8;  
const int SensorMiddle= 7;
const int SensorRight = 6;

void setup() 
{ 
    Serial.begin(9600);
    myservo.attach(14);
    pinMode(in2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(in3, OUTPUT);
} 
  
void loop() 
{ 
// это для диагностики датчиков
// ----------------------------------------------    
    int SL = digitalRead(SensorLeft);
    int SM = digitalRead(SensorMiddle);
    int SR = digitalRead(SensorRight);
    Serial.print("Left: "); 
    Serial.print(SL); 
    Serial.print(" Middle: "); 
    Serial.print(SM);
    Serial.print(" Right: ");
    Serial.println(SR);
    delay(150);
// ----------------------------------------------
// Проверка сервопривода  
    myservo.write(0); // Устанавливаем сервопривод на 0 град.
    delay(1000);  // Задержка 1 сек.
    myservo.write(90);  // Устанавливаем сервопривод на 90 град.
    delay(1000);  // Задержка на 1 сек.
    myservo.write(180); // Устанавливаем сервопривод на 180 град.
    delay(1000);  // Задержка на 1 сек.
// ----------------------------------------------
// Проверка двигателей
   /* digitalWrite(in3, 0);
    analogWrite(ENB, 255);
    digitalWrite(in2, 0);
    analogWrite(ENA, 255); 
    delay(2500);
    analogWrite(ENB, 0);
    analogWrite(ENA, 0);
    delay(2500);
    digitalWrite(in3, 1);
    analogWrite(ENB, 255);
    digitalWrite(in2, 1);
    analogWrite(ENA, 255); 
    delay(2500);
    analogWrite(ENB, 0);
    analogWrite(ENA, 0);
    delay(2500);  */
// ----------------------------------------------
}
