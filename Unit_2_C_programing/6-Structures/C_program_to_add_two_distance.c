/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct SAdd {
    int feet;
    float inch ;
    
}S1,S2,Sum;
int main()
{
   printf("Enter information of 1st distance: \n");
   printf("Enter feet : ");
   scanf("%d",&S1.feet);
   printf("Enter inch : ");
   scanf("%f",&S1.inch);
   printf("Enter information of 2ed distance: \n");
   printf("Enter feet : ");
   scanf("%d",&S2.feet);
   printf("Enter inch : ");
   scanf("%f",&S2.inch);
   Sum.feet = S1.feet + S2.feet;
   Sum.inch = S1.inch + S2.inch;
   if (Sum.inch > 12){
       Sum.inch = Sum.inch - 12 ;
       ++Sum.feet;
   }
   printf("Sum of distance: %d '-%.1f' ",Sum.feet,Sum.inch);

   
    return 0;
}
