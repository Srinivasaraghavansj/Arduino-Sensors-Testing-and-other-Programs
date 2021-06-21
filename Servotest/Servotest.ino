
#include <Servo.h>
const int g=9;
Servo gr;

void setup() {
  gr.attach(g);

}

void loop() {
gr.write(90);


}
