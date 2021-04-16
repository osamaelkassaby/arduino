#include <LiquidCrystal.h>
int i = 0;
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Loding ....");

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.home();
  lcd.setCursor(0,1);
  i++;
 // lcd.print("Loning .....");
  delay(400);
 if(i == 20){
  lcd.print("welcome .");
  lcd.setCursor(0,0);
  lcd.print("osamaelkassaby");

  }
  
  

}
