// Arduino_dev_board v 1.0
// Revers wave leds 1
// V 1.0
const int inPin1 = 7;
const int inPin2 = 6;
int val1;
int val2;
int timer = 50;

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
    /* 
   Если значение нажатой кнопки больше 700, 
   то 1 (HIGH), иначе 0 (LOW)
    */
   val1 = analogRead(inPin1) > 700 ? HIGH : LOW;
   val2 = analogRead(inPin2) > 700 ? HIGH : LOW;
   if (val1 != LOW) // Влево
    {
        digitalWrite(8, HIGH);
        delay(timer);
        digitalWrite(8, LOW);
        delay(timer);
        digitalWrite(9, HIGH);
        delay(timer);
        digitalWrite(9, LOW);
        delay(timer);
        digitalWrite(10, HIGH);
        delay(timer);
        digitalWrite(10, LOW);
        delay(timer);
        digitalWrite(11, HIGH);
        delay(timer);
        digitalWrite(11, LOW);
        delay(timer);
        digitalWrite(12, HIGH);
        delay(timer);
        digitalWrite(12, LOW);
        delay(timer);
    }
   else if (val2 != LOW) // Вправо
    {
        digitalWrite(12, HIGH);
        delay(timer);
        digitalWrite(12, LOW);
        delay(timer);
        digitalWrite(11, HIGH);
        delay(timer);
        digitalWrite(11, LOW);
        delay(timer);
        digitalWrite(10, HIGH);
        delay(timer);
        digitalWrite(10, LOW);
        delay(timer);
        digitalWrite(9, HIGH);
        delay(timer);
        digitalWrite(9, LOW);
        delay(timer);
        digitalWrite(8, HIGH);
        delay(timer);
        digitalWrite(8, LOW);
        delay(timer);
    }
   else
    {
       digitalWrite(12, HIGH);
       digitalWrite(11, HIGH);
       digitalWrite(10, HIGH);
       digitalWrite(9, HIGH);
       digitalWrite(8, HIGH); 
    }
}
