/*
 * Pressure_Sensor.h
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "State.h"

extern void (*pPS_state)();

//Define States
enum {
	PS_BUSY,
}PS_States_ID;

//Declare State Function of PS
STATE_define(PS_busy);

//INIT
void PS_Init();

#endif /* PRESSURE_SENSOR_H_ */
