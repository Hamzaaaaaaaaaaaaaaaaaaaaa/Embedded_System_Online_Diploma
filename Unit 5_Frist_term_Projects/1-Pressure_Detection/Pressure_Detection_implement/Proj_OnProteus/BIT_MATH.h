/*
 * BIT_MATH.h
 *
 *  Created on: Jul 13, 2024
 *      Author: Hamza Ahmed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define GET_BIT(reg,bit)    (reg&(1<<bit))>>bit




#endif /* BIT_MATH_H_ */
