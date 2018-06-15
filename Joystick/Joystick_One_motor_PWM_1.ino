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
  valY = map (analogRead(VRy), 0, 1023, -255, 255);
  Serial.print("valY: ");
  Serial.println(valY, DEC);
  Serial.print("\t");
  delay(70);
  if (valY >= -10 && valY <= 10)  
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      Serial.print("X stop\t");
    }
  if (valY > 11)  
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ENA, valY);
      Serial.print("X up\t");
    }
  if (valY < -11)  
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(ENA, -valY);
      Serial.print("X down\t");
    }
}
