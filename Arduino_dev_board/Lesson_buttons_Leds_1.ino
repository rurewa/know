// Arduino_dev_board v 1.0
// V 1.0
// Lesson buttons 1
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
}

void loop() 
{
   /* 
   Если значение нажатой кнопки больше 700, 
   то 1 (HIGH), иначе 0 (LOW)
    */
   val1 = analogRead(inPin1) > 700 ? HIGH : LOW;
   val2 = analogRead(inPin2) > 700 ? HIGH : LOW;
   Serial.println(val1);
   if (val1 == HIGH)
   {
       digitalWrite(led1, HIGH);
       delay(50);
   }
   else
   {
       digitalWrite(led1, LOW);
   }
   if (val2 == HIGH)
   {
       digitalWrite(led2, HIGH);
       delay(50);
   }
   else
   {
       digitalWrite(led2, LOW);
   }
}
