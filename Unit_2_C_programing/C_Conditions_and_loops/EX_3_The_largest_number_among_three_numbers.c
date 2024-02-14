
#include "stdio.h"


int main ()
{
	int x ,y ,z  ;
	
	printf ("Enter the numbers :");
	scanf ("%d%d%d",&x,&y,&z);
	
	if (x > y && x > z){
		printf ("the largest number is x : %d",x);
	
		
		
	}else if (y > x && y > z){
		printf ("the largest number is y : %d",y);	
		
		
	}else {
		printf ("the largest number is z : %d ",z);	
	}
	
}