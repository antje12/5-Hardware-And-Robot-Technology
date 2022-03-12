int pinMOSFETGate = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinMOSFETGate, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinMOSFETGate, HIGH);
}
