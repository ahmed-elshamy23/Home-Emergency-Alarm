#include <Arduino_FreeRTOS.h>
#include <MQ2.h>
#include "app.h"
#include "config.h"

static MQ2 mq2(gasSensorPin);
static float temperature, lpg, co, smoke;
static char vibration;

TaskHandle_t initializationTaskHandle, temperatureTaskHandle, GasTaskHandle, vibrationTaskHandle, validationTaskHandle;

void initializationTask()
{
  while (1)
  {
    mq2.begin();
    Serial.begin(UART_BAUD_RATE);
    pinMode(vibrationSensorPin, INPUT);
    pinMode(temperatureSensorPin, INPUT);
    vTaskDelete(initializationTaskHandle);
  }
}

void getTemperature()
{
  TickType_t currentTime;
  currentTime = xTaskGetTickCount();
  while (1)
  {
    temperature = parseTemperatureFromAnalogVoltage(analogRead(temperatureSensorPin));
    vTaskDelayUntil(currentTime, TEMPERATURE_TASK_PERIOD);
  }
}

void getGasReadings()
{
  TickType_t currentTime;
  currentTime = xTaskGetTickCount();
  while (1)
  {
    lpg = mq2.readLPG();
    co = mq2.readCO();
    smoke = mq2.readSmoke();
    vTaskDelayUntil(currentTime, GAS_TASK_PERIOD);
  }
}

void getVibrationReading()
{
  TickType_t currentTime;
  currentTime = xTaskGetTickCount();
  while (1)
  {
    vibration = digitalRead(vibrationSensorPin);
    vTaskDelayUntil(currentTime, VIBRATION_TASK_PERIOD);
  }
}

void validateReadings()
{
  TickType_t currentTime;
  currentTime = xTaskGetTickCount();
  while (1)
  {
    if (vibration)
      Serial.println(earthquake);
    if (temperature >= TEMPERATURE_THRESHOLD && smoke)
      Serial.println(fire);
    if (co && lpg)
      Serial.println(gasLeakage);
    vTaskDelayUntil(currentTime, VALIDATION_TASK_PERIOD);
  }
}