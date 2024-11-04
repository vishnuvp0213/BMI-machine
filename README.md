8<img width="1280" alt="readme-banner" src="https://github.com/user-attachments/assets/35332e92-44cb-425b-9dff-27bcf1023c6c">

# BMI Machine 🎯


## Basic Details
### Team Name: TECS


### Team Members
- Team Lead: T B Vishnu prasad - NSS College of engineering,Palakkad
- Member 2: sana V K - NSS college of engineering,Palakkad

### Project Description
This project involves building a BMI calculator using arduino uno,ultrasonic sensor,load cell and HX711 module .The ultrasonic sensor measures height,while the load cell and HX711 module measures weight.The arduino processes these inputs to calculate and display the BMI.And also it provides the details of the range of that measure.

The objective of this project  is to develop an affordable, user-friendly BMI calculator using simple and readily available components intented to provide low cost solution for all individuals at all economic status. 
### The Problem(that doesn't exist)


###  The Solution (that nobody asked for)
Since our aim is to provide low-cost, readily accessible,effective solution ,we are using arduino based BMI calculator.Such that it can provide quick access with real time information to all individuals in an affordable way even from their home.


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
step-by-step process in implementing 
1. **Set Up Connections:**  
   Connect the load cell to the HX711 module, then connect the HX711, ultrasonic sensor, and LCD to the Arduino.
2. **Calibrate the HX711 Module:**  
   Load a calibration sketch for the HX711. Place a known weight on the load cell to obtain a calibration factor, which will convert the raw load cell data into kilograms.
3. **Measure Weight with Load Cell:**  
   Use the calibrated HX711 to read the person’s weight in kilograms.
4. **Measure Height with Ultrasonic Sensor:**  
   Position the ultrasonic sensor to measure the person’s height in centimeters and convert this reading to meters.
5. **Calculate BMI:**  
   Using the formula \( \text{BMI} = \frac{\text{Weight (kg)}}{\text{Height (m)}^2} \), calculate the BMI.
6. **Determine BMI Category:**  
   Compare the BMI value to standard categories (e.g., underweight, normal weight, overweight, obese).
7. **Display Results on LCD:**  
   Show the BMI value and category on the LCD screen.
# Run
On running the code we can see the results in the LCD Display placed 
The display will show the height in meters, weight in kilograms and BMI based on these height and weight
It also shows the BMI category

### Project Documentation
For Software:

# Screenshots (Add at least 3)
![calibration](https://github.com/user-attachments/assets/e127c4f1-c171-465e-8c6c-1ecd3392c9c5)
This is the calibration of Hx711

![test](https://github.com/user-attachments/assets/838f8aed-1c26-4fb8-94f1-14241b63742f)
This is the testing of weight 

![BMI](https://github.com/user-attachments/assets/d7a0f04c-9d79-4443-9147-691c24a9e406)
This is the results obtained in BMI machine


# Diagrams


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

Workflow for BMI calculator using arduino 

1. Start with Power Supply at the top.

2. Connect it to the Arduino Uno.

3. From the Arduino, draw arrows to Load Cell and HX711.

4. Connect the Ultrasonic Sensor to the Arduino.

5. Connect the Arduino to the LCD Display.

6. Include a feedback loop for Repeat or Exit.




For Hardware:

# Schematic & Circuit

               +---------------+
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



# Build photos
![hx711 and load cells](https://github.com/user-attachments/assets/5c72a311-0084-483c-a9aa-efab432464e8)
HX711 module with four 50 kg load cells
![Ultrasonic sensor](https://github.com/user-attachments/assets/f09f604a-260a-4593-bb39-88ab9a3a94e1)
This is the ultrasonic sensor used to measure height
![ardrino](https://github.com/user-attachments/assets/41d12df0-1bb7-4d4b-8427-7f38e9c3b844)
Ardrino uno board used to compute the BMI 
![LCD](https://github.com/user-attachments/assets/5ddb704d-7a7f-4f1b-8753-16955a08e776)
LCD display used to display results

THE COMPONENTS ARE:
1)Ardrino Uno
2)HX711 with four 50KG load cells
3)Ultrasonic sensors
4)Liquid Crystal Display I2C


![final_model](https://github.com/user-attachments/assets/efc4839b-a139-4ab5-afde-347e36cb36c9)
This is the final hardware model of BMI machine ,we can measure BMI and see result in LCD display by simply standing in 
weight measurement unit

### Project Demo
# Video
https://drive.google.com/drive/folders/1kLnk87PIY9sz_SvUEVa_5OVJ-iINHOTO?usp=drive_link
 the video demonstrates about BMI calculation using our model


## Team Contributions
- [T B VISHNU PRASAD]: [hardware implementaiom]
- [SANA VK]: [software and weight calibration]

---
Made with ❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProject--24-24?link=https%3A%2F%2Fwww.tinkerhub.org%2Fevents%2FQ2Q1TQKX6Q%2FUseless%2520Projects)



