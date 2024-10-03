# Arduino UV Index Sensor Library
Enables simple usage of a cheap, readily available GUVA-S12SD UV Light sensor module.

This library allows for a quick UV Index reading based off the sensor's given voltage UV index values.

## Features
* Easy way to read and process sensor readings
* Voltage offset allows for calibration for extremely accurate readings

## Supported boards
Currently all boards are supported with this library. Tested on an RP2040-Zero from AliExpress.

## Hardware
You will need:
* An Arduino-compatible board or microcontroller
* A GUVA-S12SD UV Light sensor

Connection is as simple as giving power to the UV sensor (make sure it gets the same voltage as your IO voltage) and connecting it to an analog ready IO pin.

## Usage
1. Start your code with ```#include <UNSensor.hpp>```. Then create an object to represent the library with ```UVSensor objectname;```.
2. Initialise the library in your setup() by using ```objectname.init(pin, res, volts, offset);```
 * ```pin``` - Pin for the library to analogRead() from
 * ```res``` - Resolution of the ADC on your board (e.g. 10 bits)
 * ```volts``` - Max voltage of the ADC (IO voltage)
 * ```offset``` - Millivolts offset for your sensor (e.g. -18)
3. In your loop, use ```objectname.update();``` to update the library's memory. You must do this to have non-zero ouput values.
4. Use ```objectname.getIndex();``` and ```objectname.getVoltage();``` to get the processed UV index and sensor voltage (in millivolts) respectively.

## Finding your voltage offset
Although the sensor is often within about 25 millivolts around correct, you may choose to adjust it to give it more accuracy.

__To do this:__
1. Connect your sensor up to your board and run the Sensor Voltage example with an offset of zero to get a baseline reading.
2. While this is happening, probe the sensor output with a multimeter and compare the two voltage readings.
 * If the voltage reading from the serial monitor is _more_ than that of the multimeter, for example +14mV, then set your offset to -14 to counteract it.
 * Likewise, if the serial reading is _less_, set the offset to the difference.