// Arduino_dev_board v 1.0
// V 1.0
// Lesson buttons 2
const int led1 = 8;
const int led2 = 9;
const int inPin1 = 7;
const int inPin2 = 6;
int val1;
int val2;

void setup() 
{
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(inPin1, INPUT);
    pinMode(inPin2, INPUT);
}

void loop() 
{
   val1 = analogRead(inPin1) > 700 ? LOW : HIGH;
   val2 = analogRead(inPin2) > 700 ? LOW : HIGH;
   if (digitalRead(val1) == HIGH)
   {
       digitalWrite(led1,!analogRead(val1));
       delay(50);
   }
   if (digitalRead(val2) == HIGH)
   {
       digitalWrite(led2,!analogRead(val2));
       delay(50);
   }
}
