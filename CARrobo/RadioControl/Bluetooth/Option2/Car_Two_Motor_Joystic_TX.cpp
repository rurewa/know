// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
// Робот с использованием L298P Motor Shield от Keyes управляемый Bluetooth
// и джойстиком
// Код передатчика
// V 1.0
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- //
int xAxis, yAxis;
void setup() {
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
  xAxis = analogRead(A0); // Read Joysticks X-axis
  yAxis = analogRead(A1); // Read Joysticks Y-axis
  
  // Send the values via the serial port to the slave HC-05 Bluetooth device
  Serial.write(xAxis/4); // Dividing by 4 for converting from 0 - 1023 to 0 - 256, (1 byte) range
  Serial.write(yAxis/4);
  delay(20);
}
