# ESP32-based Energy Management and Visitor Counter for the e-Yantra Lab
## GEC Khagaria's Submission for eYantra eLSI Hackathon: Automate your lab 
> This project is a solution designed for the e-Yantra Lab environment, aimed at improving energy efficiency by controlling lights and fans based on visitor count. It uses an ESP32 microcontroller with ultrasonic sensors to detect the entry and exit of people, which in turn controls the power supply to the lab equipment.

### Online Simulation (Using Wokwi)
<img src="https://github.com/satyarth8/-ESP32-based-Energy-Management-and-Visitor-Counter-for-the-e-Yantra-Lab/assets/126249188/63f34762-7fbe-46bc-93a4-b29d99738ffc" style="width:40%;height:auto;" /> 

> https://wokwi.com/projects/396732756594349057

<img src="https://github.com/satyarth8/-ESP32-based-Energy-Management-and-Visitor-Counter-for-the-e-Yantra-Lab/assets/126249188/330030bd-8586-4dab-b410-b71acc2b0c36" style="width:40%;height:auto;" /> 

> https://www.tinkercad.com/things/7Fbl2wsHccv-copy-of-copy-of-copy-of-ultrasonic-with-led/editel?tenant=circuits
### Circuit Diagram
<img src="https://github.com/satyarth8/-ESP32-based-Energy-Management-and-Visitor-Counter-for-the-e-Yantra-Lab/assets/126249188/5835acc0-a09b-4403-a272-df75b6905c39" style="width:50%;height:auto;" /> 

### Demonstration Video
> https://www.youtube.com/watch?v=TaXw040LogM

### Components Used
- ESP32 microcontroller
- LiquidCrystal display (16x2)
- Ultrasonic sensors (HC-SR04) for entry and exit detection
- Relay module for controlling power to lights and fans
- Breadboard and jumper wires for connections


## Setup and Installation
1. Connect the components as per the circuit diagram.
2. Flash the code onto the ESP32 microcontroller using Arduino IDE or another compatible tool.
3. Open a serial monitor to view output data and debug information.
4. Ensure the relay is connected to a power supply that controls the lab's lights and fans.
5. Power up the system to start monitoring visitors and controlling lab equipment.

## Usage
- if( ```IN Sensor``` detects a person )
    check the ```OUT sensor``` for 3 seconds , using of a loop of 10, having delay of 300ms...
        if(``` OUT Sensor``` detected a person within that time period than increase the count of person in room and , activate relay accordingly...
  the vice versa happens to detect if the person has exited the lab.
  
## Project Overview
The project aims to automate energy management by switching on/off lab lights and fans based on the number of people in the lab. It uses ultrasonic sensors to detect when someone enters or exits the lab. The system displays the current count of visitors on an LCD screen and can also relay this information through a serial interface.

## Contact
For questions, suggestions, or contributions, feel free to open an issue or submit a pull request. You can also reach us via email at [satyarthaprakash7168@gmail.com].
