#include <PS3ActionMonitor.h>
void pressed() {
  Serial.println("Joystick Pressed");
}
void released() {
  Serial.println("Joystick released");
}
void xChange(int x) {
  Serial.println("Joystick X Changed : " + String(x));
}
void yChange(int y) {
  Serial.println("Joystick Y Changed : " + String(y));
}
//-------------------------------------------------
void trianglePressed()
{
  Serial.println("trianglePressed");
}

void triangleAnalog(int x) {
  Serial.println("triangle Changed : " + String(x));
}

void triangleReleased()
{
  Serial.println("triangleReleased");
}
//-------------------------------------------------
void l1Pressed()
{
  Serial.println("l1Pressed");
}

void l1Analog(int x) {
  Serial.println("l1 Changed : " + String(x));
}

void l1Released()
{
  Serial.println("l1Released");
}
//-------------------------------------------------
void selectPressed()
{
  Serial.println("selectPressed");
}

void selectReleased()
{
  Serial.println("selectReleased");
}
void setup() {

  Serial.begin(115200);

  initPs3("11:11:11:11:11:11");
  rightJoystick.attachXChange(xChange);//calling functions
  rightJoystick.attachYChange(yChange);//calling functions
  rightJoystick.attachPress(pressed);//calling functions
  rightJoystick.attachRelease(released);//calling functions

  triangle.attachPress(trianglePressed);//calling functions
  triangle.attachRelease(triangleReleased);//calling functions
  triangle.attachAnalogChange(triangleAnalog);

  l1.attachPress(l1Pressed);//calling functions
  l1.attachRelease(l1Released);//calling functions
  l1.attachAnalogChange(l1Analog);

  select.attachPress(selectPressed);//calling functions
  select.attachRelease(selectReleased);//calling functions
}

void loop() {
  // put your main code here, to run repeatedly:

}