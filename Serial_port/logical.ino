#include <Arduino.h>

void setup() 
{
    Serial.begin(9600);
    Serial.print("Вы хотите продолжить операцию (1 - да, 0 - нет)?\n\n");
}
void loop() 
{
    if (Serial.available() > 0)
    {
        bool variable = Serial.read();
        
        if (variable == true) // Если введена 1
        {
            Serial.print("Вы выбрали Да!\n..........\n\n");
        }
        else // Если введён 0
        {
            if (variable == false)
            {
                Serial.print("До свидания! \n\n");
            }    
        }
    }    
}
