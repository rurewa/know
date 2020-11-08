// Управление RGB-светодиодом с кнопками

const int RLED=11; 
const int GLED=10;
const int BLED=9;
const int buttonR=2;
const int buttonG=3;
const int buttonB=4;
int flag=0; // можно давать любое название переменным


void setup() 

{
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(buttonR, INPUT);
  pinMode(buttonG, INPUT);
  pinMode(buttonB, INPUT);
}

void loop() 

{ 
  if (digitalRead(buttonR) == HIGH && flag==0)  //если кнопка нажата    
                                          // и перемення flag равна 0 , то ... 
  { 
    digitalWrite(RLED, !digitalRead(RLED)); 
    flag = 1; 
      //это нужно для того что бы с каждым нажатием кнопки 
      //происходило только одно действие 
      // плюс защита от "дребезга"  100% 
  } 
    if (digitalRead(buttonR) == LOW && flag == 1) //если кнопка НЕ нажата 
                                        //и переменная flag равна - 1 ,то ... 
    {  
      flag=0;   //обнуляем переменную flag 
    } 

{ 
  if (digitalRead(buttonG) == HIGH  && flag == 0)  //если кнопка нажата    
                                          // и перемення flag равна 0 , то ... 
  { 
    digitalWrite(GLED, !digitalRead(GLED)); 
    flag = 1; 
       //это нужно для того что бы с каждым нажатием кнопки 
       //происходило только одно действие 
       // плюс защита от "дребезга"  100% 
  } 
    if(digitalRead(buttonG == LOW & &flag == 1) //если кнопка НЕ нажата 
                                        //и переменная flag равна - 1 ,то ... 
    {  
      flag=0;   //обнуляем переменную flag 
    } 
{ 
  if(digitalRead(buttonB)==HIGH&&flag==0)  //если кнопка нажата    
                                          // и перемення flag равна 0 , то ... 
  { 
    digitalWrite(BLED, !digitalRead(BLED)); 
    flag = 1; 
       //это нужно для того что бы с каждым нажатием кнопки 
       //происходило только одно действие 
       // плюс защита от "дребезга"  100% 
  } 
    if(digitalRead(buttonB) == LOW && flag == 1) //если кнопка НЕ нажата 
                                        //и переменная flag равна - 1 ,то ... 
    {  
      flag = 0;   //обнуляем переменную flag 
    }     
}
}
}
