/*
 * StudentDB_Using_Queue.c
 *
 *
 *      Author: Hamza Ahmed
 */

#include "StudentDB_Using_Queue.h"

FILE *Students_Info ;
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
//only used here
static void           Print_Students_Info          (FIFO_Info_S*student    );
static FIFO_Info_S *Search_by_RollNumber(FIFO_Buf_S *students_queue,int roll);
/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
FIFO_Status FIFO_Init(FIFO_Buf_S *Students_queue,FIFO_Info_S *St_info ,int length)
{
	if(!Students_queue || !St_info || !length)
	{
		printf("=======Student Init Failed======\n");
		return FIFO_NULL;
	}
	Students_queue->base = St_info ;
	Students_queue->head = Students_queue->base;
	Students_queue->tail = Students_queue->base;
	Students_queue->Length = length;
	Students_queue->Count = 0 ;

		printf("=======Student Init Done======\n");
		return FIFO_NO_ERROR ;
}
FIFO_Status FIFO_Enqueue          (FIFO_Buf_S *Students_queue,FIFO_Info_S St_info)
{
	if(!Students_queue->base || !Students_queue->head || !Students_queue->tail)
	{
		printf("\n=======Student Enqueue Empty======\n");

		return FIFO_NULL ;
	}

	if(FIFO_IsFull(Students_queue,St_info) == FIFO_FULL)
	{
		printf("\n=======Student Enqueue Full======\n");
		return FIFO_FULL;
	}
	*(Students_queue->head) = St_info ;

	//For Circular Queue
	if((Students_queue->head+1) == (Students_queue->base + Students_queue->Length))
	{
		Students_queue -> head = Students_queue->base;
	}else
	{
		Students_queue->head ++;
	}
	Students_queue->Count++;
	return FIFO_NO_ERROR;
}
FIFO_Status FIFO_IsFull           (FIFO_Buf_S *Students_queue,FIFO_Info_S St_info)
{
	if(!Students_queue->base || !Students_queue->head || !Students_queue->tail)
	{
		printf("\n=======Student Enqueue Empty======\n");

		return FIFO_NULL ;
	}
	if(Students_queue->Count == Students_queue->Length)
	{
		printf("\n=======Student Enqueue FULL======\n");
		return FIFO_FULL ;
	}else
	{
		return FIFO_NOT_FULL;
	}

}
FIFO_Status FIFO_IsEmpty          (FIFO_Buf_S *Students_queue,FIFO_Info_S *St_info)
{
	if(!Students_queue->base || !Students_queue->head || !Students_queue->tail)
		{
			printf("\n=======Student Enqueue Empty======\n");

			return FIFO_NULL ;
		}
		if(Students_queue->Count == 0)
		{
			printf("\n=======Student Enqueue Empty======\n");
			return FIFO_EMPTY ;
		}else
		{
			return FIFO_NOT_EMPTY;
		}

}
void Add_Student_From_File(FIFO_Buf_S *Students_queue)
{
    FIFO_Info_S new_student;
    int i;
    FILE *Students_Info; // Declare the file pointer

    /* open a file ==> read */
    Students_Info = fopen("Students_Info.txt", "r");

    // Check if the file is not empty
    if (Students_Info == NULL)
    {
        printf("\n [ERROR] Students_Info.txt file is empty. \n");
        printf("\n [ERROR] Adding students from file >> failed \n");
        return;
    }

    // Reading from file until end of file
    while (fscanf(Students_Info, "%d", &new_student.Roll_Number) != EOF)
    {
        // Check if the roll number exists
        if (Search_by_RollNumber(Students_queue, new_student.Roll_Number) != NULL)
        {
            // Repeated Roll number
            printf("ERROR.....Roll Number %d is already taken ", new_student.Roll_Number);

            // Ignore the rest of the line as roll number is taken
            fscanf(Students_Info, "%*[^\n]");
            continue;
        }

        // Reading data >> first name, last name, and GPA
        fscanf(Students_Info, "%s", new_student.FName);
        fscanf(Students_Info, "%s", new_student.LName);
        fscanf(Students_Info, "%f", &new_student.GPA);

        // Reading course IDs
        for (i = 0; i < Courses_Number; i++)
        {
            fscanf(Students_Info, "%d", &new_student.Courses[i]);
        }

        // Enqueue a new student
        if ((FIFO_Enqueue(Students_queue, new_student)) == FIFO_NO_ERROR)
        {
            printf("\nINFO..........Roll Number %d is saved successfully\n", new_student.Roll_Number);
            printf("\n[INFO] Students details are saved successfully\n");
        }
        else
        {
            printf("\nERROR......Adding student is failed\n");
            fclose(Students_Info); // Close the file before returning
            return;
        }
    }

    // Close the file
    fclose(Students_Info);
}
void Add_Student_Manually         (FIFO_Buf_S *Students_queue)
{
	FIFO_Info_S New_student;
	int i;
	FIFO_Status Status ;
	//check if fifo is full
	Status = FIFO_IsFull(Students_queue,New_student);
	if(Status == FIFO_FULL)
	{
		printf("\n=======Student Enqueue Full======\n");
		return;

	}


	printf("Enter The Roll Number : ");
	scanf("%d",&New_student.Roll_Number);
	if(Search_by_RollNumber(Students_queue,New_student.Roll_Number)!= NULL)
			{
				//repeated Roll number
				printf("ERROR.....Roll Number %d is already taken ",New_student.Roll_Number);
				printf("Adding Student Manually failed");
				return ;
			}
	printf("\nEnter The First Name : ");
	scanf("%s",&New_student.FName);
	printf("\nEnter The Last Name : ");
	scanf("%s",&New_student.LName);
	printf("\nEnter GPA : ");
	scanf("%d",&New_student.GPA);
	printf("\nEnter Course IDs : ");
	for(i = 0 ; i < Courses_Number;i++)
	{
		scanf("%d",&New_student.Courses[i]);
	}
	if((FIFO_Enqueue(Students_queue,New_student)) == FIFO_NO_ERROR)
	{
		printf("\nINFO..........Roll Number %d is saved successfully\n",New_student.Roll_Number);
		printf("\n[INFO] Students details are saved successfully\n");
	}else
	{
		printf("\nERROR......Adding student is failed\n");
		return;
	}
}

