
#include <stdio.h>

int main()
{
	int x , y  ;
	int temp;
    printf ("Enter value of x : ");
	scanf ("%d",&x);
	printf ("Enter value of y : " );
    scanf ("%d",&y);  
	temp = x;
	x = y   ;
	y= temp;
	printf ("After swapping , value of x : %d\n ",x);
	printf ("After swapping , value of y : %d\n ",y);
	
    return 0;
}
