#include <Servo.h>


static const int servoPin = 4;
Servo servo1;
int angle = 0;
int p=0;


const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor


void setup() {
    servo1.attach(servoPin);
    servo1.write(angle);

     Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  dist_sensor();
}

void angle_detemine(long cm)
{
  if(cm <= 30)
  {
    angle = 180;
  }
  else if(cm <= 40)
  {
    angle = 100;
  }
  else if(cm <= 50)
  {
    angle = 50;
  }
  else{
    angle = 0;
  }
  Pull();
}

void Pull()
{
      servo1.write(angle);
      delay(1000);
}

void dist_sensor()
{
  long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
   angle_detemine(cm);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
