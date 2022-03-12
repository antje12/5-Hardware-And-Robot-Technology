// Motor control
int MotorDirectionA = 13;
int MotorBreakA = 8;
int MotorSpeedA = 11;

int MotorDirectionB = 12;
int MotorBreakB = 9;
int MotorSpeedB = 6;

int pinReadA = A4;
int pinReadB = A5;
int value = 0;

int mSpeed = 150;

enum color {
  white,
  black,
  unknown
};

void setup() {
  setupMotorControl();
  pinMode(pinReadA, INPUT_PULLUP);
  pinMode(pinReadB, INPUT_PULLUP);
  Serial.begin(9600);
}

void setupMotorControl(){
  pinMode(MotorDirectionA, OUTPUT);
  pinMode(MotorBreakA, OUTPUT);
  pinMode(MotorDirectionB, OUTPUT);
  pinMode(MotorBreakB, OUTPUT);
}

void loop() {
  // sensor on left side
  color surfaceColor = getColor(pinReadA);
  switch (surfaceColor){
    case white:
      right(); // turn right to hit the black surface
      break;
    case black:
      left(); // turn left to hit the white surface
      break;
    case unknown:
      // undefined surface
      break;
  }
}

color getColor(int pinRead){
  value = analogRead(pinRead);
  //Serial.println(value);
  if (value < 100)
  {
    return white;
  }
  if (800 < value)
  {
    return black;
  }
  return unknown;
}

void forward() {
  // forward A full speed
  digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
  digitalWrite(MotorBreakA, LOW);      //Disengage the Brake for Channel A
  analogWrite(MotorSpeedA, mSpeed);       //Spins the motor on Channel A at full speed

  // forward B full speed
  digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
  digitalWrite(MotorBreakB, LOW);      //Disengage the Brake for Channel B
  analogWrite(MotorSpeedB, mSpeed);       //Spins the motor on Channel B at full speed
}

void backward() {
  // backward A full speed
  digitalWrite(MotorDirectionA, LOW); //Establishes backward direction of Channel A
  digitalWrite(MotorBreakA, LOW);      //Disengage the Brake for Channel A
  analogWrite(MotorSpeedA, mSpeed);       //Spins the motor on Channel A at full speed

  // backward B full speed
  digitalWrite(MotorDirectionB, LOW); //Establishes backward direction of Channel B
  digitalWrite(MotorBreakB, LOW);      //Disengage the Brake for Channel B
  analogWrite(MotorSpeedB, mSpeed);       //Spins the motor on Channel B at full speed
}

void left(){
  // forward A no speed
  digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
  digitalWrite(MotorBreakA, LOW);      //Disengage the Brake for Channel A
  analogWrite(MotorSpeedA, 0);         //Spins the motor on Channel A at no speed

  // forward B full speed
  digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
  digitalWrite(MotorBreakB, LOW);      //Disengage the Brake for Channel B
  analogWrite(MotorSpeedB, mSpeed);       //Spins the motor on Channel B at full speed
}

void right(){
  // forward A full speed
  digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
  digitalWrite(MotorBreakA, LOW);      //Disengage the Brake for Channel A
  analogWrite(MotorSpeedA, mSpeed);       //Spins the motor on Channel A at full speed

  // forward B no speed
  digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
  digitalWrite(MotorBreakB, LOW);      //Disengage the Brake for Channel B
  analogWrite(MotorSpeedB, 0);         //Spins the motor on Channel B at no speed
}
