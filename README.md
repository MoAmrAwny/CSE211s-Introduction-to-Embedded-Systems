# CSE211s-Introduction-to-Embedded-Systems
### Description
The goal of this project is to develop an embedded system using C programming that 
gathers real-time positional coordinates while a microcontroller is in motion (GPS tracking 
system using TM4C123G LaunchPad) after power-on until a destination point is reached. 
The collected data will then be efficiently transferred to a personal computer (PC) and 
visualized on a map application.
### Features
The GPS system performs the following tasks:  
1.Calculate the Total Displacement From Start Point to the Desired Destination.  
2.Upon the Start the RED_LED turns ON  
 .Then When SW2 Pressed BLUE_LED turns ON and the Program Starts to Read Coordinates From GPS and Send Them to Our Functions and Calculate the total Distance Covered 
 .When the Desired Destination reached GREEN_LED Turns on
 .At the End We Print the Total Displacement and the Total Distance on LCD  
The trajectory of the distance should satisfy the following criteria:  
 1. The total distance between the start and the end point should be > 100 meters.
 2.  The path from the start point to the end point should form a non-straight line that is similar to the provided baseline path below. 
 
