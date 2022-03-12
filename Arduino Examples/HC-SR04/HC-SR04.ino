int trigPin = A2;            //the used trig pin
int echoPin = A3;            //the used echo pin
int distance;               //to store the value

void setup() {
  pinMode(trigPin, OUTPUT); //sets pin as OUTPUT
  pinMode(echoPin, INPUT);  //sets pin as INPUT
  Serial.begin(9600);       //enables serial
}

void loop() {
  //store the returned value from the function
  distance = getDistance();

  //prints the stored value
  Serial.println(distance);
}

//function - returns the distance
int getDistance() {
  //sends out a trigger sound
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //returns the received echo in centimeter
  return pulseIn(echoPin, HIGH)* 0.034/2;
}
