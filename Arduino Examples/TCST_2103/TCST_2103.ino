//The used pin and a counter
int interruptPin = 2;
volatile int counter = 0;

void setup() {
  //Declares that the pin is being used for detecting inputs, while activating the pins build in pull-up resistor
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, CHANGE);

  //Activates Serial
  Serial.begin(9600);
}

void loop() {
  //Beware that the usage Serial can disturb interrupt services
  Serial.print("Count: ");
  Serial.println(counter);
}

//Fires when the used pin changes from HIGH->LOW or LOW->HIGH
void count() {
  counter++;
}
