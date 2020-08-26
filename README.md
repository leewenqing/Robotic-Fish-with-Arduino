
# Robotic-Fish-with-Arduino
 Example of the basic control for Robotic Fish（with Bluetooth）



### Introduction:
The robotic fish developed was mainly used for children's education and entertainment

### Construction:
 - The initial code for this project was developed by the author named [ric dirgahayu](https://www.instructables.com/id/RoboFist-made-From-pvc-water-pipe/). 
 - This version of the project has been partially modified to include bluetooth and mobile phone controls for children to learn and play.
 
### :warning: Code is buggy :warning:

 - The Fish is controlled through an Arduino UNO, which communicates with the phone or pad app "Roboticfish" through a [Bluetooth module](https://www.amazon.com/HiLetgo%C2%AE-Wireless-Bluetooth-Transceiver-Arduino/dp/B071YJG8DR/ref=sr_1_1_sspa?ie=UTF8&qid=1530698951&sr=8-1-spons&keywords=hc05&psc=1 "HC-05 Bluetooth Module"), mounted on it's head.

 - The project model is applicable to the design of basic three-servo robotic fish, as shown in the example in the figure below. (this example is developed at the [Theoretical Ecology and Evolution Laboratory](https://teelabiisc.wordpress.com/ "TEE-Lab, IISc"), [Indian Institute of Science] (https://www.iisc.ac.in "Indian Institute of Science, Bengaluru").)
<p align="center"><img style="border:1px solid black;"              src="https://raw.githubusercontent.com/SarthakJShetty/Fish/master/Design_Files/Mechanical_Design/Structure_Design/Fish_Assembly_Snapshot.png" alt="SolidWorks Model"></p>
               <figcaption align="center"><strong>Fig 1.</strong><em> SolidWorks assembly of mechanical structure.</em></figcaption>


### Install:
- Download or design any similar three-joint robotic fish model and implement it (e.g., 3D printing)
- Download the code Robotic-Fish-with-Arduino/BT_roboFishtest/BT_roboFishtest.ino to the Arduino board(for example UNO).
- Download the app Robotic-Fish-with-Arduino/Android control apk/Roboticfish.apk to the your phone or pad(noly for Android)
- Run the Roboticfish app on your phone or pad.
<p align="center"><img style="border:0.2px solid black;"              src="https://github.com/leewenqing/Robotic-Fish-with-Arduino/blob/master/pic/ea2db3cc7a15aa6c72d41bff0aaf522.jpg" alt="Android app"></p>
               <figcaption align="center"><strong>Fig 2.</strong><em> Android app for control.</em></figcaption>
               
- Click the Connect button to select the Bluetooth name of the robot fish. 
- Click the Connect button to select the Bluetooth name of the robot fish.   
- When the intermediate connection status is displayed as "connected", the robot fish can be controlled by the command below.

### Noting:
- Be sure to match the size of the servo motor you purchased before 3D printing.
- Remember to configure and set the name of the Bluetooth chip before using it.
- Remember to disconnect the Bluetooth connection before downloading the program to the board.

