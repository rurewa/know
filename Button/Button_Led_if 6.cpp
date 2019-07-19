// лишь одно действие (включение светодиода) по одому нажатию кнопки (не циклично)

const int led = 13; //
const int button = 2; //
int flag = 0; // 

void setup()    

{ 
  pinMode(led, OUTPUT); //
  pinMode(button, INPUT); //         
} 

void loop() 

{ 
  if(digitalRead(button) == HIGH && flag == 0)  //если кнопка нажата    
                                          // и перемення flag равна 0 , то ... 
  { 
    digitalWrite(led, !digitalRead(led)); 
    flag = 1; 
      //это нужно для того что бы с каждым нажатием кнопки 
      //происходило только одно действие 
      // плюс защита от "дребезга"  100% 
  } 
  if(digitalRead(button)  == LOW && flag == 1) //если кнопка НЕ нажата 
                                        //и переменная flag равна - 1 ,то ... 
  { 
           
    flag = 0; //обнуляем переменную flag 
  } 
}
