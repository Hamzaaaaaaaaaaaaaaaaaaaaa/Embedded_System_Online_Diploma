#include "stdio.h"

int factorial (int num);

int main()
{
	int F ;
	printf("Enter a positive number : ");
	scanf("%d",&F);
	printf("factorial of %d is  : %d ",F,factorial (F));
	
	return 0;
}

int factorial (int num)
{
	
	if(num<=1)
		return 1;
	else
		
	return (num *factorial(num-1)) ;

	
}