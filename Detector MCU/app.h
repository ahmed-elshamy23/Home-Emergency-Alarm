#ifndef APP_H
#define APP_H

#define earthquake 1
#define fire 2
#define gasLeakage 3

#define parseTemperatureFromAnalogVoltage(analogVoltage) analogVoltage * 5.0f / 1024.0f * 100.0f;

void initializationTask();

void getTemperature();

void getGasReadings();

void getVibrationReading();

void validateReadings();

#endif