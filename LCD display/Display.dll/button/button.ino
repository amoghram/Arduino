#include <LiquidCrystal.h>

LiquidCrystal lcd(1,2,4,5,6,7);
int buttonPin = 10;
int buttonNew;
int buttonOld = 1;
int td = 1000;
char buf[80];
int counter = 0;
char Txt[10];

void setup() {
  lcd.begin(16,2);
  pinMode(buttonPin, INPUT);
  pinMode(buttonNew, INPUT);

  Serial.begin(9600);
}

void loop() {
  buttonNew = digitalRead(buttonPin); 

  sprintf(buf, "Old Button: %d\n", buttonOld);
  Serial.print(buf);
  sprintf(buf, "New Button: %d\n", buttonNew);
  Serial.println(buf);
  Serial.println(Txt);

  if (buttonOld == 0 && buttonNew == 1) {
    if (counter % 2 == 0){
      lcd.clear();
      delay(1000);
      lcd.print("ButtonPressed!");
      delay(2000);
      Serial.print("Button pressed!\n");
      sprintf(Txt,"Text = ON");
      lcd.clear();
      delay(1000);
      lcd.print("Kossomk!!");
      delay(3000); 
      lcd.setCursor(2,1);
      lcd.print("Ya Khaneeth");
      
    }
    else {      
      lcd.clear();
      delay(1000);
      sprintf(Txt,"Text = OFF");
    }
    counter++;
  }
  
  buttonOld = buttonNew;
  delay(500);

  Serial.print("--------------------\n");
}
