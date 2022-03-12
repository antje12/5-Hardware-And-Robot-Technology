int pinLED = 3;
int pinPot = A5;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinPot, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(pinPot);
  Serial.println(potValue);
  
  analogWrite(pinLED, potValue/4);
}
