/*
 * State.h
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

//Automativ state function generated
#define STATE_define(_StateFunc_)  void ST_##_StateFunc_()

//func name for using in implementation for calling
#define STATE(_StateFunc_)  ST_##_StateFunc_



    // States Connections

// Pressure Sensor Driver --> Main Algorithm
void Set_Pressure_Val(int p);

//Main Algrithm --> Alarm Monitor
void High_Pressure_Detected(void);

//Alarm Monitor ==> Alarm Actuator
void Start_Alarm(void);

//Alarm Monitor --> Alarm Actuator
void Stop_Alarm(void);






#endif /* STATE_H_ */
