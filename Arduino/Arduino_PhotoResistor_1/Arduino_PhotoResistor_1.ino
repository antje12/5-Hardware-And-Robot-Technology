//The used pin and a counter
int interruptPin2 = 2;
int interruptPin3 = 3;
volatile int counter = 0;

void setup() {
  //Declares that the pin is being used for detecting inputs, 
  //while activating the pins build in pull-up resistor
  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(interruptPin3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), count, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), count, CHANGE);

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
