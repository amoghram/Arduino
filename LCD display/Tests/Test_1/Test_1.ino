int buttonPin = 2;
int buttonNew;
int buttonOld = 1;
char buf[80];

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonNew = digitalRead(buttonPin);
  sprintf(buf,"New Button: %d\n", buttonNew);
  Serial.println(buf);
  sprintf(buf, "Old Button: %d\n", buttonOld);
  Serial.print(buf);

  Serial.println("-----------");

  buttonOld = buttonNew;
  delay(100);
}
