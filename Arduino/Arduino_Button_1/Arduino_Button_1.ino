int vOut = A4;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(vOut, INPUT); // if using a resistor
  pinMode(vOut, INPUT_PULLUP); // if not using a resistor
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(vOut);
  Serial.println(value);
}
