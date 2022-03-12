int MotorDirectionA = 12;
int MotorBreakA = 9;
int MotorSpeedA = 6;

int MotorDirectionB = 13;
int MotorBreakB = 8;
int MotorSpeedB = 11;

int interruptPin2 = 2;
int interruptPin3 = 3;
volatile int counter = 0;
int turn90 = 35; // 90 degree turn
int straight = 50;

void setup() {
  //Setup Channel A
  pinMode(MotorDirectionA, OUTPUT); //Initiates Motor Channel A pin
  pinMode(MotorBreakA, OUTPUT);     //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(MotorDirectionB, OUTPUT); //Initiates Motor Channel A pin
  pinMode(MotorBreakB, OUTPUT);     //Initiates Brake Channel A pin

  pinMode(interruptPin2, INPUT_PULLUP);
  pinMode(interruptPin3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(interruptPin2), count, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), count, CHANGE);
  
  Serial.begin(9600);
}

void loop(){
  turnLeft();
  bothBreak();
  while(true){
  }
}

//Fires when the used pin changes from HIGH->LOW or LOW->HIGH
void count() {
  counter++;
}

void bothForward() {
  counter = 0;
  while(counter < straight)
  {
    // forward A full speed
    digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
    digitalWrite(MotorBreakA, LOW);      //Disengage the Brake for Channel A
    analogWrite(MotorSpeedA, 255);       //Spins the motor on Channel A at full speed

    // forward B full speed
    digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
    digitalWrite(MotorBreakB, LOW);      //Disengage the Brake for Channel B
    analogWrite(MotorSpeedB, 255);       //Spins the motor on Channel B at full speed
  }
}

void bothBreak() {
  digitalWrite(MotorBreakA, HIGH); // break A
  digitalWrite(MotorBreakB, HIGH); // break B
}

void turnLeft(){
  counter = 0;
  while(counter < turn90)
  {
    // forward A full speed
    digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
    digitalWrite(MotorBreakA, LOW);      //Disengage the Brake for Channel A
    analogWrite(MotorSpeedA, 0);         //Spins the motor on Channel A at full speed

    // forward B full speed
    digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
    digitalWrite(MotorBreakB, LOW);      //Disengage the Brake for Channel B
    analogWrite(MotorSpeedB, 255);       //Spins the motor on Channel B at full speed
  }
}

void turnRight(){
  counter = 0;
  while(counter < turn90)
  {
    // forward A full speed
    digitalWrite(MotorDirectionA, HIGH); //Establishes forward direction of Channel A
    digitalWrite(MotorBreakA, LOW);      //Disengage the Brake for Channel A
    analogWrite(MotorSpeedA, 255);       //Spins the motor on Channel A at full speed

    // forward B full speed
    digitalWrite(MotorDirectionB, HIGH); //Establishes forward direction of Channel B
    digitalWrite(MotorBreakB, LOW);      //Disengage the Brake for Channel B
    analogWrite(MotorSpeedB, 0);         //Spins the motor on Channel B at full speed
  }
}
