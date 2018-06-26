#include <Arduino.h>
// Joystick one motor PWM 1
// V 1.0
int ENA = 3, in1 = 4, in2 = 6;
int valY;
 
void setup() 
{
  Serial.begin(9600); 
  pinMode(ENA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop()
{
  valY = map (analogRead(A1), 0, 1023, -255, 255);
  Serial.print("valY: ");
  Serial.println(valY, DEC);
  Serial.print("\t");
  delay(70);
  if (valY >= -10 && valY <= 10)  
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      Serial.print("Y stop\t");
    }
  if (valY > 11)  
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ENA, valY);
      Serial.print("Y up\t");
    }
  if (valY < -11)  
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(ENA, -valY);
      Serial.print("Y down\t");
    }
}
