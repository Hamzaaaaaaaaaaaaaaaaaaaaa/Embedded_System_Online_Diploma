/*
 * Alarm_Actuator.c
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahemd
 */
#include "Alarm_Actuator.h"




//varibles
static int Alarm_State = 0 ;

// State Pointer to func
void (*pAlarm_Actuator_state)();

//Definition of states / func
STATE_define(Alarm_Actuator_idle)
{
	//State name
	Alarm_Actuator_State_ID = Alarm_Actuator_IDLE;


	printf("Alarm_Actuator_idle state : State = %d \n ",Alarm_State);

}
STATE_define(Alarm_Actuator_busy)
{
	//State Name
	Alarm_Actuator_State_ID = ALarm_Actuator_BUSY;

	pAlarm_Actuator_state = STATE(Alarm_Actuator_idle);
	printf("Alarm_Actuator_busy state : State = %d\n",Alarm_State);



}



void Alarm_Actuator_Init ()
{
	//INit AAlarm_Actuator
	printf("Alarm_Actuator_Init \n");
}

void Alarm_State_Set(int s)
{
	Alarm_State = s ;
	pAlarm_Actuator_state = STATE(Alarm_Actuator_busy);


	printf("MA---------- State =%d-------->Alarm_Actuator\n",Alarm_State);
}









