// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Для ArduinoDevBoard 2.0
// Светодиодная индикация показаний с Сонара
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //

const int trig = 14;
const int echo = 15;
NewPing sonar(trig, echo, 40);

void setup() 
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  for (int thisPin = 8; thisPin <= 12; ++thisPin)
    {
      pinMode(thisPin, OUTPUT);
    }
}

void loop() 
{
  Serial.println(sonar.ping_cm());
  unsigned sm = sonar.ping_cm();
  if (sm <= 0)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  else if (sm > 0 && sm <= 5)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  else if(sm > 5 && sm <= 10)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  else if(sm > 10 && sm <= 20)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }
  else if(sm > 20 && sm <= 30)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }
  else if(sm > 30 && sm <= 40)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }
  }
