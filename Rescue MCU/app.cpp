#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include "app.h"
#include "config.h"

static unsigned char receivedValue = 0xFF;

TaskHandle_t initializationTaskHandle, alarmLedTaskHandle, dcMotorTaskHandle, fireSystemTaskHandle, buzzerTaskHandle, receiveProblemTaskHandle;

void initializationTask()
{
  while (1)
  {
    Serial.begin(UART_BAUD_RATE);
    pinMode(buzzerPin, OUTPUT);
    pinMode(alarmLedPin, OUTPUT);
    pinMode(waterValvePin, OUTPUT);
    pinMode(dcMotorPositivePin, OUTPUT);
    pinMode(dcMotorNegativePin, OUTPUT);
    vTaskSuspend(buzzerTaskHandle);
    vTaskSuspend(dcMotorTaskHandle);
    vTaskSuspend(alarmLedTaskHandle);
    vTaskSuspend(fireSystemTaskHandle);
    vTaskDelete(initializationTaskHandle);
  }
}

void alarmLed()
{
  while (1)
  {
    digitalWrite(alarmLedPin, HIGH);
    vTaskDelay(portMAX_DELAY);
  }
}

void enableDcMotor()
{
  while (1)
  {
    digitalWrite(dcMotorPositivePin, HIGH);
    digitalWrite(dcMotorNegativePin, LOW);
    vTaskDelay(portMAX_DELAY);
  }
}

void enableFireSystem()
{
  while (1)
  {
    digitalWrite(waterValvePin, HIGH);
    vTaskDelay(portMAX_DELAY);
  }
}

void buzzer()
{
  while (1)
  {
    digitalWrite(buzzerPin, HIGH);
    vTaskDelay(portMAX_DELAY);
  }
}

void receiveProblem()
{
  TickType_t currentTime;
  currentTime = xTaskGetTickCount();
  while (1)
  {
    if (Serial.available())
    {
      vTaskResume(alarmLedTaskHandle);
      vTaskResume(buzzerTaskHandle);
      receivedValue = Serial.read();
      switch (receivedValue - '0')
      {
      case fire:
        vTaskResume(dcMotorTaskHandle);
        vTaskResume(fireSystemTaskHandle);
        break;
      case gasLeakage:
        vTaskResume(dcMotorTaskHandle);
        break;
      }
    }
    vTaskDelayUntil(currentTime, RECEIVE_PROBLEM_TASK_PERIOD);
  }
}