#include "stdio.h"
#include "string.h"

int main ()
{
char str[100]={0};
int i,j=0;
printf ("Enter a string : ");
scanf("%s",str);

for(i=0;i<100;i++)
{
	if(str [i]!= '\0'){
		j++ ;
	}
}
printf ("Length of string : %d",j);



	return 0;
}