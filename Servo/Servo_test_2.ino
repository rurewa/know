#include <Servo.h>
Servo myservo;

void setup()
{
  myservo.attach(9);
}

void loop()
{
  for(int i=15;i<=165;i++)
    {
      myservo.write(i);
      delay(100);
    }  
  for (int i=165; i>15; i--)
    {
      myservo.write(i);
      delay(100);
    } 
}
