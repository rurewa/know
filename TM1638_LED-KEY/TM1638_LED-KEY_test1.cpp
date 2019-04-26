/* Подключение модуля: 
 *  8pin - DIO(data) 
 *  9pin - CLK(clock)
 *  10pin - STB(strobe)
 */
#include <TM1638.h>
TM1638 module(8, 9, 10);
unsigned long a = 1;
 
void setup()
{
}
 
void loop()
{
    for (a=1; a<=100; a++)
        {
            module.setDisplayToDecNumber(a,0,false);
            delay(100);
        }
    module.setDisplayToString("Complete");
    delay(5000);
}
