const int VRy = 1;
const int ENA = 3;
const int in1 = 9;
const int in2 = 10;
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
  valY = map (analogRead(VRy), 0, 1023, 0, 255);
  Serial.print("Y: ");
  Serial.println(valY, DEC);
  Serial.print("\t");
  delay(70);
  if (valY <= 100)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else if (valY > 101 && valY < 149)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  if (valY >= 150)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }
  else if (valY > 101 && valY < 149)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
}
