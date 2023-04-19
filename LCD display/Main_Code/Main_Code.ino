#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
const int buttonPin = 10;    // the number of the button pin
char str[100];
int lcdState = LOW;        
int previousButtonState = LOW;
char message[] = "The Coolest Mother F**ker!!";
int messageLength = sizeof(message);

void setup() {    // initialize the LED pin as an output
  lcd.begin(16,2);
  pinMode(buttonPin, INPUT);    // initialize the button pin as an input
  Serial.begin(9600);
  lcd.print("Congradulations!");

}

void loop() {
  int buttonState = digitalRead(buttonPin);     // read the state of the button

  if (buttonState == HIGH && previousButtonState == LOW) {        // if the button is pressed
    lcdState = !lcdState;
    sprintf(str, "state: %d\n", lcdState);    
    Serial.print(str);
    if(lcdState == HIGH){
      lcd.clear();
      delay(50);
      lcd.setCursor(0, 0);
      lcd.print("Master.");
      delay(500);
      lcd.setCursor(3,1);
      lcd.print("Zaki Patel");
    }
    else{
      for (int i = 0; i < messageLength; i++) {
        lcd.clear(); // Clear the display
        lcd.setCursor(0,0); // Set the cursor to the first column of the first row
        lcd.print(&message[i]); // Print the current portion of the message
        delay(500); // Delay to slow down the scrolling speed
      }
    }
  }
  //sprintf(str, "state: %d\n", buttonState);         
  //Serial.print(str); 
  previousButtonState = buttonState;
  delay(100); 

}
