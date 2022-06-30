#include <Servo.h>  //include servo.h library
Servo myservo;

int pos = 0;
boolean fire = false;

#define Left_s 10      // left sensor
#define Right_s 12    // right sensor
#define Forward_s 11   //front sensor

#define RM1 8       // left motor
#define RM2 7       // left motor
#define enL 3
#define LM3 4       // right motor
#define LM4 2       // right motor
#define enR 9
#define pump 13
void setup() {
  pinMode(Left_s, INPUT_PULLUP);
  pinMode(Right_s, INPUT_PULLUP);
  pinMode(Forward_s, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int L = digitalRead(Left_s);
  Serial.print(L);
  Serial.print(",");
  int F = digitalRead(Forward_s);
  Serial.print(F);
  Serial.print(",");
  int R = digitalRead(Right_s);
  Serial.println(R);
}
