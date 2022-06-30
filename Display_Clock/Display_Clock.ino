#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7); //RS,E,DB4,DB5,DB6,DB7
void setup() {
  lcd.begin(20,4);
//This need some modificartion 
//in the next version we will get accurate time.
}
uint8_t ss = 0, mm = 0, hh = 0;
void loop() {
  //Time
  ss++;
  if(ss==60){
    ss=0;
    mm++;
    if(mm==60){
      mm=0;
      hh++;
      if(hh==24){
        hh=0;
      }
    }
  }
  //LCD Display
  lcd.setCursor(0,0);
  lcd.print("DIGITAL CLOCK");
  lcd.setCursor(0,1);
  if(hh<10){
    lcd.print(0);
  }
  lcd.print(hh);
  lcd.print(":");
  if(mm<10){
    lcd.print(0);
  }
  lcd.print(mm);
  lcd.print(":");
  if(ss<10){
    lcd.print(0);
  }
  lcd.print(ss);
  delay(800);
  
}
