8<img width="1280" alt="readme-banner" src="https://github.com/user-attachments/assets/35332e92-44cb-425b-9dff-27bcf1023c6c">

# [BMI Machine] 🎯


## Basic Details
### Team Name: [TECS]


### Team Members
- Team Lead: [Vishnuprasad] - [NSS College of engineering ]
- Member 2: [sana] - [NSS college of engineering]

### Project Description
This project involves building a BMI calculator using arduino uno,ultrasonic sensor,load cell and HX711 module .The ultrasonic sensor measures height,while the load cell and HX711 module measures weight.The arduino processes these inputs to calculate and display the BMI.And also it provides the details of the range of that measure.

The objective of this project  is to develop an affordable, user-friendly BMI calculator using simple and readily available components intented to provide low cost solution for all individuals at all economic status. 

 )
[]

###  The Solution (that nobody asked for)
[Since our aim is to provide low-cost, readily accessible,effective solution ,we are using arduino based BMI calculator.Such that it can provide quick access with real time information to all individuals in an affordable way even from their home.


Way of working:
1.weight measurement:
The load cell, which get connected with a hx711 amplifier or module, can measure the user's weight. The HX711 module is specifically designed to amplify the load cell's output, providing accurate weight data to the Arduino.

2.Height Measurement:

The ultrasonic sensor will measure the user's height. This sensor works by emitting ultrasonic waves and measuring the time taken for the waves to bounce back from the top of the user's head, providing the height.

3. BMI Calculation:

With the weight and height data, the Arduino will calculate BMI using the formula:  Weight (kg)/ Height (m)2

• The system will then display the calculated BMI, allowing users to understand their weight category and overall health status.

4.Affordability and Accessibility:
As it uses  low-cost components, making  ideal for  limited resources. Using the Arduino Uno as a microcontroller minimizes complexity and keeps the project within a budget- friendly range.

5. User Interaction and Display:

A simple LCD display can be used to show the weight, height, and BMI. The Arduino uno will manage the data  reading, processing,  reading, processing, display of results, making the device easy for anyone to operate.

This solution provides an economical and efficient way to track BMI without the need for expensive equipment, supporting preventive health and self-monitoring.



## Technical Details
Components Used:

Arduino Uno: This microcontroller is the heart of this  BMI calculator, running the code and processing inputs.

• LCD Display (16x2 ): Used to show the entered values and the calculated BMI result. 

Load Cell: To measure weight directly, a load cell with an HX711 amplifier can be integrated for accurate weight measurement.

Ultrasonic Sensor: An ultrasonic sensor like the HC-SR04 can be used to measure height automatically .

Power Supply: The Arduino can be powered via USB or an external battery pack.

2. Programming and Libraries:

Arduino IDE: Used for writing and uploading code to the Arduino.

Libraries:

LiquidCrystal library for interfacing with the LCD display.

HX711 library  for interpreting data from the weight sensor.

NewPing library  for handling distance measurements.

3. Code and Logic:

Input Processing:Arduino will read directly from the sensors and process it.

BMI Calculation:

The formula for BMI is: BMI weight in kg/ (height in meters)² 

The Arduino calculates BMI based on the input values.

Display Output:

The calculated BMI is displayed on the LCD, along with a classification (like : Underweight, Normal, Overweight or obese) based on BMI ranges.

4. Additional Features

serial Communication 
classification of results
simple
reliable 
C++ programming 

For Software:
-programming language:C++
- Frameworks used:Arduino IDE, libraries,BMI calculation logic
- Libraries:Arduino IDE 
           :LiquidCrystal library 
           :HX711 library 
           :NewPing library 
           :HX711 library 
- Tools used:ARDUINO IDE 
            :serial monitor 
            :Sensor libraries
            :Display libraries

For Hardware:
- List main components:Arduino Uno 
                      :load cell
                      :hx711 module
                      :ultrasonic sensor 
                      :LCD display
                      :JUMPER wires
                      :USB cable
                      :A simple keypad
                      :breadboard
                      
- List specifications :
*Arduino Uno board:ATmegha328 microcontroller ,with 32 kb flash memory, 2 kb of SRAM and 14  digital I/O pins

*Load cell:
3 wire 4 load cell each with 50kg capacity. 

*hx711 amplifier:
24 bit ADC 

*Ultrasonic sensor:HC -SR04
measures distance from 2cm to 4cm with an accuracy of 0.3 cm.

*LCD display:16×2 LCD display with 12c adapter

*5V battery source



 
         
- list the tools:screw diver 
                 soldering machine 
                 stripper


### Implementation
For Software:
[# Installation
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

]

# Run
[]

### Project Documentation
For Software:

# Screenshots (Add at least 3)
![Screenshot1](Add screenshot 1 here with proper name)
*Add caption explaining what this shows*

![Screenshot2](Add screenshot 2 here with proper name)
*Add caption explaining what this shows*

![Screenshot3](Add screenshot 3 here with proper name)
*Add caption explaining what this shows*

# Diagrams
![Workflow](Add your workflow/architecture diagram here
                          +------------------------+
                          |      Power Supply      |
                          +------------------------+
                                      |
                                      |
                     +----------------+-----------------+
                     |                |                 |
        +------------v----+     +-----v-----------+    +--------v---------+
        |   Ultrasonic    |     |  Load Cell      |    |     LCD Display  |
        |   Sensor        |     |  + HX711 Module |    |                  |
        +--------+--------+     +--------+--------+    +---------+--------+
                 |                         |                     |
            +----v-------------------------v---------------------v----+
            |                          Arduino Uno                    |
            |              (Processes sensor data and calculates BMI) |
            +---------------------------------------------------------+
                                      |
                                      |
                               +------v------+
                               | Display BMI |
                               +-------------+
)
*Add caption explaining your workflow*

Workflow for BMI calculator using arduino 

1. Start with Power Supply at the top.

2. Connect it to the Arduino Uno.

3. From the Arduino, draw arrows to Load Cell and HX711.

4. Connect the Ultrasonic Sensor to the Arduino.

5. Connect the Arduino to the LCD Display.

6. Include a feedback loop for Repeat or Exit.




For Hardware:

# Schematic & Circuit
![Circuit](Add your circuit diagram 
  )
*Add caption explaining connections*

![Schematic](                +---------------+
                |               |
         +----> | Load Cell     |
         |      |               |
         |      +---------------+
         |               |
         |               |
         |      +---------------+
         |      | HX711 Module  |
         +----> |               |
         |      | VCC   DT SCK  |
         |      | GND   -  -    |
         |      +---------------+
         |               |
         |      +---------------+
         |      | Arduino Uno   |
         |      |               |
         +----> | 5V  GND      |
                | D2   D3       |
                +---------------+

*Add caption explaining the schematic*
Schematic Connections:

Load Cell Connections to HX711:

Load Cell Wire Colors (usually):

Red: Excitation+ (E+)

Black: Excitation- (E-)

White: Signal+ (S+)

Green: Signal- (S-)

HX711 Connections:

Connect the Red wire from the load cell to E+ (A+ on HX711)

Connect the Black wire from the load cell to E- (A- on HX711)

Connect the White wire from the load cell to S+ (A- on HX711)

Connect the Green wire from the load cell to S- (A+ on HX711)

HX711 Pin to Arduino Connections:Connect VCC (on HX711) to 5V on Arduino

Connect GND (on HX711) to GND on Arduino

Connect DT (Data) on HX711 to Digital Pin 2 on Arduino

Connect SCK (Clock) on HX711 to Digital Pin 3 on Arduino



# Build Photos
![Components](Add photo of your components here)
*List out all components shown*

![Build](Add photos of build process here)
*Explain the build steps*

![Final](Add photo of final product here)
*Explain the final build*

### Project Demo
# Video
https://drive.google.com/drive/folders/1kLnk87PIY9sz_SvUEVa_5OVJ-iINHOTO?usp=drive_link
 the video demonstrates about bmi calculating machine
*Explain what the video demonstrates*

# Additional Demos
[Add any extra demo materials/links]

## Team Contributions
- [T B VISHNU PRASAD]: [hardware implementaiom]
- [SANA VK]: [software and weight calibration]

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProject--24-24?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)



