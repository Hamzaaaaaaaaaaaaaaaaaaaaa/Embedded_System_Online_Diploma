
#include "stdio.h"


int main ()
{
	int x , y ;
	
	printf ("Enter an intger you want to check: ");
	scanf ("%d",&x);
	( x % 2 == 0)?printf ("%d is even ", x) : printf ("%d is odd ", x) ;
	
	
	
}