/*
Version = 1.00
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int buttonPin = 10; // the number of the button pin
char str[100];
int lcdState = LOW;
int previousButtonState = LOW;
char message[] = "The Coolest MotherFucker!!";
int messageLength = sizeof(message);
unsigned long buttonPressTime = 0;
const unsigned long longPressDuration = 2000; // 2 seconds for long press
const unsigned long debounceDelay = 50;       // debounce delay in milliseconds

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT);
  lcd.print("Congratulations!");
}

void loop() {
  int buttonState = digitalRead(buttonPin);     // read the state of the button

  // Debounce the button
  if ((millis() - buttonPressTime) > debounceDelay) {
    if (buttonState == HIGH && previousButtonState == LOW) { // Button pressed
      buttonPressTime = millis();
    }

    if (buttonState == LOW && previousButtonState == HIGH) { // Button released
      unsigned long buttonReleaseTime = millis();
      unsigned long buttonPressDuration = buttonReleaseTime - buttonPressTime;

      if (buttonPressDuration >= longPressDuration) {
        // Display pattern for "Zaki is happy!!" for a long press
        displayHappyPattern();
      } else {
        // Toggle between scrolling message and "Master. Zaki Patel" for a short press
        lcdState = !lcdState;
        if (lcdState == HIGH) {
          lcd.clear();
          delay(50);
          lcd.setCursor(0, 0);
          lcd.print("Master.");
          delay(500);
          lcd.setCursor(3, 1);
          lcd.print("Zaki Patel");
        } else {
          scrollMessage();  
        }
      }
    }
  }
  previousButtonState = buttonState;
}

void displayHappyPattern() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Zaki is Gay!!");
  delay(500);  // Pause before starting the pattern

  // Create a flashing effect
  for (int i = 0; i < 5; i++) {
    lcd.noDisplay();  // Turn off the display
    delay(300);
    lcd.display();    // Turn on the display
    delay(300);
  }

  // Display a running light pattern
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }

  // Reset display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Zaki is Gay!!");
}

void scrollMessage() {
  for (int i = 0; i < messageLength; i++) {
    lcd.clear(); // Clear the display
    lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
    lcd.print(&message[i]); // Print the current portion of the message
    delay(500); // Delay to slow down the scrolling speed
  }
}
