int pinLed = 3;
int pinPot = A5;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
  pinMode(pinPot, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pinPot);
  Serial.println(value);
  analogWrite(pinLed, value/4);
}
