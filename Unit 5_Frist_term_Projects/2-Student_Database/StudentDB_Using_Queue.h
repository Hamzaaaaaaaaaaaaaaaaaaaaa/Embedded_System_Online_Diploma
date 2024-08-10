/*
 * StudentDB_Using_Queue.h
 *
 *
 *      Author: Hamza Ahmed
 */

#ifndef STUDENTDB_USING_QUEUE_H_
#define STUDENTDB_USING_QUEUE_H_

#include "stdio.h"
#include <string.h>


#define Name_Length 50
#define Courses_Number  5

typedef struct
{
	char FName[Name_Length];
	char LName[Name_Length];
	int Roll_Number;
	int GPA        ;
	int Courses[Courses_Number];
}FIFO_Info_S;

typedef struct
{
	int Count ;
	int Length;
	FIFO_Info_S *head;
	FIFO_Info_S*base ;
	FIFO_Info_S*tail ;
}FIFO_Buf_S;


typedef enum
{
	FIFO_NULL,
	FIFO_NO_ERROR,
	FIFO_EMPTY,
	FIFO_NOT_EMPTY,
	FIFO_FULL,
	FIFO_NOT_FULL,

}FIFO_Status;

FIFO_Status FIFO_Init(FIFO_Buf_S *Students_queue,FIFO_Info_S *St_info ,int length);
FIFO_Status FIFO_Enqueue          (FIFO_Buf_S *Students_queue,FIFO_Info_S St_info);
FIFO_Status FIFO_IsFull           (FIFO_Buf_S *Students_queue,FIFO_Info_S St_info);
FIFO_Status FIFO_IsEmpty          (FIFO_Buf_S *Students_queue,FIFO_Info_S *St_info);
void Add_Student_From_File        (FIFO_Buf_S *Students_queue);
void Add_Student_Manually         (FIFO_Buf_S *Students_queue);
void Find_Student_by_RollNumber   (FIFO_Buf_S *Students_queue);
void Find_Student_by_FristName    (FIFO_Buf_S *Students_queue);
void Find_Studnet_by_Course       (FIFO_Buf_S *Studnets_queue);
void Print_Students_Count         (FIFO_Buf_S *Students_queue);
void Delete_Student               (FIFO_Buf_S *Students_queue);
void Update_Student               (FIFO_Buf_S *Students_queue);
void Show_Students                (FIFO_Buf_S *Students_queue);
















#endif /* STUDENTDB_USING_QUEUE_H_ */
