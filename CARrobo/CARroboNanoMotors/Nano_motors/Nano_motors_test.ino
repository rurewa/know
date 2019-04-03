// Test driver motors for Nano motors board
// V 1.0
const int ENA = 10;
const int in2 = 12;
const int ENB = 9;
const int in3 = 11;

void setup() 
{ 
    pinMode(in2, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(in3, OUTPUT);
} 
  
void loop() 
{ 
    digitalWrite(in3, LOW);
    analogWrite(ENB, 255);
    digitalWrite(in2, LOW);
    analogWrite(ENA, 255); 
    delay(2500);
    analogWrite(ENB, 0);
    analogWrite(ENA, 0);
    delay(2500);
    digitalWrite(in3, HIGH);
    analogWrite(ENB, 255);
    digitalWrite(in2, HIGH);
    analogWrite(ENA, 255); 
    delay(2500);
    analogWrite(ENB, 0);
    analogWrite(ENA, 0);
    delay(2500);   
}
