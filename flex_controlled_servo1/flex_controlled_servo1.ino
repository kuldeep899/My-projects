#include <Servo.h> 
Servo myServo;
const int flexPin = A0; 
void setup() { 
Serial.begin(9600);
myServo.attach(11);
}
void loop() { 
int flexposition;
int servoposition;
flexposition=analogRead(flexPin);
servoposition=map(flexposition, 800, 900, 0, 180);
servoposition=constrain(servoposition, 0, 180);
myServo.write(servoposition);
Serial.println("sensor");
Serial.println(flexposition);
Serial.println("myservo");
Serial.println(servoposition);
delay(80);
}