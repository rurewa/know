#include <Arduino.h>
// For robocar from China
// V 1.0 for biatlon clockwise
const int ENA = 3;
const int in1 = 5;
const int in2 = 6;
const int ENB = 9; 
const int in3 = 7;
const int in4 = 8;
const int SensorLeft = 10;
const int SensorMiddle= 11;
const int SensorRight = 12;

void setup()
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop()
{
  //int diy = 500; 
  int SL = digitalRead(SensorLeft);
  int SM = digitalRead(SensorMiddle);
  int SR = digitalRead(SensorRight);
  int turn = 135; // скорость для поворота
  int motion = 55; // скорость движения прямо   назад
  // код для диагностики
  Serial.print("Left: ");
  Serial.print(SL);
  Serial.print(" Middle: ");
  Serial.print(SM);
  Serial.print(" Right: ");
  Serial.println(SR);
  // ----------------------
  // основной алгоритм
  // Если M на чёрном, а L и R на белом - прямо!
  if (SL == LOW && SM == HIGH && SR == LOW) 
  {
    analogWrite(ENA, motion);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENB, motion);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
 // Если L и M на белом - вправо!
  else if (SL == LOW && SM == LOW && SR == HIGH) 
  {
    analogWrite(ENA, turn);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENB, turn);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
  }
  // Если M и R на белом - влево!
  else if (SL == HIGH && SM == LOW && SR == LOW)
  {
    analogWrite(ENA, turn);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENB, turn);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Если L и M на чёрном - влево!
  else if (SL == HIGH && SM == HIGH && SR == LOW)
  {
    analogWrite(ENA, turn);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENB, turn);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  // Если M и R на чёрном - вправо!
  else if (SL == LOW && SM == HIGH && SR == HIGH) 
  {
    analogWrite(ENA, turn);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENB, turn);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  // Если L и R на чёрном, а M на белом - прямо и вправо!
  else if (SL == HIGH && SM == LOW && SR == HIGH)
  {
    analogWrite(ENA, motion); // Прямо!
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENB, motion);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(500);
    analogWrite(ENA, turn); // Вправо!
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENB, turn);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(500);
  }
  // Если все на чёрном - чуть вправо и прямо!
  else if (SL == HIGH && SM == HIGH && SR == HIGH) 
  {
    analogWrite(ENA, turn); // Вправо!
    digitalWrite(in1, HIGH);
    digitalWrite(in2,LOW);
    analogWrite(ENB, turn);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(300);
    analogWrite(ENA, motion); // Прямо!
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENB, motion);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(300);
  }
  // Если все на белом - вправо!
  else
  {
    analogWrite(ENA, turn); // Вправо!
    digitalWrite(in1, HIGH);
    digitalWrite(in2,LOW);
    analogWrite(ENB, turn);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(300);
  }
}
