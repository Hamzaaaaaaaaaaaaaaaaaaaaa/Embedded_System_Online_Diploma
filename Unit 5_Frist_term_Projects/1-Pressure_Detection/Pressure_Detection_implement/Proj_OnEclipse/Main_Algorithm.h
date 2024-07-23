/*
 * Main_Algorithm.h
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#ifndef MAIN_ALGORITHM_H_
#define MAIN_ALGORITHM_H_

#include "state.h"

extern void (*pMA_state)();

//Define States
enum {
	MA_Waiting,
	MA_Detection
}MA_State_ID;

//Declare State Function of MA
STATE_define(MA_Waiting);
STATE_define(MA_Detection);






#endif /* MAIN_ALGORITHM_H_ */
