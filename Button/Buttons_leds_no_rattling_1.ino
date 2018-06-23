// Buttons leds no rattling 1
// V 1.0
const int led1 = 9;
const int inPin1 = 7;
int button1 = 0;

void setup()
{
    pinMode(led1, OUTPUT);
}

void loop()
{
    button1 = digitalRead(inPin1);
    digitalWrite(led1, button1);
}
