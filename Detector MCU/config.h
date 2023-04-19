#ifndef CONFIG_H
#define CONFIG_H

#define temperatureSensorPin A0
#define gasSensorPin A1
#define vibrationSensorPin 2

#define UART_BAUD_RATE 9600

#define TEMPERATURE_THRESHOLD 60

#define GAS_TASK_PERIOD 70
#define VIBRATION_TASK_PERIOD 50
#define VALIDATION_TASK_PERIOD 50
#define TEMPERATURE_TASK_PERIOD 50

#endif