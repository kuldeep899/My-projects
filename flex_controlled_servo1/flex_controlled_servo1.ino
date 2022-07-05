#include <Servo.h> 
Servo myServo;
const int flexPin = A0; 
void setup() { 
Serial.begin(9600);
myServo.attach(3);
myServo.write(90);
}
void loop() { 
int flexposition;
int servoposition;
flexposition=analogRead(flexPin);
servoposition=map(flexposition, 1, 1023, 0, 180);
servoposition=constrain(servoposition, 0, 180);
myServo.write(servoposition);
Serial.print("sensor: ");
Serial.print(flexposition);
Serial.print(", ");
Serial.print("myservo: ");
Serial.println(servoposition);
delay(300);
}
