#include <stdio.h>

int main()
{
   int num,pos,result;
   printf("Input Number = ");
   scanf("%d",&num);
    printf("BIT Position = ");
    scanf("%d",&pos);
    result= num&(~(1<<pos));
     printf("Result = %d",result);
    return 0;
}