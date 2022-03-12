int pinMOSFETA = 3;
int pinMOSFETB = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinMOSFETA, OUTPUT);
  pinMode(pinMOSFETB, OUTPUT);
}

void loop() {
  forward();
  reverse();
  brake();
}

void forward() {
  analogWrite(pinMOSFETA, 255);
  analogWrite(pinMOSFETB, 0);

  delay(2000);
}

void reverse() {
  analogWrite(pinMOSFETA, 0);
  analogWrite(pinMOSFETB, 255);

  delay(2000);
}

void brake() {
  analogWrite(pinMOSFETA, 255);
  analogWrite(pinMOSFETB, 255);

  delay(2000);
}
