
#include "stdio.h"


int main ()
{
	char x ;
	
	printf ("Enter the characater :");
	scanf ("%c",&x);
	
	if ((x >= 'a' && x <= 'z')||(x >= 'A' && x <= 'Z')){
		printf ("%c is alphapet ",x);
	
	}else {
		printf ("the Character is not alphapet ");	
	}
	
}