/*
 * lifo.c
 *
 *  Created on: May 18, 2024
 *      Author: HAMZA AHMED
 */

#include "lifo.h"


#define     NULL    (void*)0


LIFO_Buf_s LIfO_EInit(LIFO_Buf_t* Lifo_Buf, unsigned int * Buffer,unsigned int Length)
{
	//Check if the Buffer is existed or not
	if (Buffer == NULL)
		return LIFO_NULL;
	Lifo_Buf->base = Buffer; //points to the first address of the Buffer
	Lifo_Buf->head = Buffer; //points to the first address of The Buffer
	Lifo_Buf->length = Length;
	Lifo_Buf->count = 0;
	return LIFO_NO_ERROR;
}
LIFO_Buf_s LIFO_EIsFull(LIFO_Buf_t* Lifo_Buf )
{
	if (Lifo_Buf->count == Lifo_Buf->length)
		return LIFO_FULL;
	else
		return LIFO_NOT_FULL;

}
LIFO_Buf_s LIFO_EIsEmpty(LIFO_Buf_t* Lifo_Buf )
{
	if (Lifo_Buf->count == 0)
		return LIFO_EMPTY;
	else
		return LIFO_NOT_EMPTY;

}
LIFO_Buf_s LIFO_EPushItem(LIFO_Buf_t* Lifo_Buf,unsigned int Item )
{
	// Check if the is existed or mot
	if (Lifo_Buf->base == NULL || Lifo_Buf->head == NULL)
		return LIFO_NULL;
	if (LIFO_EIsFull(Lifo_Buf) == LIFO_FULL)
		return LIFO_FULL;
	*(Lifo_Buf->head ) = Item;
	Lifo_Buf->head++;
	Lifo_Buf->count++;

	return LIFO_NO_ERROR;


}

LIFO_Buf_s LIFO_EPopItem(LIFO_Buf_t* Lifo_Buf,unsigned int* Item )
{
	// Check if the is existed or mot
	if (Lifo_Buf->base == NULL || Lifo_Buf->head == NULL)
		return LIFO_NULL;
	if (LIFO_EIsEmpty(Lifo_Buf) == LIFO_EMPTY)
		return LIFO_EMPTY;
	Lifo_Buf->head--;
	*Item= *(Lifo_Buf->head);
	Lifo_Buf->count--;

	return LIFO_NO_ERROR;

}
