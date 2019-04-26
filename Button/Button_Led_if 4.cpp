//  Управление светодиодом с кнопки с таймером (циклично)

const int led=13; //
const int button=2; //
int val=0;  // 

 void setup()     
{
  pinMode(led, OUTPUT); //
  pinMode(button, INPUT); //          
} 

 void loop() 

{ 
  if(digitalRead(button)==HIGH)//если кнопка нажата ... 
  { 
    val++;  // прибавляем к переменной 1 при каждой смене цикла. 
    delay(500); //небольшая защита от "дребезга" контактов кнопки 
  } 
  else 
    { 
      val=0; 
    } 
  if(val>=3) // три 
    { 
      digitalWrite(led,!digitalRead(led));  //инвертируем состояние пина 
      val=0;
    } 
}
