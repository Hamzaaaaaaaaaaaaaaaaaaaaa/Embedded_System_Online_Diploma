#include "stdio.h"

int main ()
{	
	int H,A,i;
	printf("Enter no of elements : ");
	scanf("%d",&H);
	int arr[H];
	for(i=0;i<H;i++)
	{
		arr[i]=(i+1)*11;
		printf("%d ",arr[i]);
	}
	printf("\nEnter the elements to be searched : ");
	scanf("%d",&A);
	for(i=0;i<H;i++)
	{
		int S =arr[i]/A;
		if(S == 1){
			printf("Number found at the location = %d",i+1);
			break;
		}
		
	}
	
	
}