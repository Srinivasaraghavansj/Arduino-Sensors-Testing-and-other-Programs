#include <Servo.h>

void setup() {
  // put your setup code here, to run once:
  Servo myServo;
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
myServo.write(90);
}
