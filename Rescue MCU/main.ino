#include <Arduino_FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include "config.h"
#include "app.h"

extern TaskHandle_t initializationTaskHandle, alarmLedTaskHandle, dcMotorTaskHandle, fireSystemTaskHandle, buzzerTaskHandle, receiveProblemTaskHandle;

void setup()
{
  xTaskCreate(initializationTask, "initialization", 64, NULL, 4, &initializationTaskHandle);
  xTaskCreate(receiveProblem, "receiveProblem", 128, NULL, 2, &receiveProblemTaskHandle);
  xTaskCreate(alarmLed, "alarmLed", 64, NULL, 3, &alarmLedTaskHandle);
  xTaskCreate(enableDcMotor, "enableDcMotor", 64, NULL, 3, &dcMotorTaskHandle);
  xTaskCreate(enableFireSystem, "enableFireSystem", 64, NULL, 3, &fireSystemTaskHandle);
  xTaskCreate(buzzer, "buzzer", 64, NULL, 3, &buzzerTaskHandle);
}

void loop()
{
}