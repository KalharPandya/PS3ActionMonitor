
#include <Ps3Controller.h>

#include <PS3ActionMonitor.h>

listener lPress(&Ps3Updater.Ps3_event_button_down_l3);
listener lRelease(&Ps3Updater.Ps3_event_button_up_l3);
listener lx(&Ps3Updater.Ps3_data_analog_stick_lx);
listener ly(&Ps3Updater.Ps3_data_analog_stick_ly);
joystick lj(lPress,lRelease,lx,ly);
void pressed(){
  Serial.println("Joystick Pressed");
}
void released(){
  Serial.println("Joystick released");
}
void xChange(int x){
  Serial.println("Joystick X Changed : "+String(x));
}
void yChange(int y){
  Serial.println("Joystick Y Changed : "+String(y));
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  initPs3("33:33:33:33:33:33");
  lj.attachXChange(xChange);
  lj.attachYChange(yChange);
  lj.attachPress(pressed);
  lj.attachRelease(released);
  Serial.println("Ready.");
  
//  Ps3.attach(notify);
}

void loop() {
  // put your main code here, to run repeatedly:

}