int motorAIN1 = 3;
int motorAIN2 = 5;
int motorBIN1 = 10;
int motorBIN2 = 11;

void setup() {
  pinMode(motorAIN1, OUTPUT);
  pinMode(motorAIN2, OUTPUT);
  pinMode(motorBIN1, OUTPUT);
  pinMode(motorBIN2, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  motorA("forward", 255);
  delay(1000);
  motorA("backward", 255);
  delay(1000);
  motorA("forward", 0);
  delay(1000);
  motorB("forward", 155);
  delay(1000);
  motorB("backward", 155);
  delay(1000);
  motorB("forward", 0);
  delay(1000);
}

void motorA(String motorDirection, int motorSpeed) {
  if(motorDirection == "forward") {
    analogWrite(motorAIN1, motorSpeed);
    analogWrite(motorAIN2, 0);
  }
  else {
    analogWrite(motorAIN1, 0);
    analogWrite(motorAIN2, motorSpeed);
  }
}

void motorB(String motorDirection, int motorSpeed) {
  if(motorDirection == "forward") {
    analogWrite(motorBIN1, motorSpeed);
    analogWrite(motorBIN2, 0);
  }
  else {
    analogWrite(motorBIN1, 0);
    analogWrite(motorBIN2, motorSpeed);
  }
}
