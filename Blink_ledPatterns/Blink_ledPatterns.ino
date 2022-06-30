
void setup() {
  for(int i=4;i<12;i++)
  {
    pinMode(i,OUTPUT);
  }

}

void loop() {
  for(int j=4;j<12;j++)
  {
    digitalWrite(j,1);
    delay(20);
    digitalWrite(j,0);
    //delay(20);
  }

}
