#include <Servo.h>
#include <ezButton.h>

Servo servo;
int servoPin = 9;     // The pin connected to the servo
char buff[100];

ezButton toggleSwitch(6); 

void setup() {
  servo.attach(servoPin);     // Attaches the servo to the specified pin
  toggleSwitch.setDebounceTime(50);
  Serial.begin(9600);
}

void loop() {
  toggleSwitch.loop();
  
  int state = toggleSwitch.getState();
  sprintf(buff,"State: %d\n", state);
  Serial.print(buff);
  // If the servo is turned on, move it back and forth
  /*if (state) {
    // Move the servo from 0 to 180 degrees
    for (int angle = 0; angle <= 180; angle++) {
      servo.write(angle);  // Move the servo to the specified angle
      delay(15);           // Delay for smooth movement
    }

    // Move the servo from 180 to 0 degrees
    for (int angle = 180; angle >= 0; angle--) {
      servo.write(angle);  // Move the servo to the specified angle
      delay(15);           // Delay for smooth movement
    }
  }
}*/


  // If the servo is turned on, move it back and forth
  if (state) {
    // Move the servo from 0 to 180 degrees
    for (int angle = 0; angle <= 180; angle++) {
      // Check the state of the switch inside the loop
      toggleSwitch.loop();
      if (!toggleSwitch.getState()) {
        // If the switch is turned off, break the loop
        break;
      }
      
      servo.write(angle);  // Move the servo to the specified angle
      delay(15);           // Delay for smooth movement
    }
    
    // Check the state of the switch before moving the servo back
    toggleSwitch.loop();
    if (!toggleSwitch.getState()) {
      // If the switch is turned off, skip moving the servo back
      return;
    }
    
    // Move the servo from 180 to 0 degrees
    for (int angle = 180; angle >= 0; angle--) {
      // Check the state of the switch inside the loop
      toggleSwitch.loop();
      if (!toggleSwitch.getState()) {
        // If the switch is turned off, break the loop
        break;
      }
      
      servo.write(angle);  // Move the servo to the specified angle
      delay(15);           // Delay for smooth movement
    }
  }
}