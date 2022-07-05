#include <Servo.h>  // header for controller servo
Servo servo;        //keeping name of servo SERVO itself
int pos = 0;
void setup()
{
  pinMode(3, OUTPUT); // PWM output to servo
  servo.attach(3);// telling where signal pin of servo attached(must be a PWM pin)
  Serial.begin(9600);
}
void loop()
{
  for (int i = 0; i <= 90; i++) {
    servo.write(i);
    Serial.println(i);
    delay(20);
  }
  for (int i = 90; i >= 0; i--) {
    servo.write(i);
    Serial.println(i);
    delay(20);
  }
}
