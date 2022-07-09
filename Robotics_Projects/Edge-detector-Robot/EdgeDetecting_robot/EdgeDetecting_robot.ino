int lm1=4; //left motor output 1
int lm2=5; //left motor output 2
int rm1=2;  //right motor output 1
int rm2=1;  //right motor output 2
int sl=8;    //sensor 1 input (left)
int sr=7;    //sensor 2 input (right)
int SlV=0;
int SrV=0;
int enA=6;    //enable left motor
int enB=3;    //enable right motor
int led=A0;
void setup()
{
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT);
 pinMode(enA,OUTPUT);
 pinMode(enB,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(sl,INPUT);
 pinMode(sr,INPUT);
sTOP();
}

void loop()
{
  digitalWrite(enA,1);
digitalWrite(enB,1);

 SlV=digitalRead(sl);
 SrV=digitalRead(sr);
 if(SrV==LOW && SlV== LOW)
 {
   digitalWrite(led,LOW);
  ForWard();
   }
   if(SrV==HIGH && SlV== HIGH)
 {
   digitalWrite(led,HIGH);
  BackWard();
  delay(400);
  Right();
  delay(550);
  ForWard();
  delay(200);
   }
    if(SrV==LOW && SlV== HIGH)
 {
  digitalWrite(led,HIGH);
  BackWard();
  delay(400);
  Right();
  delay(550);
  ForWard();
  delay(200);
   }
    if(SrV==HIGH && SlV== LOW)
 {
  digitalWrite(led,HIGH);
  BackWard();
  delay(400);
  Left();
  delay(550);
  ForWard();
  delay(200);
   }
}
void ForWard()
 {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
 } 
 void BackWard()
 {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
 }
 void Left()
 {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
 } 
 void Right()
 {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
 }  
   void sTOP()
 {
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
 } 
