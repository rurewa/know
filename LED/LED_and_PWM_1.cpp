const int pot = 5;
int val = 0;

void setup() 
{
  pinMode(6, OUTPUT);
}

void loop() 
{
  val = analogRead(pot) / 4;
  analogWrite(6, val);
}

