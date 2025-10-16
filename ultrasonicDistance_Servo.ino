#include <Servo.h>

Servo myServo;  
int servoPin = 9; 
const int trigPin = 11;
const int echoPin = 12;
long duration;
int distance;
long ultrasonic_distance() {
   // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distancec
  distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  myServo.attach(servoPin);  
  myServo.write(90);     
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic_distance();
  while(distance <= 5){
    myServo.write(5);  
    delay(1000);  
   distance = ultrasonic_distance();
  } 
  myServo.write(175);  
  delay(1000);     
}