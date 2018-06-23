// Blinking LED control with potentiometer
// V 1.0
const int led = 9;
const int pot = 1;
int val = 0;

void setup() 
{
    pinMode(led, OUTPUT);
}

void loop() 
{
  val = analogRead(pot);
  val = map(val, 0, 1023, 0, 255); // Преобразование аналогового значение в цивровое
  digitalWrite(led, HIGH);
  delay(val);
  digitalWrite(led, LOW);
  delay(val);     
}
