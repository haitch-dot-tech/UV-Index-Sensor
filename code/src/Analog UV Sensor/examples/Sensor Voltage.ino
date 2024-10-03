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
    Serial.print("\nSensor Voltage (mV): ");
    Serial.print(uv.getVoltage());
    // Serial.print("\nSensor Voltage (V): ");
    // Serial.print(uv.getVoltage() / 1000);
    delay(100);
}