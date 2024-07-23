#include "math.h"
#include "stdio.h"

int checkpower_of_3(unsigned m);

int main()
{
	unsigned int number;
	printf("Enter an nteger number:\r\n");
	scanf("%d",&number);
	
	checkpower_of_3(number) ? printf("%d ==> 0",number) : printf("%d ==> 1",number);
	return 0;
}


int checkpower_of_3(unsigned m)
{
	double i = log(m)/log(3);
	return i == trunc(i);
}