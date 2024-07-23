#include "stdio.h"
int last_occurence(int arr[],int size);
int main ()
{
int arr [100],size ;
printf("Enter size of array : ");
scanf("%d",&size);
for (int i =0; i< size ;i++)
{
printf("Enter element %d : ",i+1);
scanf("%d",&arr[i]);	
}
int last = last_occurence(int arr[],int size);
printf("Last occurence is %d  ",last);

int last_occurence(int arr[],int size)
{
	int get_key;
	printf("Enter the number you want to get its last occurrence : ");
	scanf("%d",&get_key);
	for(int i =size ; i>0 ; i--)
	{
		if (arr[i]==get_key)
			return i+1;
	}
	return -1 ;
}
