#include <LiquidCrystal.h>

int potPin = A0;
int R2 = 10000;

int contrastPin = 10;  // Define the pin used to adjust the contrast
int contrastValue = 90;  // Initialize the contrast value to 128

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(contrastPin, OUTPUT);  // Set the contrast pin as an output
  analogWrite(contrastPin, contrastValue);  // Set the initial contrast
  lcd.print("Kossomk!!");
}

void loop() {
  int sensorValue = analogRead(potPin);
  float voltage = (sensorValue * 5.0) / 1023;
  float resistance = R2 * ((5.0 / voltage) - 1.0);
  
  analogWrite(contrastPin, contrastValue);

  //Serial.println(contrastValue);
  //Serial.print("Potentiometer resistance: ");
  //Serial.print(sensorValue);
  //Serial.println(" ohms");

  delay(1000); // add a delay to avoid flooding the serial port
  
  //delay(3000);

  /*lcd.setCursor(2,1);
  lcd.print("Ya Khaneeth");
  delay(3000);
  lcd.clear();
  lcd.blink();
  delay(4000);*/

}
