#include<Servo.h>

Servo servo1,servo2;

int joyX=0,joyY=1,joyval;

void setup() {
servo1.attach(3);
servo2.attach(5);
}

void loop() {

joyval=analogRead(joyX);
joyval=map(joyval,0,1023,0,180);
servo1.write(joyval);

joyval=analogRead(joyY);
joyval=map(joyval,0,1023,0,180);
servo2.write(joyval);

delay(15);
}
