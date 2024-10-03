#include <Arduino.h>
#include <TFT_eSPI.h>
#include "FlickerFreePrint.h"
#include "Analog UV Sensor/src/UVSensor.hpp"

String uv;
String voltage;

uint16_t colour;

TFT_eSPI tft = TFT_eSPI();
FlickerFreePrint<TFT_eSPI> Text1(&tft, 0xFFFF, 0x0000);
FlickerFreePrint<TFT_eSPI> Text2(&tft, 0xFFFF, 0x0000);
UVSensor sensor;

void setup()
{
    tft.begin();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK);

    tft.setTextColor(TFT_WHITE);

    tft.setFreeFont(&FreeSansBold12pt7b);
    tft.drawString("UV Index", 0, 5);
    tft.drawString("Voltage", 0, 90);
    tft.setTextDatum(BR_DATUM);
    tft.drawString("/11", 125, 72);
    tft.drawString("mV", 125, 157);

    tft.setFreeFont(&FreeSansBold24pt7b);

    sensor.init(28, 10, 3300, 18);
}

void loop()
{
    sensor.update();

    if      (sensor.getIndex() == 0)  {colour = TFT_LIGHTGREY;}
    else if (sensor.getIndex() <= 2)  {colour = TFT_GREEN;}
    else if (sensor.getIndex() <= 5)  {colour = TFT_YELLOW;}
    else if (sensor.getIndex() <= 7)  {colour = TFT_ORANGE;}
    else if (sensor.getIndex() <= 10) {colour = TFT_RED;}
    else                              {colour = TFT_PURPLE;}

    uv = String(sensor.getIndex());
    voltage = String(sensor.getVoltage());

    tft.setCursor(0, 65);
    Text1.setTextColor(colour, TFT_BLACK);
    Text1.print(uv.c_str());

    tft.setCursor(0, 150);
    Text2.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
    Text2.print(voltage.c_str());
}
