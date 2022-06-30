void setup() {
  pinMode(2, INPUT_PULLUP); //input
  pinMode(13, 1); //output

}

void loop() {
  int  a = digitalRead(2);
           if (a == 0)
  {
    digitalWrite(13, 1);
  }
  else
    digitalWrite(13, 0);
}
