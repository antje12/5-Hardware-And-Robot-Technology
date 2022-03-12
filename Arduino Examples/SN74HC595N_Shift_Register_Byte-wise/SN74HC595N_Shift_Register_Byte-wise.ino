//ShiftRegister Pins
int latchPin = 12; //ST_CP or RCLK
int clockPin = 13; //SH_CP or SRCLK
int dataPin = 11; //DS or SER

void setup() {
  //Set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  digitalWrite(latchPin, LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(dataPin, LOW);
}

void loop() {
  //int number = 17;
    //is equal to 
  //int number = B00010001; (binary representation)

  //Overwrites the entire register and commits it
  writeShiftRegister(B01010101);
  delay(2000);

  //Overwrites the entire register and commits it
  writeShiftRegister(B01110011);
  delay(2000);

  //Overwrites the entire register and commits it
  writeShiftRegister(B00001111);
  delay(2000);

  while(true);
}


//Overwrites the entire register and commits the changes
void writeShiftRegister(int output) {
  //Bring Latch Pin LOW - prepare to commit the register
  digitalWrite(latchPin, LOW);

  //Overwrites the entire register
  shiftOut(dataPin, clockPin, MSBFIRST, output);

  //Bring Latch Pin HIGH - commits the register
  digitalWrite(latchPin, HIGH);
}
