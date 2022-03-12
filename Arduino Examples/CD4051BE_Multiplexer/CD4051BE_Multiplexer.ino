int pinA = 2; //Blue
int pinB = 3; //Green
int pinC = 4; //Yellow
int comOutInPin = A5; //White

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(comOutInPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  readComOutIn(0, LOW, LOW, LOW);
  readComOutIn(1, LOW, LOW, HIGH);
  readComOutIn(2, LOW, HIGH, LOW);
  readComOutIn(3, LOW, HIGH, HIGH);
  readComOutIn(4, HIGH, LOW, LOW);
  readComOutIn(5, HIGH, LOW, HIGH);
  readComOutIn(6, HIGH, HIGH, LOW);
  readComOutIn(7, HIGH, HIGH, HIGH);
}

//Detects button input
void readComOutIn(int channel, bool C, bool B, bool A) {
  //Defines which channel the comOutIn port is connected to
  digitalWrite(pinA, A);
  digitalWrite(pinB, B);
  digitalWrite(pinC, C);

  //Reads the channel
  boolean channelValue = digitalRead(comOutInPin);

  //If the connected button is pushed
  if(channelValue == LOW) {
    Serial.print("Button ");
    Serial.print(channel);
    Serial.println(" was pushed!");
    delay(100);
  }

  //Loops until the button is not pressed anymore
  while(channelValue == LOW) {
    channelValue = digitalRead(comOutInPin);
  }
}
