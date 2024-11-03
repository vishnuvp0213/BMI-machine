/*Instructions
Upload the code to your NodeMCU or Arduino.
Open the Serial Monitor and set the baud rate to 9600.
When you see the message, place a known weight (like 500g or 1000g) on the load cell.
Type "calibrate" in the Serial Monitor and press Enter.
After you place the weight, enter its exact mass (e.g., 500 for 500 grams) in the Serial Monitor and press Enter again.
The code will calculate and display the calibration factor based on this known weight.*/



#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 3; // DT pin of HX711
const int LOADCELL_SCK_PIN = 2;  // SCK pin of HX711

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 Calibration");

  // Start the scale without a calibration factor
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(); // No calibration factor yet
  scale.tare();      // Reset the scale to zero

  Serial.println("Place a known weight on the scale when prompted.");
  delay(2000);
}

void loop() {
  // Display raw reading from the HX711
  Serial.print("Raw reading: ");
  Serial.println(scale.get_units(10)); // Average of 10 readings for stability

  // Prompt to place a known weight on the scale
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input == "calibrate") {
      Serial.println("Place a known weight on the scale and enter its mass in grams.");
    } else if (input.toFloat() > 0) {
      float known_mass = input.toFloat(); // Get the known mass in grams
      long reading = scale.get_units(10); // Take an average reading

      // Calculate calibration factor
      float calibration_factor = reading / known_mass;
      Serial.print("Calibration factor: ");
      Serial.println(calibration_factor);
      
      // Set and save the calibration factor for future use
      scale.set_scale(calibration_factor);
      Serial.println("Calibration complete. Factor set and ready for use.");
    }
  }
  delay(1000);
}
