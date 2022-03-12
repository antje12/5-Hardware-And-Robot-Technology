//Includes the EEPROM library
#include <EEPROM.h>

void setup() {
  //Activates Serial
  Serial.begin(9600);
}

void loop() {
  //Writes a "byte sized" value to EEPROM - A byte stores an 8-bit unsigned number, from 0 to 255 (a char likewise has the size of a byte)
  writeEEPROM(0, 123);

  //Read a "byte sized" value from EEPROM
  readEEPROM(0);

  //Halts the program, in order not to break the EEPROM, since each address can only be written/overwritten approx. 100.000 times
  while(true);
}

//Stores a char in EEPROM
void writeEEPROM(int address, byte data) {
  EEPROM.write(address, data);
}

//Read a char from EEPROM
void readEEPROM(int address) {
  byte data = EEPROM.read(address);
  Serial.println(data);
}
