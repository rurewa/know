// Buttons leds no rattling
// V 1.0
const int led1 = 9;
const int led2 = 10;
const int inPin1 = 7;
const int inPin2 = 8;
int button1 = 0;
int button2 = 0;

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop()
{
    button1 = digitalRead(inPin1);
    button2 = digitalRead(inPin2);
    digitalWrite(led1, button1);
    digitalWrite(led2, button2);
}
