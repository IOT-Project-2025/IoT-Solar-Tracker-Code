#include <Stepper.h>

// Stepper motor setup
const int stepsPerRevolution = 2048;
Stepper stepper(stepsPerRevolution, 8, 10, 9, 11);

// Light sensor pins
const int light1Pin = A0;
const int light2Pin = A1;

// Thresholds
const int brightnessThreshold = 700;  // Bright light
const int margin = 50;                // Sensitivity to difference
const int stepSize = 30;              // Number of steps to move (higher = faster)

void setup() {
  stepper.setSpeed(15);   // Increase speed (RPM)
  Serial.begin(9600);     // Serial for debugging
}

void loop() {
  // Read light sensors
  int light1Reading = analogRead(light1Pin);
  int light2Reading = analogRead(light2Pin);
  int difference = light2Reading - light1Reading;

  // Debug output
  Serial.print("L1: ");
  Serial.print(light1Reading);
  Serial.print("  L2: ");
  Serial.print(light2Reading);
  Serial.print("  Diff: ");
  Serial.println(difference);

  // Only move when bright light is detected
  if (light1Reading > brightnessThreshold || light2Reading > brightnessThreshold) {
    if (difference > margin) {
      stepper.step(stepSize);  // Move right
    } else if (difference < -margin) {
      stepper.step(-stepSize); // Move left
    }
  }

}
