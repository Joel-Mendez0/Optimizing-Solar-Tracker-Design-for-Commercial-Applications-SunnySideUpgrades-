# EECE 410 Capstone Design I
## Optimizing Solar Tracker Design for Commercial Applications

### Team Members
- **Matthew Del Cid**
  - *Role:* Hardware Systems Engineer (EE)
  - *Interests:* Hardware and Design
  - *Expertise:* Electronics System Design, Lab Instruments, Test and Simulation, Analog Circuit Debugging

- **Kevin Shaholli**
  - *Role:* Project Manager (EE)
  - *Interests:* Renewables and Energy
  - *Expertise:* Interconnection, Solar Array Design, Computer-Aided Design, Energy Calculations, Electrical Installation

- **Kevin Orozco**
  - *Role:* Full Stack Software Engineer (CE)
  - *Interests:* Software Development and Cybersecurity
  - *Expertise:* C++ and Python Programming, Cybersecurity Systems and Implementation, Web App Development, Linux/Unix Operating Systems

- **Joel Mendez**
  - *Role:* Full Stack Software Engineer (CE)
  - *Interests:* Machine Learning and Artificial Intelligence, Web Development
  - *Expertise:* C++, Python, HTML, CSS, JavaScript, PostgreSQL

### Submitted to:
Dr. Angelo Devito

### Date:
12/10/2023

