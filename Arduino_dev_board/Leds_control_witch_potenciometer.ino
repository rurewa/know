// Arduino_dev_board v 1.0
// Leds control witch potenciometer
// V 1.0
const int pot = 1;
int val = 0;

void setup() 
{
    Serial.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop() 
{
   val = analogRead(pot);
   val = map(val, 0, 1023, 0, 75);
   Serial.println(val);
   if (val > 60 && val < 75)
   {
       digitalWrite(8, HIGH);
   }
   else if (val > 45 && val < 60)
   {
       digitalWrite(9, HIGH);
   }
   else if (val > 30 && val < 45)
   {
       digitalWrite(10, HIGH);
   }
   else if (val > 15 && val < 30)
   {
       digitalWrite(11, HIGH);
   }
   else if (val > 0 && val < 15)
   {
       digitalWrite(12, HIGH);
   }
   else
   {
       digitalWrite(8, LOW);
       digitalWrite(9, LOW);
       digitalWrite(10, LOW);
       digitalWrite(11, LOW);
       digitalWrite(12, LOW);
   }
}
