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
This project investigates the economic and environmental benefits of utilizing solar tracking technology in commercial solar panel systems. By continuously adjusting the azimuth of solar panels to maximize sunlight exposure, solar tracking systems can increase energy production and efficiency. The environmental benefits include reduced carbon emissions and reliance on fossil fuels, demonstrated through this project's design.

## Problem Statement / Big Picture
The project aims to make solar tracking a viable option for commercial rooftops, potentially revolutionizing industry energy use and helping end reliance on fossil fuels.

## Need Statement
With increasing energy demands due to a growing global population and urbanization, the shift towards greener energy production methods has never been more urgent. Solar tracking panels represent a significant advance in green energy production, offering increased efficiency and contributing to a cleaner environment.

## Objective Statement
The project focuses on developing a sustainable, cost-effective, and lightweight solar-tracking technology to benefit commercial buildings.

## Background Survey
Initially, solar panels were static and fixed in one position. To improve production, companies began developing panels with single or dual axis movement to track the sun's direction, significantly increasing energy capture and efficiency.

## Project Selection
The decision to develop a solar tracking system for our capstone project stems from a desire to apply engineering concepts to improve solar panel array designs and showcase the potential of solar tracking.

## Proposed Approach
The solar-tracking system will feature a housing enclosure with a rechargeable battery, a charge controller, and a microcontroller. It will include a vertical racking system to allow optimal movement of the panel, controlled by a dual-motor system and directed by a camera module.

## Global & Societal Impact
Commercial solar tracking reduces reliance on harmful energy sources and promotes job creation in the green energy field. It can significantly lower energy costs for corporations, contributing to economic growth.

## Marketing Requirements
The system should be simple to install, inexpensive to produce, lightweight, and generate more power due to being a dual-axis tracker. It must also be safe and durable.

## Engineering Requirements
Requirements include support for the panel at all tilting angles, accurate camera positioning, durable mechanical systems, and lightweight construction to support large arrays on rooftops.

## Needs Identification
Key needs are lightweight, affordable, durable, efficient, and safe components and systems.

## Objective Tree
The objective tree will detail the primary and secondary goals of the project, focusing on maximizing efficiency and minimizing costs.

## Project Motivation
The project is driven by the need to transition towards sustainable energy sources to mitigate environmental impacts and ensure a healthier planet.

## Alternative Approaches
Considering a smaller-scale version for the residential market or portable solar solutions could serve different market segments but focusing on commercial applications promises greater impact.

## Project Description
The system consists of a solar tracking camera module, motorized racking system, and battery storage. It uses an ESP32 microcontroller and a web application for real-time monitoring.

## System Overview
The core of the system is the ESP32 microcontroller, programmed to handle various tasks including motor adjustments based on real-time video feeds and overall system monitoring.

## Related Theory
The project employs computer vision algorithms to determine the optimal panel positioning instead of traditional solar tracking methods, improving the accuracy of sunlight capture.

## Functional Decomposition
Details the main functions of each component, from power management to data processing and physical adjustments.

## Behavior Modules
Describes the interactions between the system's components, including how data flows and is processed to adjust the panel positioning.

## Hardware Design
Outlines the hardware components and their configuration, ensuring they work together effectively to achieve optimal energy capture.

## Software Design
Covers the software architecture, including the roles of the Arduino code on the ESP32 and the Python script for computer vision.

## Design Iterations
Discusses the evolution of the project's design, highlighting changes and improvements made throughout the development process.

## Testing Procedure
Describes the methods used to test each component and the overall system to ensure reliability and efficiency.

## Testing Results & Analysis
Presents detailed results of the testing phases, including functional and performance tests, and discusses the implications of the findings.

## Project Timeline
Provides a visual timeline of the project's milestones and development phases.

## Project Completion & Future Work
Details the current status of the project and outlines plans for final testing and future enhancements.

## Risk Analysis
Evaluates potential risks associated with the project, including structural, electrical, and software risks, and describes measures taken to mitigate them.

## Cost Analysis / Breakdown
Provides a detailed breakdown of the project's costs, demonstrating its economic viability and cost-effectiveness.

## Project Demonstration
Illustrates the functioning of the solar tracker and its components, including the web application and computer vision capabilities.

## Codes, Standards, Constraints
Discusses the regulatory standards and constraints that guide the project's design and implementation, ensuring compliance and safety.

## Ethics
Highlights the ethical considerations of the project, focusing on responsible engineering practices and the safety of the public.

## Engineering Complexity
Describes the technical challenges and engineering principles applied in the project, emphasizing its innovative approach to solar energy tracking.

## Team Member Contributions
Details the roles and contributions of each team member, reflecting on the collaborative efforts and specialized skills brought to the project.

## Conclusion
Summarizes the project's achievements and its significance in advancing solar tracking technology for commercial use, setting the stage for future developments in renewable energy.

## References
- Detailed citations and sources of information used throughout the project report.
