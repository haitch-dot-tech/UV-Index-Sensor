#include "UVSensor.hpp"

UVSensor::UVSensor() {}

void UVSensor::init(uint8_t pin, uint8_t res, uint volts, int offset)
{
    sensorPin = pin;
    ADCRes = pow(2, res);
    ADCVoltage = volts;
    sensorOffset = offset;
}

uint UVSensor::update()
{
    latestADC = analogRead(sensorPin);
    return latestADC;
}

uint8_t UVSensor::getIndex()
{
    getVoltage();
    if (latestVoltage > 1170) {latestUV = 11;}
    else if (latestVoltage > 1079) {latestUV = 10;}
    else if (latestVoltage > 976) {latestUV = 9;}
    else if (latestVoltage > 881) {latestUV = 8;}
    else if (latestVoltage > 795) {latestUV = 7;}
    else if (latestVoltage > 696) {latestUV = 6;}
    else if (latestVoltage > 606) {latestUV = 5;}
    else if (latestVoltage > 503) {latestUV = 4;}
    else if (latestVoltage > 408) {latestUV = 3;}
    else if (latestVoltage > 318) {latestUV = 2;}
    else if (latestVoltage > 227) {latestUV = 1;}
    else {latestUV = 0;}
    return latestUV;
}

uint UVSensor::getVoltage()
{
    latestVoltage = (latestADC * ADCVoltage / ADCRes) + sensorOffset;
    return (latestVoltage);
}