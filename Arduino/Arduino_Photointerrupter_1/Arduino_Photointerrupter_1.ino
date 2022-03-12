int pinRead = A5;
int value = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinRead, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pinRead);
  if (value < 975)
  {
    Serial.println("white");
  }
  if (985 < value && value < 995)
  {
    Serial.println("table");
  }
  if (995 < value && value < 1005)
  {
    Serial.println("black");
  }
}
