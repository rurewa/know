// Joystick & servo
// V 1.0

#include <Servo.h>  // Подключаем библиотеку
Servo myservo;  // Создаём объект сервопривода
int valY;
 
void setup() 
{
  Serial.begin(9600);
  myservo.attach(5); // Сервопривод на D5
}

void loop()
{
  valY = map (analogRead(A1), 0, 1024, 0, 179);
  Serial.print("valY: ");
  Serial.println(valY, DEC);
  Serial.print("\t");
  delay(70);
  myservo.write(valY);
}
