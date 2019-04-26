// Joystick Two Apart motor no PWM 1
// V 1.0
int in1 = 4, in2 = 6;
int in3 = 7, in4 = 8;
int xValue, yValue;
 
void setup() 
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}
 
void loop() 
{
  xValue = map(analogRead(A0), 0, 1024, -255, 255);
  yValue = map(analogRead(A1), 0, 1024, -255, 255);
  // Диагностика ----------------------------------
  Serial.print("Xvalue: ");
  Serial.print(xValue); //выводим значение x
  Serial.print("\t"); //отступ
  Serial.print("Yvalue: ");
  Serial.println(yValue); //выводим значение y
  Serial.print("\t");
  delay(100);
  // ----------------------------------------------
// Нейтральное положение - моторы стоп
if (xValue >= -10 && xValue <= 10)  
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    Serial.print("X stop\t");
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    Serial.print("Y stop\t");
}
if (xValue > 11) // Джойстик по Х вверх
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.print("X up\t");
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.print("Y up\t");
}
if (xValue < -11) // Джойстик по Х вниз  
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.print("X down\t");
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.print("Y down\t");
}
if (yValue > 11) // Джойстик по Y вправо 
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    Serial.print("X left\t");
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.print("Y left\t");
}
if (yValue < -11) // Джойстик по Y влево  
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    Serial.print("X right\t");
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.print("Y right\t");
}
  Serial.println("");
}