void Find_Student_by_RollNumber   (FIFO_Buf_S *Students_queue)
{
	FIFO_Info_S *check ;
	int roll ;
	FIFO_Status Status ;


	//check if fifo is empty
	Status = FIFO_IsEmpty(Students_queue,check);
	if(Status == FIFO_NULL || Status == FIFO_EMPTY)
	{
		printf("\n=======Find_Student_by_RollNumber Failed======\n");
		return;

	}
	printf("Enter The Roll Number : ");
	scanf("%d",&roll);

	check = Search_by_RollNumber(Students_queue,roll);

	if(check == NULL)
	{
		printf("ERROR..... The Roll Number %d is not exist",roll);

	}
	else
	{
		Print_Students_Info(check);
	}
}
void Find_Student_by_FristName    (FIFO_Buf_S *Students_queue)
{
	FIFO_Info_S *check = Students_queue->tail ;
	char FName_input[Name_Length],i;
	FIFO_Status Status ;
	//check if fifo is empty
		Status = FIFO_IsEmpty(Students_queue,check);
		if(Status == FIFO_NULL || Status == FIFO_EMPTY)
		{
			printf("\n=======Find_Student_by_FristName Failed======\n");
			return;

		}
		printf("\n Enter The First Name : ");
		scanf("%s",FName_input);

		for(i = 0 ; i<Students_queue->Count;i++)
		{
			//compare between each input and all names
			if(!strcmp(FName_input,check->FName[i]))
			{
				Print_Students_Info(check);
			}else
			{
				printf("\nERROR.....%s is not found \n",FName_input);
			}
			//check if we reach the last element in queue
			if ((check +1) == (Students_queue->base +Students_queue->Length))
			{
				//set to the start
				check = Students_queue->base ;
			}
			else
			{
				check++;
			}

		}


}
void Find_Studnet_by_Course       (FIFO_Buf_S *Studnets_queue)
{
	FIFO_Info_S *check= Studnets_queue->tail ;
	int CourseId_input , i , j,number_enroled_student = 0;
	FIFO_Status Status ;


	//check if fifo is empty
	Status = FIFO_IsEmpty(Studnets_queue,check);
	if(Status == FIFO_NULL || Status == FIFO_EMPTY)
	{
		printf("\n=======Find_Studnet_by_CourseFailed======\n");
		return;

	}
	printf("Enter Course Id : ");
	scanf("%d",&CourseId_input);

	for (i = 0 ; i< Studnets_queue->Count;i++)
	{
		for (j= 0 ; j < Courses_Number ; j++)
		{
			if(check->Courses[j] == CourseId_input)
			{
				Print_Students_Info(check);
				number_enroled_student ++;
				printf("\n");
				break;
			}
		}
		//check if we reach the last element in queue
		if ((check +1) == (Studnets_queue->base +Studnets_queue->Length))
		{
		//set to the start
		check = Studnets_queue->base ;
		}
		else
		{
		check++;
		}


	}
	//check if it is not in any student
	if(number_enroled_student == 0)
	{
		printf("\nERROR.....Course id %d is not found \n",CourseId_input);
	}else
	{
		printf("\n INFO...........Total number of students enrolled : %dn",number_enroled_student);
	}


}
void Print_Students_Count         (FIFO_Buf_S *Students_queue)
{
	int counter = Students_queue->Count;
	int capacity = Students_queue->Length;

	printf("INFO..........Total number of students is %d : \n",counter);
	printf("INFO ..........You Can add up to %d students \n",capacity);
	printf("INFO ..........You can add %d more students \n",capacity - counter);
}
void Delete_Student               (FIFO_Buf_S *Students_queue)
{
	int roll_number ,i ,flag =0;
	FIFO_Info_S *check;
	FIFO_Status Status ;


	//check if fifo is empty
	Status = FIFO_IsEmpty(Students_queue,check);
	if(Status == FIFO_NULL || Status == FIFO_EMPTY)
	{
		printf("\n=======Delete_Student Failed======\n");
		return;
	}
	printf("Enter The Roll Number : ");
	scanf("%d",&roll_number);

	check = Students_queue->base;
	for(i= 0 ;i< Students_queue->Count ; i++)
	{
		if (check->Roll_Number == roll_number)
		{
			//Deleting student
			*check = *(Students_queue->tail);

			//update counter
			Students_queue->Count--;

			//check if we reach the last element in the queue
			if((Students_queue->tail+1) == (Students_queue->base + Students_queue->Length) )
			{
				//set to the start
				Students_queue->tail = Students_queue->base ;
			}
			else
			{
				//go to the next tail
				Students_queue->tail++;
			}
			flag = 1 ;
			break;
		}
		else
		{
			flag=0;
		}
		check ++ ;
	}
	if(flag == 1 )
	{
		printf("\n INFO ...... The ROll is Removed Successfully\n");
	}
	else
	{
		printf("ERROR..... This Roll Number %d is not found ",roll_number);
	}
}
void Update_Student               (FIFO_Buf_S *Students_queue)
{
	FIFO_Info_S *update_student , *check ;
	int i , input_roll,input_option,new_roll,flag=0;
	FIFO_Status Status ;

	//check if fifo is empty
	Status = FIFO_IsEmpty(Students_queue,check);
	if(Status == FIFO_NULL || Status == FIFO_EMPTY)
	{
		printf("\n=======Update_Student Failed======\n");
		return;
	}
	//Enter Roll number you want to update
	printf("\nEnter Roll Number : ");
	scanf("%d",&input_roll);

	update_student = Search_by_RollNumber(Students_queue,input_roll);

	if(update_student== NULL)
	{
		printf("\n ERROR.......Roll Number %d is not found \n",input_roll);
		return;
	}else
	{
		//if we found the roll number lets print all data
		printf("\n=== Students data ====\n");
		Print_Students_Info(update_student);
	}
	printf("\n Which data do you want to change ?\n");
	printf("\n 1: The ROll Number \n");
	printf("\n 2: The Fisrt Name \n");
	printf("\n 3: The Last Name  \n");
	printf("\n 4: The GPA \n");
	printf("\n 5: The Courses IDs \n");
	printf("\n Enter your Option\n");

	scanf("%d",&input_option);
	switch(input_option)
	{
	case 1 :
		printf("Enter the new roll number: ");
		scanf("%d",&new_roll);

		check = Students_queue->tail ;

		for (i=0;i<Students_queue->Count ;i++)
		{
			//check if we find the roll we search about to break
			if (check ->Roll_Number == new_roll)
			{
				printf("ERROR This Roll Number %d is exist \n",new_roll);

				//if we find a roll number match set flag
				flag = 1 ;
				break ;
			}
			//check if we reach the last node in the queue
			if ((check +1 )==(Students_queue->base + Students_queue->Length))
			{
				check = Students_queue->base;
			}
			else
			{
				check ++ ;
			}
		}
		if (flag == 0)
		{
			update_student->Roll_Number = new_roll;
			printf("\n INFO ..... The ROll Number %d is updated Successfully\n",new_roll);
		}
		break;
	case 2 :
		printf("Enter the new frist name : ");
		scanf("%s",&update_student->FName);
		printf("\n INFO ..... The First Name  is updated Successfully\n",new_roll);
		break;
	case 3 :
		printf("Enter the last frist name : ");
		scanf("%s",&update_student->LName);
		printf("\n INFO ..... The Last Name  is updated Successfully\n",new_roll);
		break;
	case 4 :
		printf("Enter the new GPA : ");
		scanf("%f",&update_student->GPA);
		printf("\n INFO ..... The GPA  is updated Successfully\n",new_roll);
		break;
	case 5 :
		printf("Enter the course number from %d to %d : ");
		scanf("%d",&input_option);
		printf("Enter the new course id : ");
		scanf("%d",&update_student->Courses[input_option-1]);
		printf("\n INFO ..... The Course ID %d is updated Successfully\n",update_student->Courses[input_option-1]);

		break;
	default :
	break;

	}


}
void Show_Students                (FIFO_Buf_S *Students_queue)
{
	FIFO_Info_S *check ;int i;
	FIFO_Status Status ;

	//check if fifo is empty
	Status = FIFO_IsEmpty(Students_queue,check);
	if(Status == FIFO_NULL || Status == FIFO_EMPTY)
	{
		printf("\n=======Show_Students Failed======\n");
		return;
	}
	printf("\n All Students\n\n");
	check = Students_queue->tail;
	for(i = 0 ;i<Students_queue->Count;i++)
	{
		Print_Students_Info(check);
		printf("\n");

		//check if we reach the last node in the queue
					if ((check +1 )==(Students_queue->base + Students_queue->Length))
					{
						check = Students_queue->base;
					}
					else
					{
						check ++ ;
					}


	}
}



/*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/
static void           Print_Students_Info          (FIFO_Info_S*student    )
{
	int i;
	printf(" The student details are : \n");
	printf("\n The First Name : %s\n",student->FName);
	printf("\n The Last Name : %s\n",student->LName);
	printf("\n The Roll Number : %d\n",student->Roll_Number);
	printf("\n The GPA : %d\n",student->GPA);
	printf("\n The Courses IDs : \n");
	for(i = 0 ; i < Courses_Number ; i++)
	{
		printf("\n Course %d ID : %d\n",i+1,student->Courses[i]);
	}
}
static FIFO_Info_S *Search_by_RollNumber(FIFO_Buf_S *students_queue,int roll)
{
	int i ;
	FIFO_Info_S *check = students_queue->tail;
	for(i = 0 ; i < students_queue->Count ;i++)
	{
		if(check ->Roll_Number == roll)
		{
			break;
		}
		if((check +1) == (students_queue->base + students_queue->Length))
		{
			check = students_queue->base;

		}
		else
		{
			check++;
		}
	}
	if (i == students_queue ->Count)
	{
		check = NULL ;
	}
	return check ;
}












