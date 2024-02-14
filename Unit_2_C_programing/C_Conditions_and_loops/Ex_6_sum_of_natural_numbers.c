
#include "stdio.h"


int main ()
{
	int x,i,sum ;
	printf("Enter the Number: ");
	scanf ("%d",&x);
	for(i = 1 ; i <= x ; i++){
		sum += i ;
	} 
	printf(" sum = %d",sum);
}