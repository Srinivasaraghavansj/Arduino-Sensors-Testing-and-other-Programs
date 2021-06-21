
const int trigPin = 8;
const int echoPin = 9                       ;

long duration;
int distance;
void setup() {
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600); 
}
void loop() {
analogWrite(10,0);
analogWrite(11,0);


digitalWrite(trigPin, LOW);
delayMicroseconds(2);


digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);


duration = pulseIn(echoPin, HIGH);


distance= duration*0.034/2;
int d=distance;

if(d>=3 && d<=10)
{
analogWrite(10,255);
}
if(d>=11 && d<=20)
{
analogWrite(11,200);
}
if(d>=21 && d<=40)
{
analogWrite(10,170);
}
if(d>40)
{
analogWrite(10,255);
analogWrite(11,255);
}


Serial.print("Distance: ");
Serial.println(distance);
}
