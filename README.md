
# Robotic-Fish-with-Arduino
 Example of the basic control for Robotic Fish（with Bluetooth）



### Introduction:
The robotic fish developed was mainly used for children's education and entertainment

### Construction:
 - The initial code for this project was developed by the author named [ric dirgahayu](https://www.instructables.com/id/RoboFist-made-From-pvc-water-pipe/). 
 - This version of the project has been partially modified and added bluetooth and mobile phone control program to facilitate children to play.
 
### :warning: Code is buggy :warning:

 - The Fish is controlled through an Arduino UNO, which communicates with the phone or pad app "Roboticfish" through a [Bluetooth module](https://www.amazon.com/HiLetgo%C2%AE-Wireless-Bluetooth-Transceiver-Arduino/dp/B071YJG8DR/ref=sr_1_1_sspa?ie=UTF8&qid=1530698951&sr=8-1-spons&keywords=hc05&psc=1 "HC-05 Bluetooth Module"), mounted on it's head.

 - The project model is applicable to the design of basic three-section robotic fish, as shown in the example in the figure below(this model is developed at the [Theoretical Ecology and Evolution Laboratory](https://teelabiisc.wordpress.com/ "TEE-Lab, IISc"), [Indian Institute of Science](https://www.iisc.ac.in "Indian Institute of Science, Bengaluru").)
<p align="center"><img style="border:2px solid black;"              src="https://raw.githubusercontent.com/SarthakJShetty/Fish/master/Design_Files/Mechanical_Design/Structure_Design/Fish_Assembly_Snapshot.png" alt="SolidWorks Model"></p>
               <figcaption align="center"><strong>Fig 1.</strong><em> SolidWorks assembly of mechanical structure.</em></figcaption>


### Install:
- Firstly, the body structure of the robot fish is printed by 3D printing.
- Download the code Robotic-Fish-with-Arduino/BT_roboFishtest/BT_roboFishtest.ino to the Arduino board(for example UNO).
- Download the app Robotic-Fish-with-Arduino/Android control apk/Roboticfish.apk to the your phone or pad(noly for Android)
- Run the Roboticfish app on your phone or pad.

