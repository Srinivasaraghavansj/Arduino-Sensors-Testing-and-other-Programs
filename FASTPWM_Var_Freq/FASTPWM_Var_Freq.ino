String a = "";
int b = 0;
void setup() {
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
TCCR1A = 0;
TCCR1B = 0;
TCCR1A |= (1<<WGM11) | (1<<COM1A1) | (1<<COM1B1);
TCCR1B |= (1<<CS10) | (1<<WGM13) | (1<<WGM12);
}

void loop() {
while(Serial.available()) {
a= Serial.readString();
}
b = map(a.toInt(),0,100,0,255);
ICR1 = b;
OCR1A = 50;
}
