
#include <Servo.h>  //include servo.h library
Servo myservo;

int pos = 0;
boolean fire = false;

#define Left 10      // left sensor
#define Right 12    // right sensor
#define Forward 11   //front sensor

#define LM1 2       // left motor
#define LM2 4       // left motor
#define enL 3
#define RM1 7       // right motor
#define RM2 8       // right motor
#define enR 9
#define pump 13

void setup()
{
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(enR, OUTPUT);
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

  digitalWrite(pump, HIGH);
  delay(500);

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
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
  }

  else if (digitalRead(Left) == 0)
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
  }

  else if (digitalRead(Right) == 0)
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  }

  delay(300);//change this value to increase the distance

  while (fire == true)
  {
    put_off_fire();
  }
}
