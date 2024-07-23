/*
 * main.c
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#include "Platform_Types.h"
#include "Pressure_Sensor.h"
#include "Alarm_Actuator.h"
#include "Main_Algorithm.h"


void setup()
{
	//init all drivers
	PS_Init();
	Alarm_Actuator_Init();

	//set states pointers for each one
	pMA_state = STATE(MA_Waiting);
	pPS_state = STATE(PS_busy);
	pAlarm_Actuator_state = STATE(Alarm_Actuator_idle);
}

int main ()
{
	volatile int Delay ;
	setup();
	while (1)
	{
		//call for each block
		pPS_state();
		pMA_state();
		pAlarm_Actuator_state();
		for(Delay = 0; Delay <= 10000 ; Delay++);
	}
	return 0 ;
}
