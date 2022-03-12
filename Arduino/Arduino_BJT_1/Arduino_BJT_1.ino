int pinGate = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinGate, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinGate, HIGH);
  delay(1000);
  digitalWrite(pinGate, LOW);
  delay(1000);
}
