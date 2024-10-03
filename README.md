# UV-Index-Sensor
This project is a small device that you can use to measure the UV index on the go.
It is very affordable at only ~$10 AUD, if you get all of the parts from AliExpress

## Materials
### Parts
* Keyes GUVA-S12SD UV Light Sensor Module
* (Waveshare) RP2040-Zero Dev Board - knockoffs definetly work
* 1.8" 128x160 ST7735 TFT Display module
* TP4056 LiPo battery charger module
* A small LiPo battery (300-800mAh)
* Voltage Booster module, capable of 3.7-5 volts
* Slideswitch
* Hookup wire
* 3D Printed parts
* 8 M3x5 bolts
* 4 M3 hex nuts
* Hot glue or thin double-sided tape

### Tools
* 3D Printer
* Soldering Iron
* Philips head screwdriver
* Hot glue gun (if not using double-sided tape)

## Building it
1. 3D print all of the case parts.
2. Put all of the components "where they fit"
3. Wire up according to wiring diagram
4. Upload the code and test!

## The code
All that the code (currently) does is sets up the UV sensor (using my [library](https://github.com/haitch-dot-tech/Analog-UV-Sensor)), and then prints the readings to the display.
I used PlatformIO to write this but if you have [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) and [Analog UV Sensor](https://github.com/haitch-dot-tech/Analog-UV-Sensor) installed the Arduino IDE should work just fine. Just copy the ```main.cpp``` file and rename it to ```main.ino```.

## Expanding the project/help
If you have any new improvements or ideas to add to the project, just create an "issue" mentioning these. I'd love to hear more ideas.
If you need a hand, also just create an issue and we can figure it out.

## Open Source
Of course, releasing this to GitHub means that it is an Open Source project. It includes everything you could need to build the project and I am excluding nothing.
Feel free to download and modify this project to your desire. If what you are doing, for example, is swapping the UV sensor for something else, and if you publish it, just make a small note about my "contribution".
