
#include<Servo.h>
const int trigpin1 = 2, trigpin2 = 3, trigpin3 = 4;
const int echopin1 = 5, echopin2 = 6, echopin3 = 7;                       ;
const int doorswitchpin = 9;
const int servopin = 10;
long duration1, duration2 = 0, duration3 = 0;
int distance1, distance2 = 0, distance3 = 0;

void runUsensor();
void trapcontrol();

Servo door;
void setup() {
  
pinMode(trigpin1, OUTPUT); 
pinMode(echopin1, INPUT); 
/*pinMode(trigpin2, OUTPUT); 
pinMode(echopin2, INPUT); 
pinMode(trigpin3, OUTPUT); 
pinMode(echopin3, INPUT); */
pinMode(doorswitchpin,INPUT_PULLUP);
door.detach();
Serial.begin(9600); 
}
void loop() {
runUsensor();
trapcontrol();

Serial.println("Distance: " + (String)distance1);
}

void runUsensor() {
  digitalWrite(trigpin1, LOW);
delayMicroseconds(2);
digitalWrite(trigpin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin1, LOW);
duration1 = pulseIn(echopin1, HIGH);
distance1= duration1*0.034/2;

/*delayMicroseconds(50);

digitalWrite(trigpin2, LOW);
delayMicroseconds(2);
digitalWrite(trigpin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin2, LOW);
duration2 = pulseIn(echopin2, HIGH);
distance2= duration2*0.034/2;

delayMicroseconds(50);

digitalWrite(trigpin3, LOW);
delayMicroseconds(2);
digitalWrite(trigpin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin3, LOW);
duration3 = pulseIn(echopin3, HIGH);
distance3= duration3*0.034/2;

delayMicroseconds(50);*/
}
void trapcontrol() {
  door.detach();
  if(distance1 < 10  && digitalRead(doorswitchpin) == HIGH) {
    door.attach(servopin);
    door.write(90);
    delay(200);
    door.detach();
  }
  
}

