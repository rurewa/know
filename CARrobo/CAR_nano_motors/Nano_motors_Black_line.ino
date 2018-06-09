// Black line movement for Nano motors board
// V 1.0
const int ENA = 10;
const int MotorRight = 12;
const int ENB = 9; 
const int MotorLeft = 11;
const int SensorLeft = 8;
const int SensorMiddle= 7;
const int SensorRight = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(MotorRight, OUTPUT); 
  pinMode(MotorLeft, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  // скорость моторов
  analogWrite(ENA, 105);
  analogWrite(ENB, 105);
}

void loop()
{
  int diy = 150; // чтобы не дёргался на одном месте 
  int SL = digitalRead(SensorLeft);
  int SM = digitalRead(SensorMiddle);
  int SR = digitalRead(SensorRight);
  // это для диагностики датчиков
  // ----------------------------------------------
  Serial.print("Left: "); 
  Serial.print(SL); 
  Serial.print(" Middle: "); 
  Serial.print(SM);
  Serial.print(" Right: ");
  Serial.println(SR);
  // -----------------------------------------------
  // Если M на чёрном, а L и R на белом - прямо!
  if (SL == LOW && SM == HIGH && SR == LOW) 
  {
    digitalWrite(MotorRight, HIGH);
    digitalWrite(MotorLeft, HIGH);
  }
  // Если R и M на белом - влево!
  else if (SL == HIGH && SM == LOW && SR == LOW) 
  {
    digitalWrite(MotorRight, HIGH);
    digitalWrite(MotorLeft, LOW);
  }
  
  // Если L и M на белом - вправо!
  else if (SL == LOW && SM == LOW && SR == HIGH)
  {
    digitalWrite(MotorRight, LOW);
    digitalWrite(MotorLeft, HIGH);
  }
  // Если L и M на чёрном - влево!
  else if (SL == HIGH && SM == HIGH && SR == LOW)
  {
    digitalWrite(MotorRight, HIGH);
    digitalWrite(MotorLeft, LOW);
  }
  // Если R и M на чёрном - вправо!
  else if (SL == LOW && SM == HIGH && SR == HIGH) 
  {
    digitalWrite(MotorRight, LOW);
    digitalWrite(MotorLeft, HIGH);
  }
  // Если все на чёрном - влево!
  else if (SL == HIGH && SM == HIGH && SR == HIGH) 
  {
    digitalWrite(MotorRight, HIGH);
    digitalWrite(MotorLeft, HIGH);
    delay(diy);
    digitalWrite(MotorRight, HIGH);
    digitalWrite(MotorLeft, LOW);
    delay(diy);
  }
  // Если все на белом - вправо!
  else
  {
    digitalWrite(MotorRight, LOW);
    digitalWrite(MotorLeft, HIGH);
  }
}
