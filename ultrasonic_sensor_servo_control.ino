#include <Servo.h>
#define echoPin 2
#define trigPin 3
#define speedOfSound 0.034 // cm/ms

long duration;
int distance;
Servo myServo; //creating a servo object named myServo

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(9);
}

void loop()
{
  digitalWrite(trigPin, LOW); //clears the trigPin condition
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH); // sets the trigPin HIGH
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // sets the trigPin LOW
  
  duration = pulseIn(echoPin, HIGH); // reads the echo pin
  distance = duration * speedOfSound / 2; //calculate the distance
  
  //display distance in Serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  //map the distance (for HC-SR04 2 to 400cm) to servo range(0-180)
  int range = map(distance, 2, 400, 0, 180); 
  myServo.write(range);
  // wait for servo to reach the position
  delay(500);
}