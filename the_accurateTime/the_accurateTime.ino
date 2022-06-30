#include <LiquidCrystal.h>
unsigned long start_time = 0;
LiquidCrystal lcd(2,3,4,5,6,7);
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("DIGITAL CLOCK");
  start_time = millis();
}
uint8_t ss = 0, mm = 0, hh = 0;
void loop() {
  if(millis()-start_time>=1000){
    start_time = millis();
    Serial.println(start_time);
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
  }
  //Display
  Serial.print("hh: ");
  Serial.print(hh);
  Serial.print("mm: ");
  Serial.print(mm);
  Serial.print("ss: ");
  Serial.println(ss);

  lcd.setCursor(0,1);
  if(hh<10){
    lcd.print('0');
  }
  lcd.print(hh);
  lcd.print(':');
  if(mm<10){
    lcd.print('0');
  }
  lcd.print(mm);
  lcd.print(':');
  if(ss<10){
    lcd.print('0');
  }
  lcd.print(ss);
}
