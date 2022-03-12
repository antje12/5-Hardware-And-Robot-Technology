//ShiftRegister Pins
int latchPin = 12; //ST_CP or RCLK ()
int clockPin = 13; //SH_CP or SRCLK ()
int dataPin = 11; //DS or SER ()
int clearPin = 10; //MR or SRCLR (Blue)

void setup() {
  //Set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clearPin, OUTPUT);

  digitalWrite(clearPin, HIGH);
  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);
}

void loop() {
  //Clears the register
  clearRegister();

  //Overwrites the register and committing it, one bit at a time
  //PUSH (1): 10000000
  //PUSH (0): 01000000
  //PUSH (1): 10100000
  //PUSH (0): 01010000
  //PUSH (1): 10101000
  //PUSH (0): 01010100
  //PUSH (1): 10101010
  //PUSH (0): 01010101 - Final Register
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(1000);
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(1000);
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(1000);
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(4000);

  //Overwrites the entire register, before committing it
  //PUSH (1): 10101010
  //PUSH (1): 11010101
  //PUSH (0): 01101010
  //PUSH (0): 00110101
  //PUSH (1): 10011010
  //PUSH (1): 11001101
  //PUSH (1): 11100110
  //PUSH (0): 01110011 - Final Register
  pushClock(HIGH);
  pushClock(HIGH);
  pushClock(LOW);
  pushClock(LOW);
  pushClock(HIGH);
  pushClock(HIGH);
  pushClock(HIGH);
  pushClock(LOW);
  pushLatch();
  delay(4000);
  
  //Clears the register
  clearRegister();

  //Overwrites the register and committing it, one bit at a time
  //PUSH (1): 10000000
  //PUSH (1): 11000000
  //PUSH (1): 11100000
  //PUSH (1): 11110000
  //PUSH (1): 01111000
  //PUSH (1): 00111100
  //PUSH (0): 00011110
  //PUSH (0): 00001111 - Final Register
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(1000);
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(HIGH);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(1000);
  pushClock(LOW);
  pushLatch();
  delay(4000);

  while(true);
}

//Clears the register
void clearRegister() {
  //Clears the 8-bit register
  digitalWrite(clearPin, HIGH);
  digitalWrite(clearPin, LOW);
  digitalWrite(clearPin, HIGH);

  //Commits the empty register
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
  digitalWrite(latchPin, HIGH);
}

//Add a data (0/1) to the 8-bit register
void pushClock(boolean data) {
  //If HIGH, data = 1, if LOW, data = 0
  digitalWrite(dataPin, data);  

  //Add the data to the 8-bit register 
  digitalWrite(clockPin, LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);
}

//Commits the current register
void pushLatch() {
  digitalWrite(latchPin, LOW);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}
