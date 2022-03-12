int MotorDirectionA = 12;
int MotorBreakA = 9;
int MotorSpeedA = 3;

int MotorDirectionB = 13;
int MotorBreakB = 8;
int MotorSpeedB = 11;

void setup() {
  //Setup Channel A
  pinMode(MotorDirectionA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(MotorBreakA, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel A
  pinMode(MotorDirectionB, OUTPUT); //Initiates Motor Channel A pin
  pinMode(MotorBreakB, OUTPUT); //Initiates Brake Channel A pin
}

void loop(){
  bothForward();
  delay(2000);
  bothBreak();
  turnLeft();
  delay(1000);
  bothBreak();
}

void bothForward() {
  // forward A full speed
  digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
  digitalWrite(MotorBreakA, LOW);   //Disengage the Brake for Channel A
  analogWrite(MotorSpeedA, 123);    //Spins the motor on Channel A at full speed

  // forward B full speed
  digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
  digitalWrite(MotorBreakB, LOW);   //Disengage the Brake for Channel B
  analogWrite(MotorSpeedB, 123);   //Spins the motor on Channel B at full speed
}

void bothBreak() {
  digitalWrite(MotorBreakA, HIGH); // break A
  digitalWrite(MotorBreakB, HIGH); // break B
}

void turnLeft(){
  // forward A full speed
  digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
  digitalWrite(MotorBreakA, LOW);   //Disengage the Brake for Channel A
  analogWrite(MotorSpeedA, 50);    //Spins the motor on Channel A at full speed

  // forward B full speed
  digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
  digitalWrite(MotorBreakB, LOW);   //Disengage the Brake for Channel B
  analogWrite(MotorSpeedB, 100);   //Spins the motor on Channel B at full speed
}
