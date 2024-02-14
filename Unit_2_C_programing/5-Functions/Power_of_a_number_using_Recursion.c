#include <stdio.h>


int power(int base , int exp);
int main()
{
   int Base,Exp; 
   printf("Enter base number: ");
   scanf("%d",&Base);
   
   printf("Enter power number(positive): ");
   scanf("%d",&Exp);
   
   printf("%d^%d =%d",Base , Exp,power(Base,Exp));
   
    return 0;
}
int power(int base , int exp){
	if (exp == 1)
	{
		base = base ;
	}	
	else
	{
		base = (base*(power(base,exp-1)));
	}
	return base ;
}