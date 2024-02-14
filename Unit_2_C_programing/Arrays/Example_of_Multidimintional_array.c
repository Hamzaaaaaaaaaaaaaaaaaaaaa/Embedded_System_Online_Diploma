
#include "stdio.h"


int main ()
{
	float frist_mat[2][2];
	int i,j ;
	float seconed_mat[2][2];
	float sum[2][2];
	for(i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
		printf ("Enter frist_mat (%d,%d) element:",i,j);
		scanf ("%f", &frist_mat[i][j]);
		}
	}
	printf("\r\n");
	for(i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
		printf ("Enter seconed_mat (%d,%d) element:",i,j);
		scanf ("%f", &seconed_mat[i][j]);
		
		}
		
	}
	for(i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
		sum[i][j]=frist_mat[i][j]+seconed_mat[i][j];
		}
		

	}
	printf ("sum of matrix= \n");
	for(i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
		printf (" %.2f\t",sum[i][j]);
		}
		printf ("\r\n");	

	}
	
}