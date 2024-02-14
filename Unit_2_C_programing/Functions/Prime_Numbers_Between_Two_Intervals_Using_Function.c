#include "stdio.h"

int prime (int num);

int main()
{
	int num1,num2,Flag;
	printf("Enter two numbers (intervals):");
	scanf("%d %d",&num1,&num2);
	printf("prime numbers between %d and %d:",num1,num2);
	for(int i = num1 +1;i<num2;++i)
	{
		Flag=prime(i);
				if(Flag==0)
					printf("%d ",i);
	}
	return 0;
}

int prime (int num)
{
	int flag,j ;
	flag =0;
	for(j=2;j<=num/2;++j)
	{
		if(num%j == 0)
		{
			flag=1;
			break;
		}
	}
	return flag;
}