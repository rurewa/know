// Arduino_dev_board v 1.0
// V 1.0
// Lesson buttons 2
const int led1 = 8;
const int led2 = 9;
const int inPin8 = A7;
const int inPin9 = A6;
int val1;
int val2;

void setup() 
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(inPin8, INPUT);
    pinMode(inPin9, INPUT);
}

void loop() 
{
   val1 = analogRead(inPin8) > 700 ? LOW : HIGH;
   val2 = analogRead(inPin9) > 700 ? LOW : HIGH;
   if(digitalRead(val1) == HIGH) //если кнопка нажата ... 
    {     
        digitalWrite(led1,!analogRead(val1));  //включаем светодиод (возможент эффект залипания кнопки)
        delay(100); // небольная защита от дребезга кнопки 
    } 
   if(digitalRead(val2) == HIGH) //если кнопка нажата ... 
    {     
        digitalWrite(led2,!analogRead(val2));  //включаем светодиод (возможент эффект залипания кнопки)
        delay(100); // небольная защита от дребезга кнопки 
    } 
}
