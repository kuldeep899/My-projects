#define RM1 1       // left motor
#define RM2 2       // left motor
#define enR 3
#define LM1 4       // right motor
#define LM2 5       // right motor
#define enL 6
#define pump 7      // water pump motor

#define Right_S 10       // right sensor
#define Forward_S 12     //forward sensor
#define Left_S  9      // left sensor
void setup() {
  pinMode(Left_S, INPUT);
  pinMode(Right_S, INPUT);
  pinMode(Forward_S, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Left Sensor = ");
  int L = digitalRead(Left_S);
  Serial.print(L);
  Serial.print(", ");
  Serial.print("Forward Sensor = ");
  int F = digitalRead(Forward_S);
  Serial.print(F);
  Serial.print(", ");
  Serial.print("Right Sensor = ");
  int R = digitalRead(Right_S);
  Serial.println(R);
}
