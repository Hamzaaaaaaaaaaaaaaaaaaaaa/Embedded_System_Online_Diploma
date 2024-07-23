/*
 * fifo.c
 *
 *  Created on: May 18, 2024
 *      Author: HAMZA AHMED
 */
#include <stdio.h>
#include "fifo.h"


FIFO_Buf_s FIFO_EInit(FIFO_Buf_t* FIFO_Buf,ELEMENT_TYPE * Buffer,uint32_t Length)
{
	if(Buffer == NULL)
		return FIFO_FULL;

	FIFO_Buf->base = Buffer;
	FIFO_Buf->head = FIFO_Buf->base;
	FIFO_Buf->tail = FIFO_Buf->base;
			FIFO_Buf->Length = Length;
			FIFO_Buf->Count = 0;

	return FIFO_NO_ERROR;
}
FIFO_Buf_s FIFO_EIsFull(FIFO_Buf_t* FIFO_Buf)
{
	if(FIFO_Buf->base == NULL || FIFO_Buf->head == NULL  || FIFO_Buf->tail == NULL )
		return FIFO_NULL;
	if(FIFO_Buf->Count == FIFO_Buf->Length)
		return FIFO_FULL;
	else
		return FIFO_NOT_FULL;
}
FIFO_Buf_s FIFO_EIsEmpty(FIFO_Buf_t* FIFO_Buf)
{
	if(FIFO_Buf->base == NULL || FIFO_Buf->head == NULL  || FIFO_Buf->tail == NULL )
		return FIFO_NULL;
	if(FIFO_Buf->Count ==0)
		return FIFO_EMPTY;
	else
		return FIFO_NOT_EMPTY;

}
FIFO_Buf_s FIFO_EEnQueue(FIFO_Buf_t* FIFO_Buf,ELEMENT_TYPE Item)
{
	if(FIFO_Buf->base == NULL || FIFO_Buf->head == NULL  || FIFO_Buf->tail == NULL )
		return FIFO_NULL;
	/*Check if FIFO is full or not */
	if(FIFO_EIsFull(FIFO_Buf) == FIFO_FULL)
		return FIFO_FULL;
	*(FIFO_Buf->head) = Item;
	FIFO_Buf->Count++;

	// For circular Queue
	if (FIFO_Buf->head == (ELEMENT_TYPE*)(FIFO_Buf->Length * sizeof(ELEMENT_TYPE)))
		FIFO_Buf->head = FIFO_Buf->base;
	else
		FIFO_Buf->head++;
	return FIFO_NO_ERROR;
}
FIFO_Buf_s FIFO_EDeQueue(FIFO_Buf_t* FIFO_Buf,ELEMENT_TYPE* Item)
{
	if(FIFO_Buf->base == NULL || FIFO_Buf->head == NULL  || FIFO_Buf->tail == NULL )
		return FIFO_NULL;
	/*Check if FIFO is full or not */
	if(FIFO_EIsEmpty(FIFO_Buf) == FIFO_FULL)
		return FIFO_EMPTY;

	*Item = *(FIFO_Buf->tail);
	FIFO_Buf->Count--;

	// For circular Queue
	if (FIFO_Buf->tail == (ELEMENT_TYPE*)(FIFO_Buf->Length * sizeof(ELEMENT_TYPE)))
		FIFO_Buf->head = FIFO_Buf->base;
	else
		FIFO_Buf->tail++;


	return FIFO_NO_ERROR;
}
void FIFO_vPrint(FIFO_Buf_t* FIFO_Buf)
{
	ELEMENT_TYPE * Temp;
	int i;
	if(FIFO_Buf->Count == 0)
		printf("FIFO is Empty\n");

	else
		Temp = FIFO_Buf->tail;

	printf("\n===========FIFO_Print=========\n");
	 for( i=0; i < FIFO_Buf->Count;++i )
	{
		printf("\t %X \n",*Temp);
		Temp++;
	}
		printf("\n====================\n");

}








