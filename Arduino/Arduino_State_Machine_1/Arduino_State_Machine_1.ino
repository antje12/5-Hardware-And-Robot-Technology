// Motors
int MotorDirectionA = 12;
int MotorBreakA = 9;
int MotorSpeedA = 3;

int MotorDirectionB = 13;
int MotorBreakB = 8;
int MotorSpeedB = 11;

// State
int state = 0;
String program = "";
char next = "";
int output = B00000000;
bool newState = false;

// Multiplexer
int pinA = A1;
int pinB = A2;
int pinC = A3;

int comInOut = A5;
int value = 0;

// Shift Register
int dataPin = 5;
int clockPin = 6;
int latchPin = 7;

void setup() {
  setupMotor();
  setupMultiplexer();
  setupShiftRegister();
  Serial.begin(9600);
}

void setupMotor(){
  pinMode(MotorDirectionA, OUTPUT);
  pinMode(MotorBreakA, OUTPUT);
  pinMode(MotorDirectionB, OUTPUT);
  pinMode(MotorBreakB, OUTPUT);
}

void setupMultiplexer(){
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(comInOut, INPUT_PULLUP);
}

void setupShiftRegister(){
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(latchPin, LOW);
}

void loop(){
  /*switch(state){
    case 0: // input mode
      registerInput();
      break;
    case 1: // active mode
      executeProgram(); // .charAt(0) .remove(0);
      break;
    case 2: // pause mode
      wait();
      break;
  }*/
  readBtn("btn 0", LOW, LOW, LOW, 0); //000 = 0
  readBtn("btn 1", HIGH, LOW, LOW, 1); //100 = 1
  readBtn("btn 2", LOW, HIGH, LOW, 2); //010 = 2
  readBtn("btn 3", HIGH, HIGH, LOW, 3); // 110 = 3
  readBtn("btn 4", LOW, LOW, HIGH, 4); //001 = 4
  readBtn("btn 5", HIGH, LOW, HIGH, 5); //101 = 5
  readBtn("btn 6", LOW, HIGH, HIGH, 6); // 011 = 6
  
  flashLEDs();
}

void readBtn(String btnNum, bool A, bool B, bool C, int s){
  digitalWrite(pinA, A);
  digitalWrite(pinB, B);
  digitalWrite(pinC, C);
  
  value = analogRead(comInOut);
  if (value < 100){
    Serial.println(btnNum + " says: " + String(value));
    state = s;
    newState = true;
  }
}

void flashLEDs(){
  digitalWrite(latchPin, LOW);
  switch(state){
    case 0:
      output = B10000000;
      break;
    case 1:
      output = B01000000;
      break;
    case 2:
      output = B00100000;
      break;
    case 3:
      output = B00010000;
      break;
    case 4:
      output = B00001000;
      break;
    case 5:
      output = B00000100;
      break;
    case 6:
      output = B00000010;
      break;
  }
  if (newState){
    shiftOut(dataPin, clockPin, LSBFIRST, output);
  }
  digitalWrite(latchPin, HIGH);
}

/*
void executeProgram(){
  while(program.length() > 0){
    next = program.charAt(0)
    switch(next){
      case 'f':
        forward();
        break;
      case 'b':
        back();
        break;
      case 'l':
        left();
        break;
      case 'r':
        right();
        break;
    }
    program.remove(0);
  }
}

// transition code
void goToInputState(){
  state = 0;
  program = ""; // reset program
}

void goToActiveState(){
  state = 1;
}

void goToPauseState(){
  state = 2;
}

// program code
void forward() {
  digitalWrite(MotorDirectionA, HIGH); //Forward
  digitalWrite(MotorBreakA, LOW); //No break
  analogWrite(MotorSpeedA, 123); //Speed
  
  // forward B full speed
  digitalWrite(MotorDirectionB, HIGH); //Forward
  digitalWrite(MotorBreakB, LOW); //No break
  analogWrite(MotorSpeedB, 123); //Speed
}

void back() {
  digitalWrite(MotorDirectionA, LOW); //Backward
  digitalWrite(MotorBreakA, LOW); //No break
  analogWrite(MotorSpeedA, 123); //Speed
  
  digitalWrite(MotorDirectionB, LOW); //Backward
  digitalWrite(MotorBreakB, LOW); //No break
  analogWrite(MotorSpeedB, 123); //Speed
}

void break() {
  digitalWrite(MotorBreakA, HIGH);
  digitalWrite(MotorBreakB, HIGH);
}

void left(){
  digitalWrite(MotorDirectionA, HIGH); //Forward
  digitalWrite(MotorBreakA, LOW); //No break
  analogWrite(MotorSpeedA, 50); //Speed
  
  digitalWrite(MotorDirectionB, HIGH); //Forward
  digitalWrite(MotorBreakB, LOW); //No break
  analogWrite(MotorSpeedB, 100); //Speed
}

void right(){
  digitalWrite(MotorDirectionA, HIGH); //Forward
  digitalWrite(MotorBreakA, LOW); //No break
  analogWrite(MotorSpeedA, 100); //Speed
  
  digitalWrite(MotorDirectionB, HIGH); //Forward
  digitalWrite(MotorBreakB, LOW); //No break
  analogWrite(MotorSpeedB, 50); //Speed
}*/
