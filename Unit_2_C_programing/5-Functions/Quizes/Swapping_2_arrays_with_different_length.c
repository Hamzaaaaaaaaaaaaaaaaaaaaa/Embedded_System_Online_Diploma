#include "stdio.h"

int main ()
{
	int a[10],b[10],c[10],i;
	printf("Enter First array -> ");
	for (i=0;i<10;i++)
		scanf("%d",&a[i]);
		printf("\n Enter Second array -> ");
	for (i=0;i<5;i++)	
		scanf("%d",&b[i]);
	printf("Arrays before swapping\n First array -> ");
	for (i=0;i<10;i++)
		printf("%d\t",a[i]);
	printf("\n Second array -> ");
	for (i=0;i<5;i++)	
		printf("%d\t",b[i]);
	for (i=0;i<10;i++)
	{
		c[i]=a[i];
		a[i]=b[i];
		b[i]=c[i];
	}
	printf("Arrays after swapping\n First array -> ");
	for (i=0;i<5;i++)	
		printf("%d\t",a[i]);
	printf("\n Second array -> ");
	for (i=0;i<10;i++)
		printf("%d\t",b[i]);
}