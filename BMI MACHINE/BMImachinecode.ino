/*This is a Ardrino code to calculate Body Mass Index
we are using hx711 load cell driver that drives four 50 kg load cells
Ultrasonic sensor for height measurement
RUN This code after calibrating the load cells and type calibration factor in this code*/



#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

// HX711 setup for weight measurement
const int LOADCELL_DOUT_PIN = 3;  // DT pin of HX711
const int LOADCELL_SCK_PIN = 2;   // SCK pin of HX711
HX711 scale;
float calibration_factor = -23440.94;  // Replace with your calibrated factor

// Ultrasonic sensor setup for height measurement
const int TRIG_PIN = 7;            // Trig pin of HC-SR04
const int ECHO_PIN = 6;            // Echo pin of HC-SR04
float initial_height_cm = 0.0;
bool initialHeightMeasured = false;

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address if necessary

void setup() {
  Serial.begin(9600);
  Serial.println("BMI Calculator");

  // Setup HX711 for weight measurement
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);  // Set your calibration factor
  scale.tare();  // Reset the scale to 0

  // Setup ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Setup LCD
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("Measuring height...");

  // Measure initial height from sensor to ground
  initial_height_cm = measureHeight();
  Serial.print("Initial Height (from sensor to ground): ");
  Serial.print(initial_height_cm);
  Serial.println(" cm");
  lcd.clear();
  lcd.print("Initial Height:");
  lcd.setCursor(0, 1);
  lcd.print(initial_height_cm);
  lcd.print(" cm");
  initialHeightMeasured = true;
  delay(4000);
  lcd.clear();
}

void loop() {
  // Measure weight
  float weight_kg = scale.get_units(10);  // Average 10 readings for stable output
  Serial.print("Weight: ");
  Serial.print(weight_kg, 2);
  Serial.println(" kg");

  lcd.clear();
  lcd.print("Weight: ");
  lcd.print(weight_kg, 2);
  lcd.print(" kg");

  // Wait 4 seconds before the next measurement
  delay(4000);

  // Measure height when human is standing
  float standing_height_cm = measureHeight();
  float human_height_cm = initial_height_cm - standing_height_cm;  // Calculate human height in cm
  float human_height_m = human_height_cm / 100;                    // Convert height to meters
  Serial.print("Height: ");
  Serial.print(human_height_m, 2);   // Display height in meters
  Serial.println(" m");

  lcd.clear();
  lcd.print("Height: ");
  lcd.print(human_height_m, 2);
  lcd.print(" m");

  // 4-second delay after measuring height before calculating BMI
  delay(4000);

  // Calculate BMI
  if (human_height_m > 0) {
    float bmi = weight_kg / (human_height_m * human_height_m);  // BMI formula
    Serial.print("BMI: ");
    Serial.print(bmi, 2);
    Serial.println();

    lcd.clear();
    lcd.print("BMI: ");
    lcd.print(bmi, 2);

    // BMI category display
    String category;
    if (bmi < 18.5) {
      category = "Underweight";
    } else if (bmi >= 18.5 && bmi < 24.9) {
      category = "Normal weight";
    } else if (bmi >= 25 && bmi < 29.9) {
      category = "Overweight";
    } else {
      category = "Obesity";
    }

    Serial.println("Category: " + category);
    lcd.setCursor(0, 1);
    lcd.print(category);
    Serial.println("------------------------");
  } else {
    Serial.println("Invalid height reading.");
    lcd.clear();
    lcd.print("Invalid height");
  }

  // 4-second delay before restarting loop
  delay(4000);
}

// Function to measure height using ultrasonic sensor
float measureHeight() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.0343 / 2;  // Calculate distance in cm
}
