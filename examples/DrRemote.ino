#include <PS3ActionMonitor.h>
void setup() {

  Serial.begin(115200);
  setId("rmESP");//MAX 6 chars This is its own id
 
  PEsp.init("rmpik"); 
  funEsp.init("pmESP"); 
  DrESP.init("Drbase");
  initPs3("22:22:22:22:22:22");
}

void loop() {
  // put your main code here, to run repeatedly:
}