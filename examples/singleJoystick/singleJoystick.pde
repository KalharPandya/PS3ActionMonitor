
#include <Ps3Controller.h>

#include <PS3ActionMonitor.h>

listener lPress(&Ps3Updater.Ps3_event_button_down_l3);
listener lRelease(&Ps3Updater.Ps3_event_button_up_l3);
listener lx(&Ps3Updater.Ps3_data_analog_stick_lx);
listener ly(&Ps3Updater.Ps3_data_analog_stick_ly);
listener crossP(&Ps3Updater.Ps3_event_button_down_cross);
listener crossR(&Ps3Updater.Ps3_event_button_up_cross);

listener upP(&Ps3Updater.Ps3_event_button_down_up);
listener upR(&Ps3Updater.Ps3_event_button_up_up);
joystick lj(lPress,lRelease,lx,ly);
button cross(crossP,crossR),up(upP,upR);
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
  lj.attachXChange(xChange);
  lj.attachYChange(yChange);
  lj.attachPress(pressed);
  lj.attachRelease(released);
  cross.attachBtnPress(crossPressed);
  cross.attachBtnRelease(crossReleased);
  up.attachBtnPress(upPressed);
  up.attachBtnRelease(upReleased);
  
  Serial.println("Ready.");
  
//  Ps3.attach(notify);
}

void loop() {
  // put your main code here, to run repeatedly:

}