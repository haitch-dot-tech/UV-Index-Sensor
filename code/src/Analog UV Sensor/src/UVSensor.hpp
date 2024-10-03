#include <Arduino.h>

class UVSensor 
{
    public:
        UVSensor();
        /**
         * @brief Sets up the UV Sensor.
         * @param pin Pin to read analog values from
         * @param res Your ADC Resolution (in bits)
         * @param volts ADC voltage (millivolts)
         * @param offset Offset in millivolts to improve ADC readings
         */
        void init(uint8_t pin, uint8_t res, uint volts, int offset);
        /**
         * @brief Updates the library's memory. Call in your loop.
         */
        uint update();
        /**
         * @brief Gets the UV Index rating from the sensor.
         * @return UV Index 0-11
         */
        uint8_t getIndex();
        /**
         * @brief Gets the voltage reading.
         * @return Voltage in millivolts
         */
        uint getVoltage();
    private:
        uint8_t sensorPin;
        uint ADCRes;
        uint ADCVoltage;
        int sensorOffset;

        uint latestADC;
        uint latestVoltage;
        uint8_t latestUV;
};