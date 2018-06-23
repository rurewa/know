// Arduino_dev_board v 1.0
// V 1.0
// Led wave

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
   for (int i=10; i<=500; i=i+20)
   {
       digitalWrite(8, HIGH);
       delay(i);
       digitalWrite(8, LOW);
       delay(i);
       digitalWrite(9, HIGH);
       delay(i);
       digitalWrite(9, LOW);
       delay(i);
       digitalWrite(10, HIGH);
       delay(i);
       digitalWrite(10, LOW);
       delay(i);
       digitalWrite(11, HIGH);
       delay(i);
       digitalWrite(11, LOW);
       delay(i);
       digitalWrite(12, HIGH);
       delay(i);
       digitalWrite(12, LOW);
       delay(i);
   }
}
