int xValue, yValue;
int in1 = 9;
int in2 = 10;
int in3 = 12;
int in4 = 11;
int xPin = A0;
int yPin = A1;   

void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  xValue = map(analogRead(xPin), 0, 1024, 0, 252);
  yValue = map(analogRead(yPin), 0, 1024, 0, 252);
  Serial.print("X: ");
  Serial.print(xValue); //выводим значение x
  Serial.print("\t"); //отступ
  Serial.print("Y: ");
  Serial.println(yValue); //выводим значение y
  Serial.print("\t"); //отступ
  delay(70);
  if (xValue <= 100)
    {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    }
  else if (xValue > 101 && xValue <149)
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
  if (xValue >= 150)
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }
  else if (xValue > 101 && xValue <149)
    {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
///////////////////////////////////////////
  if (yValue <= 100)
    {
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
  else if (yValue > 101 && yValue <149)
    {
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
  if (yValue >= 150)
    {
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
  else if (yValue > 101 && yValue <149)
    {
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
}
