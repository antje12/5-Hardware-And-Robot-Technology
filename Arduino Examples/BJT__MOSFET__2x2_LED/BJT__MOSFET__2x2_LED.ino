int pinBJTBase = 3;
int pinMOSFETGate = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBJTBase, OUTPUT);
  pinMode(pinMOSFETGate, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinBJTBase, HIGH);
  digitalWrite(pinMOSFETGate, HIGH);
}
