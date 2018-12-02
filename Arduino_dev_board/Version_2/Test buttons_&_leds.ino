// Arduino_dev_board v 2.0
// V 1.1
// Test buttons & leds

void setup()
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(8,digitalRead(13)); // led 8, button 13
  digitalWrite(9,digitalRead(16)); // led 9, button 16
  digitalWrite(10,digitalRead(17)); // led10, button 17
  digitalWrite(11,digitalRead(17)); // led 11
  digitalWrite(12,digitalRead(17)); // led 12
}
