#include "stdio.h"

int main()
{
	char arr1[100],arr2[100];
	int result;
	printf("Enter a string : ");
	fgets(arr1);
	printf("Enter your name : ");
	fgets(arr2);
	result = stricmp(arr1,arr2);
	if(result == 0)
		printf("Idenrical");
	else
		printf("Different");
	
	
	
}