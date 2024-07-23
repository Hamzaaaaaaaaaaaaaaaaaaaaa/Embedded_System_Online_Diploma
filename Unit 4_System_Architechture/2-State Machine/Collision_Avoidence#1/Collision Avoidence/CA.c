/*
 * CA.c
 *
 *  Created on: May 21, 2024
 *      Author: HAMZA AHMED
 */

#include "CA.h"

//Variables
static int CA_Speed = 0;
static int CA_Distance = 0;
static int CA_Threshold = 50;

void (*CA_state) ();

STATE_define(CA_waiting)
{
	//state name
	CA_state_id = CA_waiting;

	//state action(DC motor)
	CA_Speed = 0;

	//event check
	CA_Distance= US_GetDistanceRandom(45,55,1);

	if(CA_Distance<= CA_Threshold)
	{
		// assign func address to address of pointer to func
		CA_state = STATE(CA_waiting);

	}else
	{
		CA_state = STATE(CA_driving);
	}
	printf("CA_waiting State : Distance - %d  Speed = %d\n",CA_Distance,CA_Speed);
	return 0 ;
}
STATE_define(CA_driving)
{

	//state name
	CA_state_id = CA_waiting;

	//state action(DC motor)
	CA_Speed = 30;

	//event check
	CA_Distance= US_GetDistanceRandom(45,55,1);

	if(CA_Distance<= CA_Threshold)
	{
		// assign func address to address of pointer to func
		CA_state = STATE(CA_waiting);

	}else
	{
		CA_state = STATE(CA_driving);
	}
	printf("CA_waiting State : Distance - %d  Speed = %d\n",CA_Distance,CA_Speed);
	return 0;
}
int US_GetDistanceRandom(int l,int r ,int count)
{
	int i;
	for (i=0;i<count;++i)
	{
		int rand_num = (rand()%(r-l+1))+l;
		return rand_num;
	}
}
