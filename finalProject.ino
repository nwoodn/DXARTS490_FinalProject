
// defines pins
int motorPin = 9;
int trigPin = 6;
int echoPin = 5;

// defines variables
long duration;
int distance;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(motorPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  distance = map(distance,4,300,35,150);

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 150) {
    analogWrite(motorPin, distance);
    delay(300);
  }
}
