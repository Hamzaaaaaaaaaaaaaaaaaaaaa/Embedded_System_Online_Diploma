#include "stdio.h"
#include "string.h"

int main ()
{
  char str[100];
  int i,n;
  printf("Enter the srting : ");
  scanf("%s",str);
  
  n=strlen(str);
  for(i=0;i<n/2;i++)
  {
	  char temp = str[i];
	  str[i]= str[n-1-i];
	  str[n-1-i] = temp;
  }
  
  printf("Reverse string is : %s",str);
	return 0;
}