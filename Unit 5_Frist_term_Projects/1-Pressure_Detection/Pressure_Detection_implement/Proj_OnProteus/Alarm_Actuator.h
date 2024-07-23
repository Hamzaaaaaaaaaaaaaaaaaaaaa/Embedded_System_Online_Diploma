/*
 * Alarm_Actuator.h
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "State.h"


extern void (*pAlarm_Actuator_state)();

//Define States
enum{
	Alarm_Actuator_IDLE,
	ALarm_Actuator_BUSY
}Alarm_Actuator_State_ID;

//Declare state functions of Alarm_Actuators
STATE_define(Alarm_Actuator_idle);
STATE_define(Alarm_Actuator_busy);


void Alarm_Actuator_Init ();
void Alarm_State_Set(int s);

#endif /* ALARM_ACTUATOR_H_ */
