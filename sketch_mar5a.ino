/*
  IoT Solar Tracker Project 2025
*/

#include <Servo.h>

// declare variables for pins
const int light1Pin = A0;
const int servoPin = 9;

// variable for servo angle
int angle = 90;

int light1Reading;

// margin for difference to move motor
int margin = 20;

// create servo object and give it a name
Servo servo1;

void setup() {   // put your setup code here, to run once:
  servo1.attach(servoPin);  // attach servo to pin
  servo1.write(angle);      // set initial servo angle
  Serial.begin(9600);       // initialize serial communication
}

void loop() {  // put your main code here, to run repeatedly:
  // get light sensor values
  light1Reading = analogRead(light1Pin);

  // move the servo depending on the difference
  if(light1Reading > margin){  // increase angle if light1Reading is greater than the margin
    if(angle<180){          // only increase the angle if it is already less than 180 degrees
      angle = angle + 1;
    }
  }
  else if(light1Reading < (-1*margin)){  // decrease angle if light1Reading is less than negative margin
    if(angle>0){                      // only decrease the angle if it is already greater than than 0 degrees
      angle = angle - 1;
    }
  }
  else{  // if difference is within +/- margin, do nothing  
         // this prevents the servo from constantly bouncing back and forth due to small fluctuations
  }

