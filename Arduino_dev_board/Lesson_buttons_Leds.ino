// Arduino_dev_board v 1.0
// V 1.0
// Lesson buttons
const int led1 = 8;
const int led2 = 9;
const int inPin8 = A7;
const int inPin9 = A6;
int val1;
int val2;

void setup() 
{
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(inPin8, INPUT);
    pinMode(inPin9, INPUT);
}

void loop() 
{
   val1 = analogRead(inPin8) > 700 ? LOW : HIGH;
   val2 = analogRead(inPin9) > 700 ? LOW : HIGH;
   if (val1 == LOW)
   {
       digitalWrite(led1, HIGH);
   }
   else
   {
       digitalWrite(led1, LOW);
   }
   if (val2 == LOW)
   {
       digitalWrite(led2, HIGH);
   }
   else
   {
       digitalWrite(led2, LOW);
   }
}
