

//This version contains only 2 switches, one for the door sensing and another one for the Mouse sensing. It also has a servo which triggers the door

#include <Servo.h>
const int tr=9,doorsw=5,mousesw=3;
Servo trig;

void setup() {
  pinMode(doorsw, INPUT);
  pinMode(mousesw, INPUT);
  Serial.begin(9600);
  trig.detach();
}

void loop() {

  trig.detach();
  if(digitalRead(doorsw)==0 && digitalRead(mousesw)==1)
  {
    trig.attach(tr);
    trig.write(90);
    delay(1500);
  }

  if(digitalRead(doorsw)==HIGH)
  {
   
    
  }
Serial.println("Door= "+(String)digitalRead(doorsw)+"MousePresent= "+(String)digitalRead(mousesw));
}
