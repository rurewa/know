// Управление светодиодом с кнопки с таймером (циклично). Без delay.

long previousMillis = 0; // переменная типа long
int val = 0; // для хранения значения

void setup() { 
  pinMode(13, OUTPUT);
} 

void loop() { 
  if(digitalRead(2) == HIGH) { 
    if (millis() -previousMillis >500) { 
        previousMillis = millis();     
        val++; 
      } 
  } 
  else { 
    val=0;
  } 
  if(val>=5) { 
    digitalWrite(13,!digitalRead(13));//инвертируем состояние пина 
    val=0; 
    } 
}
