int pinGateMotorA = 3;
int pinGateMotorB = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinGateMotorA, OUTPUT);
  pinMode(pinGateMotorB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinGateMotorA, HIGH);
  digitalWrite(pinGateMotorB, HIGH);
  delay(1000);
}
