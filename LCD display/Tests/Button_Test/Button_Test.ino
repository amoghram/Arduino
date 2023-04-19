const int buttonPin = 10;    // the number of the button pin
char str[100];
int ledState = LOW;        
int previousButtonState = LOW;

void setup() {    // initialize the LED pin as an output
  pinMode(buttonPin, INPUT);    // initialize the button pin as an input
  Serial.begin(9600);

}

void loop() {
  int buttonState = digitalRead(buttonPin);     // read the state of the button

  if (buttonState == HIGH && previousButtonState == LOW) {        // if the button is pressed
    ledState = !ledState;
    sprintf(str, "state: %d\n", ledState);    
    Serial.print(str);
                          // debounce the button
  }
 // sprintf(str, "state: %d\n", buttonState);         
  //Serial.print(str); 
  previousButtonState = buttonState;
  delay(100); 

}
