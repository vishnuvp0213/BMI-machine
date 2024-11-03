/*Instructions
Make sure to replace -23440.94 with the calibration factor you obtained during the calibration step.
Upload the code to your NodeMCU or Arduino.
Open the Serial Monitor at 9600 baud rate.
Place an object on the load cell, and the weight should be displayed in kilograms.
Check for accuracy: If the weight readings fluctuate, try adjusting the calibration factor slightly or averaging more readings.*/

#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3; // DT pin of HX711
const int LOADCELL_SCK_PIN = 2;  // SCK pin of HX711

HX711 scale;
float calibration_factor = -23440.94;  // Replace with your calibration factor

void setup() {
  Serial.begin(9600);
  Serial.println("Weight Measurement");

  // Initialize HX711
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);  // Set the calibration factor
  scale.tare();  // Reset the scale to zero
  Serial.println("Place an item on the scale to read its weight.");
}

void loop() {
  // Read weight in kilograms
  float weight_kg = scale.get_units(10);  // Average of 10 readings for stability

  Serial.print("Weight: ");
  Serial.print(weight_kg, 2);  // Display weight with 2 decimal places
  Serial.println(" kg");

  delay(1000);  // Update every second
}
