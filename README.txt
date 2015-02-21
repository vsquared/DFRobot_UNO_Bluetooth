This file contains additional instructions to accompany ‘DFRobot_UNO_Bluetooth’, a video demonstrating control of a 4 wheel drive mobile platform using Bluetooth and a Nexus 4 smartphone.  The requisite Arduino sketch is in a separate file.

Materials List For Project:

1) DFRobot 4wd Mobile Platform (Pirate)
2) “Make an Arduino-Controlled Robot” by Michael Margolis, 2013, O’Reilly Media
3) UNO Prototyping Platform (Arduino)
4) Motor Shield v2.3 (Adafruit)
5) E-Z Link Bluetooth Shield (Adafruit)
6) Nexus 4 Smartphone (Google)
7) ‘SPP Pro’ application by Jerry Li (Google Play Store)
8) Battery: 9v or 6 AA Battery Holder
9) 22 gauge solid wire (Black,Red)
10) Soldering iron, Rosin-core solder
11) Small screwdrivers (Phillips, regular), wire stripper, needle-nose pliers
12) Duct tape, velcro hook and loop with adhesive backing (optional)
13) Simple Arduino sketch accompanying this file.

Please Note:

1) The book recommends a ‘Leonardo’ board, but since it is not compatible with the EZ-Link Shield, an UNO board was used instead.  Power requirements are reportedly greater with UNO and robot performance is suboptimal, which was confirmed by our experience.  Therefore, a separate 9v battery (or 6 AA battery holder) was used in lieu of the 5 AA battery holder supplied in the kit.  The coaxial power jack on the rear of the chassis was wired to the adjacent switch so that it could be used for the power supply.  If a VIN jumper is used on the Motor Shield, a single battery will energize the board (with shields) as well as the four motors.

2) A strip of duct tape was used on the main platform to insulate the Arduino board pins.  Alternatively the board may be secured by short mounting pins provided in the kit or adhered with hook and loop velcro strips.

3) Uploading the Arduino sketch to UNO via USB cable necessitates setting a switch on the EZ-Link board to ‘Soft Serial’.  This switch should then be set to ‘Direct’ after uploading.

4) The four motor speeds may not be identical and some wheels may rotate faster than others.  If this occurs, individual motor speed may be adjusted by changing the ‘pwm’ variable in the Arduino sketch.

5) Five commands were used to control robot movement:

Forward = 'f' = 102 (ASCII)
Back = 'b' = 98
Left = 'l' = 108
Right = 'r' = 114
Stop = 's' = 115

The Arduino sketch is set to trap each of these letters and change wheel direction accordingly.

6) It is also necessary to program five buttons in the app ‘SPP Pro’ so that Nexus 4 sends these commands when the buttons are touched and held.  Additionally, each button was programmed to send a ‘stop’ command when released.  For safety reasons, a fifth button was programmed to send a stop command in each of the three positions.

To program the buttons, first use ‘SPP Pro’ to connect to the EZ-Link shield, and then select ‘Keyboard mode’. Under the menu (three vertical dots in right upper corner) select ‘Buttons set’.  Name and program five buttons according to this table:

Btn Name  Forward   Back   Left   Right   Stop
Btn Down     f	     b      l      r       s
Btn Hold     f       b      l      r       s
Btn Up       s       s      s      s       s 
