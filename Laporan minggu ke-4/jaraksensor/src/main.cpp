#include <Arduino.h> 

const int trigPin = 5;
const int echoPin = 18;


//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701


long duration;
float distanceCm;
float distanceInch;


void setup() {
 Serial.begin(115200); // Starts the serial communication
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void loop() {

 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
  
 duration = pulseIn(echoPin, HIGH);
 
 distanceCm = duration * SOUND_SPEED/2;

 distanceInch = distanceCm * CM_TO_INCH;
 
 Serial.print("Distance (cm): ");
 Serial.println(distanceCm);

  delay(1000);
}
