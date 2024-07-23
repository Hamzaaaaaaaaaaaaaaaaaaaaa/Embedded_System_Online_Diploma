/*
 * main.c
 *
 *  Created on: May 18, 2024
 *      Author: HAMZA AHMED
 */
#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

#define LENGTH_BUFFER1 5
#define LENGTH_BUFFER2 5


unsigned int Buffer1[LENGTH_BUFFER1];

int main(){

	unsigned int Temp = 0,i;
	LIFO_Buf_t UART_LIFO, I2C_LIFO;
	// Static Allocaation
	LIfO_EInit(&UART_LIFO,Buffer1,LENGTH_BUFFER1);
	// Dynamic Allocaation
	unsigned int *Buffer2 = (unsigned int*) malloc(LENGTH_BUFFER2*sizeof(unsigned int));
	LIfO_EInit(&I2C_LIFO,Buffer2,LENGTH_BUFFER2);

	for(i=0; i<LENGTH_BUFFER1; ++i){
		if( ( LIFO_EPushItem(&UART_LIFO, i) ) == LIFO_NO_ERROR){
			printf("UART_LIFO Push  : %d \n",i);
		}

	}
	printf("=====================\n");
	for(i=0; i<LENGTH_BUFFER1; ++i){
		if( ( LIFO_EPopItem(&UART_LIFO, &Temp) ) == LIFO_NO_ERROR){
			printf("UART_LIFO Pop  : %d \n",Temp);
		}

	}
	return 0;


}
