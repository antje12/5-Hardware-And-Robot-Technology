//Motor A (Left)
int motorLeftDirection = 12;   //DIR A
int motorLeftSpeed = 3;        //PWM A

//Motor B (Right)
int motorRightDirection = 13;   //DIR B
int motorRightSpeed = 11;       //PWM B

void setup() {
  //Motor A (Left)
  pinMode(motorLeftDirection, OUTPUT);
  pinMode(motorLeftSpeed, OUTPUT);
  
  //Motor B (Right)
  pinMode(motorRightDirection, OUTPUT);
  pinMode(motorRightSpeed, OUTPUT);
}

void loop() {
  //Go Forward
  drive(HIGH, 100, HIGH, 100, 800);
  
  //Turn Right (hard turn)
  drive(HIGH, 100, LOW, 100, 160);

  //Turn Right (soft turn)
  //drive(HIGH, 100, HIGH, 0, 370);
}

//Drives the robot
void drive(boolean leftDirection, int leftSpeed, boolean rightDirection, int rightSpeed, int distance) {
  //Motor A (Left)
  digitalWrite(motorLeftDirection, leftDirection);
  digitalWrite(motorLeftSpeed, leftSpeed);
  
  //Motor B (Right)
  digitalWrite(motorRightDirection, rightDirection);
  digitalWrite(motorRightSpeed, rightSpeed);

  //Driving distance/time
  delay(distance);
}
