#include <UVSensor.hpp>

UVSensor uv;

void setup()
{
    Serial.begin(9600);
    uv.init(29, 10, 3300, -18); // Pin 29 (analog capable), ADC resolution is 10 bits, 3.3V supply (converted to millivolts), -18 millivolts offset (ADC compensation)
}

void loop()
{
    sensor.update();
    Serial.print("\nUV Index: ");
    Serial.print(uv.getIndex());
    delay(100);
}