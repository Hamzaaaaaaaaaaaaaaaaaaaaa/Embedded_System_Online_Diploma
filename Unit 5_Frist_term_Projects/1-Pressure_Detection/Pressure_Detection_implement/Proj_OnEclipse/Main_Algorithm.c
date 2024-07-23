/*
 * Main_Algorithm.c
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#include "Main_Algorithm.h"
#include "Alarm_Actuator.h"
#include "Platform_Types.h"


//Varibles
static int P_val = 0 ;
static boolean Alarm_State = 0;
static int P_threshold = 20 ;


//STATE pointer to func
void (*pMA_state)();

//Definition of states / func

STATE_define(MA_Waiting)
{
	MA_State_ID = MA_Waiting ;
	printf("MA_Waiting state : pressure = %d\n",P_val);

	//State Action
	Alarm_State = 0;
	Alarm_State_Set(Alarm_State);

}


STATE_define(MA_Detection)
{
	//State Name
	MA_State_ID = MA_Detection ;
	printf("MA_Detection state : pressure = %d\n",P_val);


	//State Action
	Alarm_State = 1 ;
	Alarm_State_Set(Alarm_State);
}
void Set_Pressure_Val(int p)
{
	P_val = p ;
	// you must determine the destination state here
	(P_val <= P_threshold) ? (pMA_state = STATE(MA_Waiting)) : (pMA_state = STATE(MA_Detection));

	printf("PS -------------- Pressure = %d ---------->MA\n",P_val);
}



