#include "stdio.h"
#include "string.h"

int main ()
{
char string_1[100],C;	
int i,j=0;

	printf("Enter a string : ");
	scanf("%s",string_1);
	   printf("\r\n");
	printf("Enter a character to find frequency : ");
	scanf(" %c", &C);
	
	for(i=0;i  <strlen(string_1);i++)
	{
		if(string_1[i] == C){
			j++;
		}
	}
	printf("frequency of %c = %d ",C,j);
	return 0;
}