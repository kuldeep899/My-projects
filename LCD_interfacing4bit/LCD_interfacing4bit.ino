#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);  //RS,E,DB4,DB5,DB6,DB7
void setup() {
  lcd.begin(20,4);  //cols,rows
  lcd.setCursor(7,0);
  lcd.print("WELOME");
  lcd.setCursor(9,1);  //col,row
  lcd.print("TO");
  lcd.setCursor(0,2);
  lcd.print("IOT & EMBEDDED SYSTE");

}

void loop() {
  // put your main code here, to run repeatedly:

}
