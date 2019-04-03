#include <Servo.h>
Servo myservo1;
Servo myservo2;
const int VRx = 1;
const int VRy = 0;
const int SWz = 2;
int dataX = 0;
int dataY = 0;
int buttonZ = 0;

void setup()
{
  myservo1.attach(9);
  myservo2.attach(12);
  pinMode(SWz, INPUT_PULLUP);
  pinMode(13, OUTPUT);
}

void loop()
{
  dataX = analogRead(VRx);
  dataX = map (dataX, 0, 1023, 0, 179);
  myservo1.write(dataX);
  dataY = analogRead(VRy);
  dataY = map (dataY, 0, 1023, 0, 179);
  myservo2.write(dataY);
  buttonZ = digitalRead(SWz);
  buttonZ = buttonZ ^ 1;
if (buttonZ == !LOW)
  {
    digitalWrite(13, HIGH);
  }
else
  {
  digitalWrite(13, LOW);
  }
}
