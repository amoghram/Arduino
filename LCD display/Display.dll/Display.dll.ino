#include <LiquidCrystal.h>


LiquidCrystal lcd(1,2,4,5,6,7);

void setup() {
  lcd.begin(16,2);

}

void loop() {
  
  lcd.print("Kossomk!!");
  delay(3000); 

  lcd.setCursor(2,1);
  lcd.print("Ya Khaneeth");
  delay(3000);

  lcd.clear();

  lcd.blink();

  delay(4000);

}
