#include <RobotIRremoteInt.h>
#include <RobotIRremote.h>
#include <RobotIRremoteTools.h>

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}
