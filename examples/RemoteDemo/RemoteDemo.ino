
#include <PS3ActionMonitor.h>

void setup() {

  Serial.begin(115200);

        setId("abc12");//MAX 6 chars This is its own id
         myEsp.init("def12");
  initPs3("66:66:66:66:66:66");
}

void loop() {
  // put your main code here, to run repeatedly:
//  myEsp.println("Hello");
//  delay(100);
}
