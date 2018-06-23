// Blinking LED control with potentiometer for Arduino_dev_board v 1.0
// V 1.0
const int pot = 1;
int val = 0;

void setup() 
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop() 
{
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255); // Преобразование аналогового значение в цивровое
  digitalWrite(8, HIGH);
  delay(val);
  digitalWrite(8, LOW);
  delay(val);  
  digitalWrite(9, HIGH);
  delay(val);
  digitalWrite(9, LOW);
  delay(val);
  digitalWrite(10, HIGH);
  delay(val);
  digitalWrite(10, LOW);
  delay(val);
  digitalWrite(11, HIGH);
  delay(val);
  digitalWrite(11, LOW);
  delay(val);
  digitalWrite(12, HIGH);
  delay(val);
  digitalWrite(12, LOW);
  delay(val);
}
