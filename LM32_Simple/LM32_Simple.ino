
#define LM32PIN A0
void setup(){
    Serial.begin(9600);
    pinMode(LM32PIN, INPUT);
    delay(10);
}
void loop(){

while(true){

      float temp2 = (float)analogRead(LM32PIN)/1023*5*0.864*100;
  
            Serial.println("Temp: " + (String)temp2); 
            delay(1000);
}
}
