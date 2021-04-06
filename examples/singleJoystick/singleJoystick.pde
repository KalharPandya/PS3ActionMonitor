
#include <Ps3Controller.h>

#include <PS3ActionMonitor.h>

listener lPress(&Ps3Updater.Ps3_event_button_down_l3);
listener lRelease(&Ps3Updater.Ps3_event_button_up_l3);
listener lx(&Ps3Updater.Ps3_data_analog_stick_lx);
listener ly(&Ps3Updater.Ps3_data_analog_stick_ly);//Creating object of listener and passing address of joysticks y axis
listener crossP(&Ps3Updater.Ps3_event_button_down_cross);//Creating object of listener and passing address of button
listener crossR(&Ps3Updater.Ps3_event_button_up_cross);

listener upP(&Ps3Updater.Ps3_event_button_down_up);
listener upR(&Ps3Updater.Ps3_event_button_up_up);
joystick lj(lPress,lRelease,lx,ly);//passing listener object into joystick
button cross(crossP,crossR),up(upP,upR);//passing listener object into button
void crossPressed()
{
  Serial.println("CrossPressed");
}
void crossReleased()
{
  Serial.println("CrossReleased");
}
void upPressed()
{
  Serial.println("upPressed");
}
void upReleased()
{
  Serial.println("upReleased");
}
void pressed(){
  Serial.println("Joystick Pressed");
}
void released(){
  Serial.println("Joystick released");
}
void xChange(int x){
 // Serial.println("Joystick X Changed : "+String(x));
}
void yChange(int y){
 // Serial.println("Joystick Y Changed : "+String(y));
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  initPs3("11:11:11:11:11:11");
  lj.attachXChange(xChange);//calling functions
  lj.attachYChange(yChange);//calling functions
  lj.attachPress(pressed);//calling functions
  lj.attachRelease(released);//calling functions
  cross.attachBtnPress(crossPressed);//calling functions
  cross.attachBtnRelease(crossReleased);//calling functions
  up.attachBtnPress(upPressed);//calling functions
  up.attachBtnRelease(upReleased);//calling functions
  Serial.println("Ready.");
}

void loop() {
  // put your main code here, to run repeatedly:

}