#ifndef APP_H
#define APP_H

#define earthquake 1
#define fire 2
#define gasLeakage 3

void initializationTask();

void alarmLed();

void enableDcMotor();

void enableFireSystem();

void buzzer();

void receiveProblem();

#endif