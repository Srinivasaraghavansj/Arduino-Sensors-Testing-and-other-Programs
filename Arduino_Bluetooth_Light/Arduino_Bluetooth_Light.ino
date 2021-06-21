char a ='0';
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() {
if(Serial.available() == 1){
  a = Serial.read();
}
if(a == '1'){
digitalWrite(LED_BUILTIN,HIGH);
digitalWrite(5,HIGH);
}
if(a == '0'){
digitalWrite(LED_BUILTIN,LOW);
digitalWrite(5,LOW);
}
}
