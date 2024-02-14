#include "stdio.h"

int main ()
{
	int r,c,i,j;
	printf("Enter rows and column of matrix :");
	scanf("%d\n",&r);
	scanf("%d",&c);
	int arr[r][c];
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("Enter the element of matrix(%d,%d) :\n",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Entered matrix:\n");
	for(i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			printf("%d \t",arr[i][j]);
			
		}
		printf("\r\n");
	}
	printf("Transposed matrix:\n");
	for(i=0;i<c;i++)
	{
		for (j=0;j<r;j++)
		{
			printf("%d \t",arr[j][i]);
			
		}
		printf("\r\n");
	}
	
	
	
	
	
	
	
}