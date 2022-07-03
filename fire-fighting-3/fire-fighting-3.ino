#include <Servo.h>
Servo myservo;

int pos = 0;
boolean fire = false;

#define RM1 1       // left motor
#define RM2 2       // left motor
#define enR 3
#define LM1 4       // right motor
#define LM2 5       // right motor
#define enL 6
#define pump 7      // water pump motor

#define Right_S 8       // right sensor
#define Forward_S 9     //forward sensor
#define Left_S  10      // left sensor

void setup()
{
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);

  myservo.attach(6);
  myservo.write(90);
}

void put_off_fire()
{
  delay (500);

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, HIGH);

  digitalWrite(pump, HIGH); delay(500);

  for (pos = 50; pos <= 130; pos += 1) {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 130; pos >= 50; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }

  digitalWrite(pump, LOW);
  myservo.write(90);

  fire = false;
}

void loop()
{
  analogWrite(enL, 255);
  analogWrite(enR, 255);
  myservo.write(90); //Sweep_Servo();

  if (digitalRead(Left_S) == 1 && digitalRead(Right_S) == 1 && digitalRead(Forward_S) == 1) //If Fire not detected all sensors are zero
  {
    //Do not move the robot
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
  }

  else if (digitalRead(Forward_S) == 0 && digitalRead(Right_S) == 0 && digitalRead(Left_S) == 0) //If Fire is straight ahead
  {
    //Move the robot forward
    analogWrite(enL, 255);
    analogWrite(enR, 255);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
  }

  else if (digitalRead(Left_S) == 0 && digitalRead(Forward_S) == 1 && digitalRead(Forward_S) == 1)      //If Fire is to the left
  {
    //Move the robot left
    analogWrite(enL, 255);
    analogWrite(enR, 255);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  else if (digitalRead(Left_S) == 0 && digitalRead(Forward_S) == 0 && digitalRead(Right_S) == 1) //If Fire is to the right
  {
    //Move the robot right
    analogWrite(enL, 255);
    analogWrite(enR, 255);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
  }

  delay(300); //Slow down the speed of robot

  while (!digitalRead(Forward_S))
  {
    put_off_fire();
  }
}
