#include<Servo.h>

Servo servo1,servo2;

const int s1pin=3,s2pin=5,modechange=9,modeled=10;//modechanges from auto to manual pin
int joyX=0,joyY=1,joyval,s1max=180,s1min=0,s2max=180,s2min=0,s1imin=0,s1imax=180,s2imin=0,s2imax=180;
boolean mode=true; //0 for automatic, 1 for manual

void setup() {
servo1.attach(s1pin);
servo2.attach(s2pin);
pinMode(modechange,INPUT);
pinMode(modeled,OUTPUT);
}



void loop() {
  
if(digitalRead(modechange)== HIGH)
{
  mode=!mode;
  digitalWrite(modeled,HIGH);
  delay(2000);
  digitalWrite(modeled,LOW);
  }



if(mode==true)
{
servo1.write(s1imin);
delay(100);
servo2.write(s2imin);
delay(100);
servo1.write(s1imax);
delay(100);
servo2.write(s2imax);
delay(100);
servo1.detach();
servo2.detach();  
}


 
if(mode==false)
{
joyval=analogRead(joyX);
joyval=map(joyval,0,1023,s1min,s1max);
servo1.write(joyval);

joyval=analogRead(joyY);
joyval=map(joyval,0,1023,s2min,s2max);
servo2.write(joyval);

delay(15);
}
}
