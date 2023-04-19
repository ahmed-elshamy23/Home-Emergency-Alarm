#include <Arduino_FreeRTOS.h>
#include <FreeRTOSConfig.h>
#include "config.h"
#include "app.h"

extern TaskHandle_t initializationTaskHandle, temperatureTaskHandle, GasTaskHandle, vibrationTaskHandle, validationTaskHandle;

void setup()
{
  xTaskCreate(initializationTask, "initialization", 128, NULL, 4, &initializationTaskHandle);
  xTaskCreate(getGasReadings, "getGasReadings", 128, NULL, 2, &GasTaskHandle);
  xTaskCreate(validateReadings, "validateReadings", 128, NULL, 2, &validationTaskHandle);
  xTaskCreate(getTemperature, "getTemperature", 128, NULL, 2, &temperatureTaskHandle);
  xTaskCreate(getVibrationReading, "getVibrationReadings", 128, NULL, 2, &vibrationTaskHandle);
}

void loop()
{
}