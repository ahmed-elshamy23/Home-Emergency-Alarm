#ifndef CONFIG_H
#define CONFIG_H

#define buzzerPin A0
#define alarmLedPin A1
#define waterValvePin A2
#define dcMotorPositivePin A3
#define dcMotorNegativePin A4

#define UART_BAUD_RATE 9600

#define BUZZER_TASK_PERIOD 50
#define DC_MOTOR_TASK_PERIOD 50
#define ALARM_LED_TASK_PERIOD 50
#define FIRE_SYSTEM_TASK_PERIOD 50
#define RECEIVE_PROBLEM_TASK_PERIOD 70

#endif