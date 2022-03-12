int pinOut = 3;
int pinIn = A5;
int pinInValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinOut, OUTPUT);
  digitalWrite(pinOut, HIGH);
  
  pinMode(pinIn, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  pinInValue = analogRead(pinIn);
  Serial.println(pinInValue);
}
