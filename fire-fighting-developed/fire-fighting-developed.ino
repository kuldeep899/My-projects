#include <Servo.h>
Servo myservo;
 
int pos = 0;    
boolean fire = false;

#define Left_S 10       // left sensor
#define Right_S 12      // right sensor
#define Forward_S 11    //forward sensor
 
#define LM1 4       // left motor
#define LM2 2       // left motor
#define enL 3
#define RM1 7       // right motor
#define RM2 8       // right motor
#define enR 9
#define pump 13
 
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
  
  digitalWrite(pump,LOW);
  myservo.write(90);
  
  fire=false;
}
 
void loop()
{
   analogWrite(enL,155);
   analogWrite(enR,155);
   myservo.write(90); //Sweep_Servo();  
 
    if (digitalRead(Left_S) ==1 && digitalRead(Right_S)==1 && digitalRead(Forward_S) ==1) //If Fire not detected all sensors are zero
    {
    //Do not move the robot
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
    }
    
    else if (digitalRead(Forward_S) ==0) //If Fire is straight ahead
    {
    //Move the robot forward
    analogWrite(enL,155);
    analogWrite(enR,155);
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
    }
    
    else if (digitalRead(Left_S) ==0) //If Fire is to the left
    {
    //Move the robot left
    analogWrite(enL,155);
    analogWrite(enR,155);
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    }
    
    else if (digitalRead(Right_S) ==0) //If Fire is to the right
    {
    //Move the robot right
    analogWrite(enL,155);
    analogWrite(enR,155);
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
