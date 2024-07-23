/*
 * lifo.h
 *
 *  Created on: May 18, 2024
 *      Author: HAMZA AHMED
 */

#ifndef LIFO_H_
#define LIFO_H_

#include<stdio.h>

typedef struct
{
	unsigned int length ; //length of stack buffer
	unsigned int * base; //pointer to first address
	unsigned int * head;//increnent or decrement ponter while adding or removing item
	unsigned int count ;// to know the stack is fyll or not
}LIFO_Buf_t;

typedef enum{
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_NOT_FULL,
	LIFO_EMPTY,
	LIFO_NOT_EMPTY,
	LIFO_NULL

}LIFO_Buf_s;
/*
	Function Name        : LIFO_ECreate
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf,Pointer to Unsigned int Buffer,unsigned int Length
	Function Description : Create the the Stack to Add data.
 */
LIFO_Buf_s LIfO_EInit(LIFO_Buf_t* Lifo_Buf, unsigned int * Buffer,unsigned int Length);
/*
	Function Name        : LIFO_EIsFull
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf
	Function Description : Check if Buffer is full or not
 */
LIFO_Buf_s LIFO_EIsFull(LIFO_Buf_t* Lifo_Buf );
/*
	Function Name        : LIFO_EIsEmpty
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf
	Function Description : Check if Buffer is Empty or not
 */
LIFO_Buf_s LIFO_EIsEmpty(LIFO_Buf_t* Lifo_Buf );
/*
	Function Name        : LIFO_EPushItem
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf, unsigned int Item
	Function Description : Adding a new data on the Top of Stack_Buffer
 */
LIFO_Buf_s LIFO_EPushItem(LIFO_Buf_t* Lifo_Buf,unsigned int Item );
/*
	Function Name        : LIFO_EPopItem
	Function Returns     : Enum
	Function Arguments   : Pointer to struct Lifo_Buf,poiner to unsigned int Item
	Function Description : removing a new data on the Top of Stack_Buffer
 */
LIFO_Buf_s LIFO_EPopItem(LIFO_Buf_t* Lifo_Buf,unsigned int* Item );




#endif /* LIFO_H_ */
