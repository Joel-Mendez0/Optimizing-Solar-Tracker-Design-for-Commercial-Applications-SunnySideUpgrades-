# Capstone Final Project
## Optimizing Solar Tracker Design for Commercial Applications

https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/0a00a07c-9d0d-4bea-a53a-b840ea959109

https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/70076ef7-138c-4648-81d9-b663b06ff56b

https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/11da9491-a63d-4943-8d3b-7a6165acc433

https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/452aa02b-4df4-4c98-ad79-40416ea26a1e

https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/3dc2a47d-8116-4849-b216-8741e3ced0c9



# Commercial Solar Tracking - Critical Design Report

## EECE 411 Capstone Design II
### Manhattan College, Electrical & Computer Engineering

**Faculty Mentor:** Dr. Wafa Elmannai

### Capstone Team:
- Kevin Shaholli
- Matthew Del Cid
- Kevin Orozco
- Joel Mendez

## Table of Contents
1. [Team Members](#team-members)
2. [Abstract](#abstract)
3. [Problem Statement / Big Picture](#problem-statement--big-picture)
4. [Need Statement](#need-statement)
5. [Objective Statement](#objective-statement)
6. [Background Survey](#background-survey)
7. [Project Selection](#project-selection)
8. [Proposed Approach](#proposed-approach)
9. [Global & Societal Impact](#global--societal-impact)
10. [Marketing Requirements](#marketing-requirements)
11. [Engineering Requirements](#engineering-requirements)
12. [Needs Identification](#needs-identification)
13. [Objective Tree](#objective-tree)
14. [Project Motivation](#project-motivation)
15. [Alternative Approaches](#alternative-approaches)
16. [Project Description](#project-description)
17. [System Overview](#system-overview)
18. [Related Theory](#related-theory)
19. [Functional Decomposition](#functional-decomposition)
20. [Behavior Modules](#behavior-modules)
21. [Hardware Design](#hardware-design)
22. [Software Design](#software-design)
23. [Design Iterations](#design-iterations)
24. [Testing Procedure](#testing-procedure)
25. [Testing Results & Analysis](#testing-results--analysis)
26. [Project Timeline](#project-timeline)
27. [Project Completion & Future Work](#project-completion--future-work)
28. [Risk Analysis](#risk-analysis)
29. [Cost Analysis / Breakdown](#cost-analysis--breakdown)
30. [Project Demonstration](#project-demonstration)
31. [Codes, Standards, Constraints](#codes-standards-constraints)
32. [Ethics](#ethics)
33. [Engineering Complexity](#engineering-complexity)
34. [Team Member Contributions](#team-member-contributions)
35. [Conclusion](#conclusion)
36. [References](#references)

---

## Team Members

### Kevin Shaholli
**Role:** Project Manager, Electrical Engineer  
**Interests:** Renewables and Energy  
**Expertise:** Interconnection, Solar Array Design, Computer-Aided Design, Energy Calculations, Electrical Installation

### Matthew Del Cid
**Role:** Hardware Systems Engineer, Electrical Engineer  
**Interests:** Hardware and Design  
**Expertise:** Electronics System Design, Lab Instruments, Testing and Simulation, Analog Circuit Debugging

### Kevin Orozco
**Role:** Full-Stack Software Engineer, Computer Engineer  
**Interests:** Software Development and Cybersecurity  
**Expertise:** C++ and Python Programming, Cybersecurity Systems and Implementation, Web App Development, Linux/Unix Operating Systems

### Joel Mendez
**Role:** Full-Stack Software Engineer, Computer Engineer  
**Interests:** Machine Learning and Artificial Intelligence, Web Development  
**Expertise:** C++, Python, HTML, CSS, JavaScript, SQL

## Abstract
This project will investigate the economic and environmental benefits of utilizing solar tracking technology in commercial solar panel systems. By continuously adjusting the azimuth of solar panels to maximize exposure to sunlight throughout the day, solar tracking systems can increase energy production and efficiency. Additionally, the environmental benefits of solar tracking systems, including reduced carbon emissions and reliance on fossil fuels, are implemented through this project's design. The results of this solar tracker will demonstrate the potential for commercial companies to achieve sustainable benefits through the adoption of solar tracking technology.

## Problem Statement / Big Picture
In the grand scheme of this project, we plan to make solar tracking a better option for commercial rooftops. The participation of this sector in the movement towards sustainable energy could revolutionize industry and put an end to the need for fossil fuels. The environment and economy can both thrive in the future with solar-tracking technology.

## Need Statement
In today's rapidly changing world, the imperative to shift towards greener energy production methods has never been more urgent. With a growing global population, increasing urbanization, and expanding industrialization, our energy demands are soaring. However, this growing energy demand is coupled with a heightened awareness of the environmental damage created by conventional energy sources. Climate change, air pollution, and resource depletion are among the pressing concerns that necessitate a transition to cleaner, more sustainable energy alternatives. The adoption of green energy production, such as solar, wind, and hydropower, offers a promising solution. Not only can it help mitigate environmental impacts, but it can also reduce our reliance on limited fossil fuels. Embracing green energy is not just an environmental choice; it is a strategic imperative to ensure a better environment and a more secure energy future for generations.
Solar tracking panels represent a transformative leap in green energy production. Unlike fixed solar panels, which are static and can only capture sunlight optimally during specific hours of the day, solar tracking panels dynamically follow the path of the sun, continually adjusting their orientation to maximize sunlight absorption. This technology offers an increase in energy production, making it an invaluable asset for sustainable power generation. Solar tracking panels can significantly boost the efficiency of solar systems, ensuring that a larger portion of available sunlight is harnessed, leading to increased energy production. This innovation not only benefits residential and commercial users by enhancing their energy self-sufficiency but also contributes to a cleaner, greener environment by reducing reliance on fossil fuels. Solar tracking panels are a beacon of hope in our pursuit of a more sustainable energy future.

## Objective Statement
Solar-tracking technology is a critical component of our project, enabling us to dynamically adjust the orientation of the panel to maximize the amount of sunlight captured by the panel. For that reason, our innovative approach will aim for a more sustainable, cost-effective, and lightweight solar panel that will benefit these buildings in the commercial sector.
## Background Survey
In the growing world with a need for energy, we have had to resort to different ways of creating energy. A big source of green energy that is being pushed out into the world is solar panel energy production. Most companies are creating solar farms that are placed in big open spaces to help produce green energy that can be put back into the grid that can be used by people. Panels when it was first implemented, it was unable to move and were placed at a set location. To help improve production, companies began to create panels with a signal or dual axis to help it move toward the sun's direction. [1]

<img width="468" alt="Picture1" src="https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/8e88928b-99df-4709-b42d-5fde9b19608f">

To make these panels move to the correct location a software algorithm must be installed into the microcontrollers to give commands to the axes. The microcontroller is given data from the sensors in the panel or a similar area around the panels. Most versions of solar tracking today use photo resistors which react to the amount of sunlight used. They gather information from the radiation that they receive from the sun to send information to the component controlling the axis of the panels. The only issue with these solar trackers is that they begin to increase the maintenance cost of the solar panels. This prevents companies from fully engaging since extra costs must be made on maintenance for the axes, the microcontroller algorithm, and the stand that the panel is on. Some companies have happened to excel in creating a solar tracking system. 
	The Solar Star projects, located in California, have established themselves as pioneering solar tracking farms, harnessing cutting-edge technology to achieve exceptional efficiency in power generation. Their use of single-axis tracking is a hallmark of their design, allowing the panels to follow the sun’s path from east to west.[1] By continuously adjusting the horizontal angle of the panels, they maximize their exposure to direct sunlight, ensuring that every beam of sunlight is captured efficiently. This comprehensive approach to solar tracking ensures that the Solar Star projects maintain peak performance throughout the day, delivering the highest possible overall efficiency in power generation and contributing significantly to the renewable energy landscape in California.

## Project Selection
We chose to build a solar tracking system for our capstone project because we wanted to see how we can use our engineering concepts from our education to improve upon existing solar panel array design. Concepts like computer vision are heavily emphasized because of our experience and education with such concepts, as well as their benefits to the application of solar. We aim to demonstrate how implementing modern technologies can advance renewable energy towards the future that it is planned to part in. Overall, we believe that our project will showcase the potential of solar tracking and make an impact towards its overall implementation.
## Proposed Approach
Our solar-tracking system will have a housing enclosure at the base, protecting the necessary components as well as stabilizing the solar panel. Within this enclosure will be a rechargeable 12 V battery, an accessible charge controller, and a microcontroller. From the base will emerge a vertical racking system, providing enough clearance between the panel and base for optimal movement. Leading up and inside the racking will be any necessary wired connections from the microcontroller. These connections will be for the motors and the camera module. Towards the top of the racking, attached to the panel, will be our dual-motor system. There will be two motors that will allow the panel to rotate in each axis. The camera will be placed beside the panel, so as not to get blocked by any resulting shade. Once the camera detects the point of most light, the microcontroller will direct the panel to face towards it. 

	While solar-tracking technology has been around for years, it is not properly optimized for commercial use. In 2020, only 3.5% of commercial buildings in the U.S. had solar panels on their roofs, even though commercial solar has the potential to hold up to 145 Gigawatts. To create a design that is more marketable to the commercial market, we will have three main objectives. We will use tracking to improve efficiency, lower cost, and lower weight from current large-scale solar trackers.

## Global & Societal Impact
The global impact of commercial solar tracking is significant as it helps to reduce the world’s reliance on harmful energy sources such as oil and gas. By utilizing the power of the sun to generate electricity, commercial solar tracking systems can reduce carbon emissions and lower the effects of climate change. This shift towards renewable energy sources can reduce the dependency on limited fossil fuels.
On a societal level, commercial solar tracking can create job opportunities and promote economic growth in the green energy field. Installing and maintaining these systems will require solar technicians and electricians. Designing these arrays will require electrical and mechanical engineers. Additionally, the use of solar power can lower energy costs for corporations. Overall, commercial solar tracking systems can drive positive global change by promoting clean energy production.

## Marketing Requirements
In addition to surveying current commercial implementations of solar tracking, we spoke with an engineer working in the national solar industry to determine our requirements.
1.	The system must be simple to install relative to a normal solar array.
2.	The system must be inexpensive to produce.
3.	The system must be lightweight.
4.	The system must generate more power because of being a dual axis tracker.
5.	The system must be safe to install and use.
6.	The system must have a long lifespan.
7.	The system must allow the user to monitor energy production.
8.	The system must be durable.

## Engineering Requirements
Requirements include support for the panel at all tilting angles, accurate camera positioning, durable mechanical systems, and lightweight construction to support large arrays on rooftops.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/e503aa22-d494-43a9-85c2-2bb4aa82eb5e)

## Needs Identification
Key needs are lightweight, affordable, durable, efficient, and safe components and systems.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/bea6708e-617d-4bef-9f4b-70965815b922)

## Objective Tree
The objective tree will detail the primary and secondary goals of the project, focusing on maximizing efficiency and minimizing costs.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/147b300c-9456-41e8-b52d-36bcaab84cba)

## Project Motivation
The world today stands at a critical dilemma in its relationship with energy consumption and the resulting environmental impact. The relentless pursuit of conventional energy sources has left a negative mark on our planet, manifesting in the form of pollution, climate change, and depleted natural resources. Our reliance on fossil fuels and inefficient energy technologies not only accelerates environmental harm but also poses a significant threat to global health, and the stability of ecosystems. As we deal with these challenges, it is imperative to transition towards more sustainable and less harmful sources of energy. Innovations in renewable energy technologies are seen as a beacon of hope, offering a pathway to reduce our carbon footprint and mitigate the adverse effects of energy production on the environment.
In traditional solar tracker projects that rely on photoresistors for orientation towards the sun and due to the huge amount of mechanism required to build and maintain these panels, these are not very cost-effective pieces of equipment. For that reason, we concluded that we need to help create a more efficient, cost-effective, and lightweight solar panel to help us get an edge on this issue. Solar panel embodies the forward-thinking solutions required to propel us towards a more sustainable energy future. Its deployment could play a pivotal role in reducing our reliance on polluting energy sources, contributing to a cleaner, healthier planet for generations to come.

## Alternative Approaches
An alternative approach to this project is to create a smaller-scale version of the solar tracking system. That version could be more tailored to the residential or portable solar market. Such a prototype would include photoresistors alongside the panel, directly communicating with an Arduino or similar basic microcontroller. We feel targeting the commercial sector would be more effective for a solar-tracking system and create a larger impact on renewables.
## Project Description
Our commercial solar tracking system consists of three main components: solar tracking camera module, motorized racking system, and battery storage. The camera module tracks the light in the sky, sending coordinates to the ESP32 microcontroller. The coordinates of most light are then used by the motors to determine where to move the panel. Finally, the attached solar panel takes advantage of the light by charging the lead acid battery through a charge controller. The battery in turn powers the entire system, ensuring a self-sustaining design.
	The ESP32 microcontroller will make use of a local Wi-Fi connection to send data to our Sunnyside Upgrade web application. This web application is intended for use by our customers. When having our system installed, they will be able to check the battery charge, current tilt position, energy production, and weather conditions. Additionally, customers will be able to view the live camera feed at any time. These features aim to provide the user with confidence and knowledge of their system and its efficiency compared to a standard solar panel array.
	Commercial solar tracking aims to be a modern energy solution for corporations and building owners. Our goals are to improve efficiency, lower cost, and lower weight, from the alternatives on the market. With the current commercial sector largely untapped due to previous limitations, we plan to work towards a future that embraces solar tracking technology.

## System Overview
The system's core lies within the ESP32 microcontroller, which was programmed with Arduino code to perform various tasks. It facilitates communication with a python script running on a separate computer. This script allows for processing real-time video feeds from the camera module connected to the ESP32, allowing for accurate readings of the sun’s position using computer vision and image processing techniques.
The ESP32’s functions extend to hosting a webpage, enabling remote monitoring and control of the system, as well as managing the motor mechanisms that adjust the solar panel’s tilt. These adjustments are influenced by the results from the python script, with all calculations for retrieving the actual angle coming from the ESP32. Furthermore, the ESP32 oversees the charging of a battery through the solar panel and the associated charge controller. The battery is integral to the self-sufficiency of the system as it is used to power the system, including the ESP32 and motors, which is then in turn charged by the power generated from the solar panel.  
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/e6d4581d-4ebc-4fcc-a811-31e93736d45f)

## Related Theory
Traditionally, solar tracking systems operate on known positions of the sun. However, because we want to focus on the optimal position of the panel, accounting for obstructions, we must operate using computer vision algorithms to achieve the optimal angle. The equations below show the typical angles for each season throughout the year.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/587f3f3f-1bab-4206-a504-678b4fff7b77)
As mentioned, avoiding these calculations requires various computer vision and image processing techniques such as grayscale conversion, thresholding, contour detection, and centroid calculation. Grayscale conversion and thresholding are essential techniques for the functionality of the algorithm. Grayscale conversion simplifies the image by reducing the color obtained into a single intensity, representing the luminance of each pixel. Thresholding takes each pixel and marks each pixel white or black based on a threshold value. This method effectively isolates the brightest areas of the image, allowing for precise identification and measurement of sunlight concentration. Equations for both these functions are shown below:
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/1577a6f1-a412-4752-9450-b29c819fe1f7)
After these image-processing techniques are employed, the last step is to perform a search of the contours in the image and calculate the center of the region. In computer vision, a contour is a curve joining all the continuous points, having the same color or intensity. This is implemented using a function called cv2.findContours. Additionally, the center of the region is also calculated. Both these processes are shown in the figure below.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/983f8d0d-236a-4c56-9408-24c35fcb7521)
After the algorithm returns the center coordinates, the servo motors are adjusted accordingly. The servo motors are adjusted in such a way that the center coordinates always remain in the middle. After each check, depending on the thresholding value for incrementing the angle, the panel will move in such a way that the light remains centered, thus the panel facing the direction with the lightest.
For this solar power monitoring, we're using a 12V battery (Vin) as our storage source. To display the charge level on a website, we need to transmit a signal to the microcontroller that corresponds to the solar energy being produced. However, the ESP32 microcontroller can only handle a maximum voltage of 3.3V. To safely step down the 12V battery voltage, we've employed a voltage divider circuit with a 7K ohm resistor (R1) and a 2.1K ohm resistor (R2) connected in series. This configuration creates a maximum voltage drop of 2.7V (Vout), which is within the ESP32's safe operating range and allows us to represent a fully charged battery on the website accurately. Then to monitor the battery percentage, a separate calculation is necessary. The voltage divider and percentage equations are shown below:
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/ee70e17e-10ab-4353-9a68-c5a712b04d5c)

## Functional Decomposition
Details the main functions of each component, from power management to data processing and physical adjustments.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/e5cddfa3-cd8c-44a4-9677-d8f416474c5d)

## Behavior Modules
In the hardware behavior diagram, we can see that we connected various components that helped us construct our project. We can begin by looking at the battery at the bottom right. The 12V battery will be connected to our charge controller which be the main connecting source for our project. The charge controller will be connected to the solar panel and ESP32. The Power produced by the panel will flow to the battery and the power stored in the battery will flow through the controller which will send that information to the ESP32. That information received by the ESP32 will send that voltage reading to the website which will display the data. Connected to the ESP32 shall be the 2-servo motor and the camera module. Data will be collected from the image in the camera module and will be sent to the ESP32. The ESP32 shall analyze the information received and from that shall give instructions if the motors need to move in a certain direction. The motors will be placed under the solar panel and shall be oriented to give us the capability to control the panel's movement on two axes. This orientation we found to make it possible for us to create an efficient solar tracking panel. 

![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/cb318650-80ab-476e-bb0d-7bb0f1806915)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/d9fbf841-100f-4d71-8aeb-65de4859fc5d)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/c6963f8d-2b5f-4dc1-8900-2036296b3ade)

## Hardware Design
As previously mentioned, we used various components in our hardware design that can be seen in the schematic below. We shall start with the 12V battery that is connected to a voltage divider that consists of a 7 k Ω and 2.1kΩ resistor. This was done to step down the voltage so it can transmit a saver reading into the ESP32 which has a max voltage intake of 3.3 V. This was done so that the 3.3 V can be perceived as the battery being fully charged at 100% and if a lower voltage was to be read on the ESP32 such as 3.0V then is correlates to being only 95% charged which will be displayed on our website. This divider will be plugged into GPIO 34 which will receive all the information that will be sent to our website. Moving forward we can see that our camera module is also connected to MOSI, MOSO, SDA, 3.3V pin, ETC which was needed for the ESP32 to be able to work and send information between each other to use our computer vision aspect of our project. Finally, the last sections that were connected to our ESP32 were our 2 servo motors. One motor is connected to GPIO 13, and the other is GPIO 12. We connected a 330 Ω resistor to those pins which were sending the signal to the motors giving it instructions on how they will move in coordination with the information received by the camera module. We then powered the motors from the 3.3V output pin on the ESP32. Before going to the motor, we placed a 100 µF capacitor between the 3.3V output and the servo motor to help reduce any unwanted noise to our motors. This makes it so that the panel does not shake because the noise from the ESP32 causes the motors to jitter and shake which makes it not for optimal use when attached to a panel. Below can be seen a better depiction of the hardware scheme.

![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/702d9393-1f7b-496d-b12c-e55f29ce5140)

Below can be seen the final construction of our hardware. A charge controller was added to our circuit to help us monitor if the battery is being charged or overcharged by the light indicator that is on the component. It also gives us a safer connection between all components to prevent any danger that could occur with the high voltage.

![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/d6a3a686-765a-4eb7-bfa6-d1064dc57b92)

In the figure below, we can see our two iterations used in our construction process. On the first iteration which is on the left we used a PIC16f887 microcontroller. In our first trials we attempted to connect the PIC16f887 microcontroller with the servomotors, but it was mentioning errors and it also used C++ as a coding language to flash code and we were having multiple issues. We also had to create the circuit around the circuit such as the crystals, the capacitor, and resistor to make it work. 
	We ran into multiple issues in this iteration, and we moved onto our second iteration which consisted of using an ESP32. This worked for us exceptionally and we stuck with this iteration. It made it easier to flash code onto the ESP32 and we were able to use a more favorable code language that we were more experienced with. We were able to flash code easier and reboot the microcontroller if anything went wrong with the code which made it easier to test our code on our components. It was also very compatible with our servomotors and camera module. The connection to these components made it better to work with. Transferring information to the ESP32 in the form of voltage was easier which made it an excellent selection for use to implement out voltage divider to send information on the battery percentage. With everything working in that iteration, we just began to improve it by making the wires better and adding capacitors to redo noise going to our motors to make it more stable in the final construction which can be seen in Figure 9 which shows our final iteration.

![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/15ededbe-7245-46db-baba-1f3d72081e1a)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/381a1999-e25d-4d20-b7ca-cd0539e819ee)


## Software Design
The software architecture of our solar tracking system is divided into two primary components: the Arduino code flashed on the ESP32 and the Python script running on a separate computer. This section provides an overview of how these software components interact with the hardware components to obtain full functionality of the solar tracking system.
ESP32 Side
	The ESP32 microcontroller is programmed using Arduino code. The software implementation for the Arduino code includes camera and servo control, network configuration, and web server functionality. The ESP32 initializes and controls an ArduCAM and two servo motors. The camera will capture images analyzed to determine the area of most light. Based on this analysis, the ESP32 will adjust the servo motors accordingly to have the panel face in the optimal direction for energy production.
	The ESP32 is also responsible for handling the web server functionality of the project. The web server allows the ESP32 to communicate with the Python script used to perform the necessary computer vision component of the project. This server handles requests for capturing images, streaming video, updating servo angles based on computed coordinates, and providing system status updates such as battery percentage. The figure below shows all the major functions performed by the ESP32.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/ec05a620-919b-41b9-80f6-01b3730a7fc2)
Python Side
	The Python script is responsible for performing the computer vision aspect of the project including the image processing and transmission of coordinates to the ESP32. The computer vision algorithm uses a variety of image processing techniques to isolate the area with the most amount of light. The implementation was made possible with the open-source library OpenCV. The algorithm implemented uses image processing techniques such as grayscale conversion, thresholding, and finding contours in the image. Additionally, results are displayed using a basic GUI, to assist with debugging. The figure below shows the functions implemented by the Python script.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/28a8edc2-2a05-4092-bbc6-58e787552b05)
Web App
	The web application is directly served from the ESP32, providing a user interface for monitoring the state of the panel. This app was built with HTML, CSS, and JavaScript, and allows users to: View the camera stream to monitor the panel’s alignment with the sun, monitor the weather for all panels, and view system status, such as battery level and energy production. 
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/2c87bad5-5ca5-419a-908c-bcb9403ad29a)

## Design Iterations
The image above shows the humble beginnings of what has become a more sophisticated solar tracking solar panel system. The image on the left shows our first attempts using a microcontroller without much flexibility. This would require us to create components from scratch. We decided to move from this design to a new one using a microcontroller that comes with the necessary functionality. The second and third images are of the first design with a new microcontroller, the ESP32. A proof of concept, where the main goal was to test the servo motors to see how they would interface with the ESP32. 
This picture shows our latest iteration and a notable addition to the project: the camera. Adding the camera marked a significant step forward from the initial design which only consisted of the microcontroller and servo motors in isolation. Although they were still not integrated into a cohesive system, the presence of the camera allowed us to test the original algorithms for detecting the greatest source of light and adjusting the positions of the servo motors to optimize solar panel energy production.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/cea70a6f-cee2-4550-ad43-4de354c68c87)
## Testing Procedure
Individual Component Testing:
The first phase of our testing procedure involved a meticulous examination of each component in isolation. The microcontroller was the foundational test subject, beginning with a simple program affirming operational status followed by sketches to probe the functionality of all I/O ports. Moving onto the servo motors, a sweep test was conducted to ensure they could move properly and achieve their full range of motion. This also included a load test confirming their capacity to bear the solar panel’s weight. The solar panel itself was tested by subjecting it to various intensities of light. We measured voltage output and identified the optimal angle for peak energy production: straight ahead. The battery was tested by connecting it to our servo motors in isolation. Without other power sources attached we could determine whether the battery sufficiently powered the components of our system. Finally, the camera was tested for image clarity and data transmission. The picture fidelity is not a significant concern for our application since our solar panel tracker application will only need to be detecting differences in light rather than any other technical image processing. For our application, the camera functioned as needed and integrated seamlessly with the microcontroller for near-real-time image analysis.
Software and Integration Testing:
With individual components tested, our attention shifted to the software realm and the task of harmonizing these elements. The solar tracking algorithm underwent simulation under diverse lighting scenarios, such as outside lighting, indoor lighting, and a moving light source simulated with a flashlight. There is still work to do in fine-tuning it to calculate the solar panel’s ideal positioning throughout the day accurately. We then tested the responsiveness of the servo motors, now equipped with light sensors, to react to variations in light so the solar panel can be adjusted accordingly to the brightest available light. The web app was next in line tested to ensure a fluid user experience and the ability to deliver near-real-time data such as positioning, camera output, and battery levels. The client-server setup was validated through a series of communication tests between the microcontroller and server to confirm the exchange of data packets and the server’s capacity to process requests from the web app. The final stage of our testing was an exhaustive end-to-end system evaluation, where all components were united. This was most important to ensure that when working together, the system sustained functionality and exhibited the desired stability over prolonged usage. 

## Testing Results & Analysis
Presents detailed results of the testing phases, including functional and performance tests, and discusses the implications of the findings.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/2d85dc11-3b09-4fc6-ad8f-19ae980756cd)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/bf81c87b-bbc3-4071-908d-95bde1e0c670)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/f71b0b2d-7882-46b8-b28a-45eec439b708)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/3a3ef5d3-c730-468b-9fc7-4e3753058a97)

## Project Timeline
Provides a visual timeline of the project's milestones and development phases.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/e0f558f3-e9d0-4206-9527-12d2c5719ba0)

## Project Completion & Future Work
We are on track to complete the project based on our project timeline. The first semester consisted of researching the means to build the project. Once determined and purchased, we experimented with different hardware iterations to see which fit our needs best. This consisted of different chips and microcontrollers until we settled on the ESP32. With our microcontroller in hand, we connected our external components to it to see how they interfaced with the device. We were able to control the servo motors with the microcontroller, completing our beginning steps with the hardware. Afterward, the motors were mechanically mounted with the panel, to move it towards the sun. At this point, we began to focus on the computer vision software. While having Arduino code to operate the motors worked, we chose to have the computations of tracking light done in python. Once that software was completed, we integrated it to our camera module, so it can interface with the ESP32 which is connected to the motors. With the main components working, we had to create the racking structure and power our system. The structure is held together with a combination of steel and wood. It is sturdy enough to hold the panel at any angle. The battery not only powers the solar tracker separate from a computer, but it in turn gets charged by the solar panel. 
	With the bulk of the project completed, we have two tasks left in our future work. Those are testing and optimization. Testing is important to ensure that the final product does not have any flaws that we cannot repair. Performing tests also leads to optimization. By finding flaws in our system, we can learn how best to improve it. Specific optimizations we plan to implement are a more accurate solar tracker, simplified hardware design, and racking that is stable while holding all our components.

## Risk Analysis
Engineering design inherently comes with more risk the larger it is scaled to. Therefore, we have taken steps to identify issues beforehand and prevent them from affecting their users once installed.
	The first risk we identified when designing the system is structural stability of the solar panel. To provide a lightweight product, the size of the racking structure must be minimal and easy to install. However, this cannot compromise the structural integrity of the panel. Additionally, the addition of shifting tilt angles alters the force onto the system throughout the day. While a unique challenge to active solar tracking, it is one that must be considered. To combat this, the solar panel is tested to move across numerous different angles that would be realistic in a real-world application. This will also include testing the speed and strength of the panel movement across wide gaps in light, to make sure the racking can support quicker and wider movement. The software will prohibit the panel from tilting at any unexpected angles that would compromise the safety of the system and its users. 
	Moving past the support of the panel is the solar energy generation and storage. When working with electricity, it is important that dangerous hazards such as electric shock and fire are accounted for. The microcontroller will constantly be monitoring the voltage of the charged battery from the solar panel, using that information for battery information. If the voltage read is ever unstable or higher than normal, the user would be able to see those effects through the web app and call for maintenance of the system. The open-face design under the panel allows for easy access to fix issues before they become dangerous. Additionally, the connected charge controller provides a level of separation between the energy generated and the power to the system.
	Implementation of a web application that tracks your solar tracker system also calls for security risks. It is imperative that the information collected is only accessible by the user and their organization. The addition of account credentials provides a simple solution to this problem. Users will be able to log in with their company credentials to access the information. That web page will only be private to them, to avoid unwanted tracking of their energy usage. 

## Cost Analysis / Breakdown
We are excited to share the financial details of our latest project. This has been a real focus for us - making sure we can deliver an innovative, sustainable solution in a cost-effective way. The budget we set aside for production was $200. But through careful planning and smart use of resources, we were able to complete the project for just $175.39. This is an impressive result, and it shows we are committed to quality without breaking the bank. The materials we selected were a big part of keeping costs down, but we never compromised on the standards or specifications. This is a commercially viable design that is also eco-friendly. 
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/a0c7469e-f8ba-4fcc-9d10-e37b1fb56e66)

## Project Demonstration
Illustrates the functioning of the solar tracker and its components, including the web application and computer vision capabilities. (refer to top)

## Codes, Standards, Constraints
The diversity in codes, laws, and standards pertaining to solar energy across different states presents a significant consideration in the design of our final product. This variance necessitates a flexible approach to ensure compliance with the local regulations governing the installation and operation of solar energy systems. Additionally, our design is constrained by the necessity to avoid heavy solar panels, adhering strictly to Section 1503 in the International Building Code (IBC) [6], which governs the structural requirements for such installations. This stipulation is particularly critical given our project's major focus on deploying solar energy systems on larger commercial rooftops and carports. This focus is driven by the desire to maximize the utility and efficiency of solar energy in spaces that are both abundant and underutilized, thereby contributing to the broader adoption of renewable energy sources in commercial settings.
Other Standards we will be using include:
•	IEC 62817
The primary purpose of IEC 63817 Ed.1.0 is to ensure the safety and reliability of 	electronic devices by establishing clear requirements for the design, testing, and 			validation of software tools and systems. This standard covers a wide range of topics, 		including software requirements, testing procedures, and validation techniques. [8]
•	UL 3703
Ensures that a solar tracker has met the stringent safety requirements of the National Electrical Code. Involve rigorous inspection and evaluation of a tracker platform and all the trackers’ mechanical and electrical aspects, including mounting, bonding, and grounding, as described in an installation manual. [9]
•	UL 2703
The Standard for Mounting Systems, Mounting Devices, Clamping/Retention Devices, and Ground Lugs for Use with Flat-Plate Photovoltaic Modules requirements for ground-mounted and roof systems as part of a nonstructural building component. Used to determine the fire classification of a rooftop-mounted PV system as required for compliance with the building code requirements, which is to maintain the roof's fire performance integrity. It is looking at the overall installation resistance to external fire exposure. [9]

## Ethics
Ethical considerations play a pivotal role in our project and various others, necessitating a careful examination of potential ethical dilemmas. One significant aspect involves patented designs to ensure our project remains ethically sound. Fortunately, the passive nature of our design and its resemblance to similar projects mitigates this concern as a primary issue. Our ethical focus centers on two key codes: Code number 5, emphasizing the imperative to enhance comprehension of technology, its judicious application, and the potential repercussions. In our project we want to create a device that can be used successfully by the consumer and gives us a better technologically advanced piece of equipment. [7] Additionally, Code number one takes precedence, highlighting the commitment to accept responsibility for decisions aligning with the safety, health, and welfare of the public. [7] This code underscores our dedication to promptly disclose any factors that could jeopardize the well-being of the public or the environment, reinforcing our ethical responsibility throughout the project's lifecycle. [7] We want to create a safe working piece of hardware that cannot harm any of the users or anyone near the equipment.
## Engineering Complexity
This project employed various engineering principles, particularly in computer vision and embedded systems. For the computer vision portion of the project, various image processing techniques were used to isolate the position of the sun. Embedded systems were used in the form of the ESP-32 microcontroller, which is the main processing unit for our entire project. Additionally, we incorporated other modules such as a 12V rechargeable battery, an accessible charge controller, servo motors, and the solar panel.
Our solar tracking project is inherently complex, and we acknowledge the sophisticated nature of this endeavor. Not only is the scale ambitious, but the work also intersects multiple engineering disciplines. Leveraging computer vision techniques for optimal solar positioning, combined with the intricate workings of embedded systems powered by the ESP-32 microcontroller, forms the core of our project's technical complexity. Our team has navigated a myriad of engineering challenges - from developing an algorithm capable of precisely tracking the sun's ever-changing position in the sky, to seamlessly integrating a range of components, including a 12V rechargeable battery, a user-friendly charge controller, and the pivotal servo motors. These elements must work in perfect concert to reposition the solar panel in real-time. This multi-level approach not only elevates the technical sophistication of our project but also underscores the remarkable expertise and collaborative spirit of our dedicated team.
 This profound complexity, coupled with our commitment to rigorous testing and optimization, also amplifies the risk factors associated with our solar tracking system. As we push the boundaries of what is possible in the commercial solar power domain, we tread carefully, mindful of the responsibilities that accompany such innovation. With each calculated step, we ensure our system is structurally robust and adheres to the highest safety standards, all while maintaining the delicate balance of providing a lightweight and efficient solution. This project not only represents an engineering marvel but also serves as a beacon of sustainable and renewable energy solutions. Our aspirations are to enable commercial entities to harness the sun's power with unparalleled efficiency and reliability, paving the way for a future of greater energy independence and environmental stewardship.

## Team Member Contributions
Sunnyside Upgrade made use of digital means such as Google Meet and Discord to coordinate in-person meetings. Most of these meetings consisted of the full team, where each member contributed towards not only their assignments, but assisted others if needed. Whenever necessary, specific members would meet outside of these time slots to complete smaller individual tasks. In between these meetings, the team kept communicating to share research and ideas on how to implement each feature. This proved to be valuable, as we attended each meeting prepared with the information that we had discussed with each other online. To manage our time effectively, each team member took charge of completing tasks specialized to their interests and expertise.
•	Kevin Shaholli took the role of Project Manager. This entailed scheduling the meetings, researching technical documentation, purchasing parts, and assigning tasks to the team via work packages. In between management, Kevin designed the system's layout, the circuitry behind the solar panel, and the racking structure of the project.
•	Matthew Del Cid led electronics as a Hardware Systems Engineer. The hardware and circuit design were put together by Matthew. He was also in charge of researching the electronics required, and testing if the designed circuits were operable. Features such as the battery storage, step-down voltage, and servo motor control were led by Matthew.
•	Kevin Orozco oversees web development as a Full Stack Software Engineer. He customized the UI of the web application to suit our requirements for the project. When gathering information such as tilt and battery charge, Kevin found how to send live data from the system to the web application. 
•	Joel Mendez focused on the development of our solar tracking software as a Full Stack Software Engineer. This includes computer vision that allows our camera to recognize where the sun is located. His software allows us to communicate that information to the microcontroller, where the motors are then told how to operate to move the solar panel accordingly. 
It is important to recognize that no task is strictly individual. Throughout the design process, both electrical engineers worked together on the hardware, and likewise for the computer engineers for software. At points where one aspect was more crucial, members from outside their expertise would assist in ensuring that the team stayed on track with our timeline.

## Conclusion
Through this project, we are proud to have demonstrated the immense potential of solar tracking technology for commercial applications. By leveraging computer vision and embedded systems, we have been able to develop a solar tracking solution that significantly boosts energy production and efficiency compared to traditional static panels. The detailed design process, rigorous testing, and thoughtful consideration of economic, environmental, and safety factors have all coalesced into a robust, viable system. We believe this project serves as a blueprint for how commercial entities can harness the power of the sun more effectively and reliably.
 	Looking ahead we will focus on further refining the accuracy and durability of the system. Simplifying the hardware to streamline installation will also be a key priority. But the foundation is strong - integrating real-time monitoring through the web app, ensuring safety and code compliance, and demonstrating the technical complexity that underpins this innovation. This project represents a significant step forward in accelerating the adoption of renewable energy solutions in the commercial sector. By making solar tracking more accessible and impactful, we hope to contribute to a future where businesses can reduce their carbon footprint, enhance their energy independence, and do their part in building a more sustainable world. The journey continues, but we are excited about the possibilities that lie ahead.

## References
[1] B. Ludt, "What is a solar tracker, how does it work, and how many types are there?," Solar Power World. [Online]. Available: https://www.solarpowerworldonline.com/2020/01/what-is-a-solar-tracker-and-how-does-it-work/#:~:text=Single-axis%20solar%20trackers%20track,panels%20track%20the%20sun%20directly. Accessed: Oct. 18, 2023.
[2] C. F. Lewandoski, R. F. Santos, J. P. Man Kit Sio, D. da Costa Canfild, M. Bisolotti do Carmo, F. M. da Silva, J. A. Cruz Siqueira, W. Alves de Oliveira, A. Ikpehai, and R. Reginatto, "Study of the Efficiency of the Solar Tracker System compared to the Fixed Solar Generation System," Research, Society and Development, vol. 11, no. 6, e6711628671, 2022. DOI: 10.33448/rsd-v11i6.28671
[3] F. Pearce et al., "U.S. commercial rooftops hold 145 gigawatts of untapped solar potential," Yale E360. [Online]. Available: https://e360.yale.edu/digest/u-s-commercial-rooftops-hold-145-gigawatts-of-untapped-solar-potential. Accessed: Oct. 18, 2023.
[4] B. Ludt, "What is a solar tracker, how does it work, and how many types are there?" Solar Power World. [Online]. Available: https://www.solarpowerworldonline.com/2020/01/what-is-a-solar-tracker-and-how-does-it-work/#:~:text=Single-axis%20solar%20trackers%20track,panels%20track%20the%20sun%20directly. 
[5] O. Bolt, “How to calculate solar panel tilt angle?” Energy Theory, https://energytheory.com/how-to-calculate-solar-panel-tilt-angle/. 
[6] R. Mayfield, “Navigating NEC Codes for Solar and Solar-Plus-Storage,” Mayfield Renewables, Jul. 11, 2022. https://www.mayfield.energy/technical-articles/navigating-nec-codes-for-solar-and-solar-plus-storage/.
[7] K. Laas, M. Davis, and E. Hildt, Codes of ethics and ethical guidelines: emerging technologies, changing fields. Cham: Springer, 2022.
[8] “IEC,” IEC 62817:2014 | IEC Webstore | rural electrification, solar power, LVDC, https://webstore.iec.ch/publication/7442  
[9] “PV Mounting Systems Certification,” UL Solutions, https://www.ul.com/services/pv-mounting-systems-certification  

