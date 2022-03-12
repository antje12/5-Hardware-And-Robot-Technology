int pinA = A1;
int pinB = A2;
int pinC = A3;

int comInOut = A4;
int value = 0;

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  
  pinMode(comInOut, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop(){
  readBtn("btn 1", LOW, LOW, LOW); //000 = 0
  readBtn("btn 2", HIGH, LOW, LOW); //100 = 1
  readBtn("btn 3", LOW, HIGH, LOW); //010 = 2
  readBtn("btn 4", HIGH, HIGH, LOW); // 110 = 3
  
  readBtn("btn 5", HIGH, LOW, HIGH); // 101 = 5
  readBtn("btn 6", LOW, HIGH, HIGH); // 011 = 6
  readBtn("btn 7", HIGH, HIGH, HIGH); // 111 = 7
}

void readBtn(String btnNum, bool A, bool B, bool C){
  digitalWrite(pinA, A);
  digitalWrite(pinB, B);
  digitalWrite(pinC, C);
  
  value = analogRead(comInOut);
  if (value < 100){
    Serial.println(btnNum + " says: " + String(value));
    //writeLed(A, B, HIGH); // 4 - 7
  }
}

void writeLed(bool A, bool B, bool C){
  digitalWrite(pinA, A);
  digitalWrite(pinB, B);
  digitalWrite(pinC, C);
  
  pinMode(comInOut, OUTPUT);
  analogWrite(comInOut, 255); // flash LED
  delay(2000);
  pinMode(comInOut, INPUT);
}
