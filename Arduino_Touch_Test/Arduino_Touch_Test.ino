void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(A0,INPUT_PULLUP);
pinMode(LED_BUILTIN,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println((String)analogRead(A0));
if(analogRead(A0) < 1019)
digitalWrite(LED_BUILTIN,HIGH);
else
digitalWrite(LED_BUILTIN,LOW);
delay(30);
}
