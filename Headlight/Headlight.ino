const int relayoff=5,flash=6;
void setup() {
pinMode(relayoff,OUTPUT);
pinMode(flash,OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(relayoff,HIGH);
digitalWrite(flash,HIGH);
Serial.println("BLINK");
delay(780);
digitalWrite(flash, LOW);
Serial.println("OFF");
delay(400);
}
