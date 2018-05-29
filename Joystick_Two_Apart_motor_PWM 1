#define ENA 3
#define in1 9
#define in2 10
#define ENB 5
#define in3 12
#define in4 11
int valX, valY;
 
void setup() 
{
  Serial.begin(9600);  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
 
void loop() 
{
  valX = map(analogRead(A0), 0, 1024, -255, 255);
  valY = map(analogRead(A1), 0, 1024, -255, 255);
 
  Serial.print(valX);    //выводим значение x
  Serial.print("\t");      //отступ
  Serial.print(valY);    //выводим значение y
  Serial.print("\t");
  if (valX >= -10 && valX <= 10)  
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    Serial.print("X stop\t");
  }
  if (valX > 11)  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(ENA, valX);
    Serial.print("X up\t");
  }
  if (valX < -11)  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, -valX);
    Serial.print("X down\t");
  }
 
  if (valY >= -10 && valY <= 10)   
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.print("Y stop\t");
  }
  if (valY > 11)  
  {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(ENB, valY);
    Serial.print("Y up\t");
  }
  if (valY < -11)  
  {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(ENB, -valY);
    Serial.print("Y down\t");
  }
  Serial.println("");
}
