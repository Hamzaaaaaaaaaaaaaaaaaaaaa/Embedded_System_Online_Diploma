/*
 * Pressure_Sensor.c
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#include "Pressure_Sensor.h"
#include "GPIO.h"
/*for testing*/
//int PS_Get_Pressure_Random(int l , int r , int count);

//Varibles
static int P_val = 0 ;

// STATE Pointer to Func
void (*pPS_state)();

//Definition of states/func

STATE_define(PS_busy)
{
 //State Name
	PS_States_ID = PS_BUSY;

	//State Action
	P_val = GPIO_Get_Pressure_Val();
/* For Testing */
//	printf("PS_busy state : Pressure = %d\n",P_val);

	//check event and update state
	Set_Pressure_Val(P_val);
	pPS_state = STATE(PS_busy);


}

void PS_Init()
{
	//Init PS Driver
	/* For Testing */
//	printf("PS_Init\n");
}



//////////////////////////////////////////////

/*
int PS_Get_Pressure_Random(int l , int r , int count )

{
	//Generate one(count) random number in the range [l:r}
	int i ,rand_num;
	for (i = 0 ; i< count ;i++)
	{
		rand_num = (rand() % (r-l+1)) + l ;
	}
	return rand_num ;
}
*/






