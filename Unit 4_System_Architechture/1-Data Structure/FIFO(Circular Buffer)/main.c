
/*
 * main.c
 *
 *  Created on: May 18, 2024
 *      Author: SOUQ COMPUTER
 */


#include "stdio.h"
#include "fifo.h"


int main (){
	FIFO_Buf_t FIFO_UART;
	ELEMENT_TYPE i,temp;

	if(FIFO_EInit(&FIFO_UART,Buff,LENGTH)==FIFO_NO_ERROR)
		printf("FIFO INIT.........DONE\n");

	for(i=0; i<7;++i)
	{
		printf("FIFO ENQUEUE (%x)\n",i);
		if(FIFO_EEnQueue(&FIFO_UART,i)== FIFO_NO_ERROR)
			printf("\t FIFO ENQUEUE ...... DONE\n");
		else
			printf("\t FIFO ENQUEUE .......FAILED\n");
	}
	FIFO_vPrint(&FIFO_UART);

	if(FIFO_EDeQueue(&FIFO_UART, &temp) == FIFO_NO_ERROR){
		printf("FIFO Dequeue(%x)------Done\n",temp);
	}
	if(FIFO_EDeQueue(&FIFO_UART, &temp) == FIFO_NO_ERROR){
		printf("FIFO Dequeue(%x)------Done\n",temp);
	}
	/* Print the Elements after remove two elements */
	FIFO_vPrint(&FIFO_UART);
	return 0;
}




