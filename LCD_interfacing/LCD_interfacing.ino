#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7,8,9,10,11,12);  //RS,RW,E,DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7
void setup() {
  lcd.begin(20,4);  //cols,rows
  lcd.setCursor(7,0);
  lcd.print("WELOME");
  lcd.setCursor(9,1);  //col,row
  lcd.print("TO");
  lcd.setCursor(0,2);
  lcd.print("IOT & EMBEDDED SYSTEMS");

}

void loop() {
  // put your main code here, to run repeatedly:

}
