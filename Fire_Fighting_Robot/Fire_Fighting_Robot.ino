
#include <Servo.h>  //include servo.h library
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

#define Right  10       // right sensor
#define Forward 12     //forward sensor
#define Left  9      // left sensor

void setup()
{
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);

  myservo.attach(11);
  myservo.write(90);
}

void put_off_fire()
{
  delay (100);

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, HIGH);

  digitalWrite(pump, HIGH);
  delay(100);

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
  analogWrite(enR, 200);
  analogWrite(enL, 200);
  myservo.write(90); //Sweep_Servo();

  if (digitalRead(Left) == 1 && digitalRead(Right) == 1 && digitalRead(Forward) == 1)
  {

    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
  }

  else if (digitalRead(Forward) == 0)
  {
    analogWrite(enR, 200);
    analogWrite(enL, 200);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
  }

  else if (digitalRead(Left) == 0)
  {
    analogWrite(enR, 200);
    analogWrite(enL, 200);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
  }

  else if (digitalRead(Right) == 0)
  {
    analogWrite(enR, 200);
    analogWrite(enL, 200);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  delay(300);

  while (fire == true)
  {
    put_off_fire();
    delay(250);
  }
}