## Table of Contents
1. [Meet the Team](#meet-the-team)
2. [Need Statement](#need-statement)
3. [Objective Statement](#objective-statement)
4. [The Big Picture](#the-big-picture)
5. [Background and Survey](#background-and-survey)
6. [Alternative Approach](#alternative-approach)
7. [Analytical Hierarchy Process](#analytical-hierarchy-process)
8. [Needs Identification](#needs-identification)
9. [Marketing Requirements](#marketing-requirements)
10. [Engineering Requirements](#engineering-requirements)
11. [Trade-Off Matrix](#trade-off-matrix)
12. [House of Quality](#house-of-quality)
13. [Proposed Approach](#proposed-approach)
14. [Project Summary](#project-summary)
15. [Related Theory](#related-theory)
16. [Physical Diagram](#physical-diagram)
17. [Software Diagram](#software-diagram)
   - [Solar Tracker](#software-diagram-solar-tracker)
   - [Web App](#software-diagram-web-app)
18. [Functional Decomposition](#functional-decomposition)
   - [Level 0](#level-0-functional-decomposition)
   - [Level 1](#level-1-functional-decomposition)
19. [EECE 410 Go/No Go Milestone](#eece-410-go-no-go-milestone)
20. [Testing Plan](#testing-plan)
21. [Risk Analysis](#risk-analysis)
22. [Cost Estimation](#cost-estimation)
23. [Codes, Standards, Constraints](#codes-standards-constraints)
24. [Ethics](#ethics)
25. [Complex Engineering](#complex-engineering)
26. [References](#references)

### Need Statement
In today's rapidly changing world, the imperative to shift towards greener energy production methods has never been more urgent. With a growing global population, increasing urbanization, and expanding industrialization, our energy demands are soaring. However, this growing demand for energy is coupled with a heightened awareness of the environmental damage created by conventional energy sources. Climate change, air pollution, and resource depletion are among the pressing concerns that necessitate a transition to cleaner, more sustainable energy alternatives. The adoption of green energy production, such as solar, wind, and hydropower, offers a promising solution. Not only can it help mitigate environmental impacts, but it can also reduce our reliance on limited fossil fuels. Embracing green energy is not just an environmental choice; it's a strategic imperative to ensure a better environment and a more secure energy future for generations.
Solar tracking panels represent a transformative leap in green energy production. Unlike fixed solar panels, which are static and can only capture sunlight optimally during specific hours of the day, solar tracking panels dynamically follow the path of the sun, continually adjusting their orientation to maximize sunlight absorption. This technology offers an increase in energy production, making it an invaluable asset for sustainable power generation. Solar tracking panels can significantly boost the efficiency of solar systems, ensuring that a larger portion of available sunlight is harnessed, ultimately leading to increased energy production. This innovation not only benefits residential and commercial users by enhancing their energy self-sufficiency but also contributes to a cleaner, greener environment by reducing reliance on fossil fuels. Solar tracking panels are a beacon of hope in our pursuit of a more sustainable energy future.
### Objective Statement
Solar-tracking technology is a critical component of our project, enabling us to dynamically adjust the orientation of the panel to maximize the amount of sunlight captured by the panel. For that reason, our innovative approach will aim for a more sustainable, cost-effective, and lightweight solar panel that will benefit these buildings in the commercial sector.
### The Big Picture
In the grand scheme of this project, we plan to make solar-tracking a better option for commercial rooftops. The participation of this sector in the movement towards sustainable energy could revolutionize the industry and put an end to the need for fossil fuels. The environment and economy can both thrive in a future with solar-tracking technology.
### Backround and Survey
The Solar Star projects, located in California, have established themselves as pioneering solar tracking farms, harnessing cutting-edge technology to achieve exceptional efficiency in power generation. These projects integrate a sophisticated solar tracking system that combines sunlight sensors, advanced tracking software, single-axis tracking, and horizontal tracking to optimize the energy production of their vast array of solar panels [1]. 

 	At the heart of their system are sunlight sensors strategically placed throughout the solar farm. These sensors continuously monitor the intensity and direction of incoming sunlight. This data feeds into the tracking software, a complex algorithm that factors in the time of day, date, and geographical coordinates to precisely determine the sun’s position. The software instructs the solar panels to adjust their orientation accordingly. The use of single-axis tracking is a hallmark of their design, allowing the panels to follow the sun’s path from east to west. By continuously adjusting the horizontal angle of the panels, they maximize their exposure to direct sunlight, ensuring that every beam of sunlight is captured efficiently. This comprehensive approach to solar tracking ensures that the Solar Star projects maintain peak performance throughout the day, delivering the highest possible overall efficiency in power generation and contributing significantly to the renewable energy landscape in California.
### Alternative Approach
An alternative approach to this project is to create a smaller-scale version of the solar tracking system. That version could be more tailored to the residential or portable solar market. Such a prototype would include photoresistors alongside the panel, directly communicating with an arduino or similar basic microcontroller. We feel targeting the commercial sector would be more effective for a solar-tracking system, as well as create a larger impact on renewables as a whole.
### Analytical Hierarchy Process
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/bf222d0b-5535-443b-9ece-3acb3fabb61a)
### Needs Identification
Creating a more cost-efficient model. Cost is the most important factor, as pricing is the best way to break into the commercial market.
Efficiency is the main drive towards using solar-tracking over normal solar panels. Increasing efficiency at a reasonable cost allows for more energy at a higher rate of production.
Structure will not only prove that the project is stable, but will also last as long as possible. This eliminates waste and lowers production/maintenance costs.
Being able to monitor the energy generated digitally provides an easy way for us to test our product and for customers to manage their systems after installation.
### Marketing Requirements
In addition to surveying current commercial implementations of solar-tracking, we spoke with an engineer working in the national solar industry to determine our requirements.
The system must be simple to install relative to a normal solar array.
The system must be inexpensive to produce.
The system must be lightweight. 
The system must generate more power as a result of being a dual-axis tracker.
The system must be safe to install and use.
The system must have a long lifespan.
The system must allow the user to monitor energy production.
The system must be durable.
### Engineering Requirements
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/616d66ac-b611-472f-ac3e-b7a76af6f9e3)
### Trade-Off Matrix
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/27a581ab-ae57-4cb7-b679-684add4a0f52)
### House of Quality
The following diagram is a House of Quality, which serves as a visual representation that encapsulates the correlation between customer requirements and engineering requirements.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/58786a2f-1756-41de-9ba9-a2da9478001d)
### Proposed Approach
	Our solar-tracking system will have a housing enclosure at the base, protecting the necessary components as well as stabilizing the solar panel. Within this enclosure will be a rechargeable 9 V  battery, an accessible charge controller, and the microcontroller. From the base will emerge a vertical racking system, providing enough clearance between the panel and base for optimal movement. Leading up and inside the racking will be any necessary wired connections from the microcontroller. These connections will be for the motors and the camera module. Towards the top of the racking, attached to the panel, will be our dual-motor system. These will be two motors that will allow the panel to rotate in each axis. The camera will be placed beside the panel, as to not get blocked by any resulting shade. Once the camera detects the point of most light, the microcontroller will direct the panel to face towards it. 

	While solar-tracking technology has been around for years, it is not properly optimized for commercial use. In 2020, only 3.5% of commercial buildings in the U.S. had solar panels on their roofs, even though commercial solar has the potential to hold up to 145 Gigawatts. [2] To create a design that is more marketable to the commercial market, we will have three main objectives. We will use tracking to improve efficiency, lower cost, and lower weight from current large scale solar-trackers.

 ### Project Summary
The goal is to construct solar tracking panels that are not only highly efficient but also cost-effective, making them an ideal choice for large-scale installations, including solar farms and expansive structures like warehouses. We recognize the tremendous potential of solar energy in meeting the rising global demand for sustainable power. By focusing on cost-efficiency, we aim to shatter the financial barriers that have limited the widespread adoption of solar tracking technology. The goal is to introduce this to solar farms and industrial facilities to harness solar power more effectively, thereby reducing their reliance on conventional energy sources and significantly reducing their environmental damage. 
### Related Theory
As one can expect there can be a lot of math that can go behind creating a tilting solar panel. To begin with we can start with the basics. When installing a solar panel, you can install it at an angle to help optimize the power consumption. As we can see in the figure below we can see the equations to help calculate the best tilt angle for any given panel at a certain location. [4]
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/106d272b-45cf-4ad6-bbce-f13278ccb1ba)

The case above works for a non-tilting panel. Which is helpful but in our case since we want to adjust the system instantaneously a lot more equations have to be involved. As we can see in the figure below various variables and angles are involved in this project. We need the angle of the sun in rest to the panel, the angle of the panel with respect to the ground, etc. Below the panel diagram you will find the corresponding equations needed to solve for the optimal tilting angle.[4] As it can be seen it is a very elaborate set of equations that can cause various sets of errors in our project and to avoid any issues we will use a camera module.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/56ef685a-492d-441b-a7a5-3954c1b6ba84)

### Physical Diagram
The following diagram is a representation of the hardware components in our project. The schematic displayed on the left shows the pin input/output of the esp32 microcontroller and the connections to our motors. The picture on the right, shows the breadboard implementation of the schematic.
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/8cd82104-70f5-42dc-86e5-fbfaa238a800)
### Software Diagram (Solar Tracker)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/1c5da174-d4ef-495a-9de2-def49a4a0d9f)
### Software Diagram (Web Application)
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/0a2e24be-a8c9-4b99-be5b-a63d60394e65)
### Functional Decomposition
- [Level 0](#functional-decomposition-level-0)
  ![Level 0](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/b1c0d970-a003-4d01-8f63-3b89ba3d4a90)

- [Level 1](#functional-decomposition-level-1)
  ![Level 1](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/e42682ee-ef36-4367-8e21-7d6c9cac1300)
### EECE 410 Go/No Go Milestone
The timeline of this project spans two college semesters, providing our team with two clear sections for developing this project. We will be dividing this project into a hardware portion and a software portion. For the first semester, we aim to have our schematics complete and our final hardware determined. Using hardware as the basis for our project gives us a structure for moving forward. Especially because in our second semester, is when we will focus on incorporating the software. With the hardware designed, we will be able to assess how the software should go about moving the panel. A completed physical build will allow us to properly test the software, and see how each piece of code affects the final movement of the panel. 
### Testing Plan
	Testing for this project will be done as we move forward throughout its development. This will ensure that every component works properly before we move on to the next. As a result, the final product will have been already troubleshooted. Listed below are the steps for our testing plan:
Run the hardware schematic on simulation software.
Use each component, such as motors and cameras, to access their functionality.
Ensure finished build is structurally sound.
Debug light-tracking software.
Import the programs to the microcontroller.
Test all angles of the solar panel to account for every scenario.
Several iterations for this project were performed to find the best configuration for our project and are listed below:
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/be9a5733-f992-455b-aaa3-ede29d590003)
### Cost Estimation
![image](https://github.com/Joel-Mendez0/SunnySideUpgrades/assets/113056408/731dc522-664c-44fe-8b9e-ff63339242b6)
### Codes, Standards, Constraints
Navigating the landscape of solar energy implementation poses a challenge due to the variations in codes, laws, and standards across different states. This diversity requires careful consideration in the design process to ensure compliance and efficiency. Additionally, our design approach prioritizes the need for a lightweight solar panel, steering away from a heavy structure that could potentially inflict damage on rooftops.[5] This consideration aligns with our commitment to promoting safe and sustainable solar solutions. Our project emphasizes catering to larger commercial spaces, particularly targeting expansive areas like warehouses with significant flat surfaces. This strategic focus aims to maximize solar energy utilization in sectors with substantial land availability, optimizing the impact of our innovative design.
### Ethics
 Ethical considerations play a pivotal role in our project and various others, necessitating a careful examination of potential ethical dilemmas. One significant aspect involves patented designs to ensure our project remains ethically sound. Fortunately, the passive nature of our design and its resemblance to similar projects mitigates this concern as a primary issue. Our ethical focus centers on two key codes: Code number 5, emphasizing the imperative to enhance comprehension of technology, its judicious application, and the potential repercussions. In our project we want to create a device that can be used successfully by the consumer and gives us a better technologically advanced piece of equipment. [6]Additionally, Code number one takes precedence, highlighting the commitment to accept responsibility for decisions aligning with the safety, health, and welfare of the public.[6] This code underscores our dedication to promptly disclose any factors that could jeopardize the well-being of the public or the environment, reinforcing our ethical responsibility throughout the project's lifecycle.[6] We want to create a safe working piece of hardware that cannot harm on any of the users or anyone near the equipment
### Complex Engineering
	This project employed various engineering principles, particularly in computer vision and embedded systems. For the computer vision portion of the project, various image processing techniques were used to isolate the position of the sun. Embedded systems were used in the form of the ESP-32 microcontroller, which is the main processing unit for our entire project. Additionally, we incorporated other modules such as a 9V rechargeable battery, an accessible charge controller, servo motors, and the solar panel. 
### References
[1] B. Ludt, "What is a solar tracker, how does it work, and how many types are there?," Solar Power World. [Online]. Available: https://www.solarpowerworldonline.com/2020/01/what-is-a-solar-tracker-and-how-does-it-work/#:~:text=Single-axis%20solar%20trackers%20track,panels%20track%20the%20sun%20directly. Accessed: Oct. 18, 2023.
[2] F. Pearce et al., "U.S. commercial rooftops hold 145 gigawatts of untapped solar potential," Yale E360. [Online]. Available: https://e360.yale.edu/digest/u-s-commercial-rooftops-hold-145-gigawatts-of-untapped-solar-potential. Accessed: Oct. 18, 2023.
[3] B. Ludt, "What is a solar tracker, how does it work, and how many types are there?," Solar Power World. [Online]. Available: https://www.solarpowerworldonline.com/2020/01/what-is-a-solar-tracker-and-how-does-it-work/#:~:text=Single-axis%20solar%20trackers%20track,panels%20track%20the%20sun%20directly. 
[4] O. Bolt, “How to calculate solar panel tilt angle?,” Energy Theory, https://energytheory.com/how-to-calculate-solar-panel-tilt-angle/. 
[5] R. Mayfield, “Navigating NEC Codes for Solar and Solar-Plus-Storage,” Mayfield Renewables, Jul. 11, 2022. https://www.mayfield.energy/technical-articles/navigating-nec-codes-for-solar-and-solar-plus-storage/.
[6] K. Laas, M. Davis, and E. Hildt, Codes of ethics and ethical guidelines : emerging technologies, changing fields. Cham: Springer, 2022.

