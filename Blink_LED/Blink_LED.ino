
// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
int d;
// defines variables
long duration;
int distance;
void setup() {
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
analogWrite(10,0);
analogWrite(11,0);

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.033/2;
d=distance;

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

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
