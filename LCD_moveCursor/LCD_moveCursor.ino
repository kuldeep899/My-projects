#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);  //RS,RW,E,DB4,DB5,DB6,DB7
byte arrow[8] = {B00100,B01110,B11111,B00100,B00100,B00100,B00100,B00100,};
void setup() {
  lcd.createChar(7,arrow);  //num,data
    lcd.begin(20,4);          //cols,rows

}

void loop() {
  for(int i=0;i<=19;i++)
  {
    lcd.setCursor(i,1);
    lcd.write(byte(7));
    delay(500);
    lcd.clear();
  }

}
