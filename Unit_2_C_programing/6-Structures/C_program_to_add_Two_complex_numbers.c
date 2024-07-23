/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct Scomplex {
    float real;
    float imag ;
    
}N1,N2,Sum;
struct Scomplex add(struct Scomplex N1,struct Scomplex N2){
    struct Scomplex temp ;
    temp.real = N1.real+N2.real;
    temp.imag = N1.imag+N2.imag;
    
    return (temp) ; 
}
int main()
{
    
   printf("For 1st complex number : \n");
   printf("Enter real and imaginary respectively : ");
   scanf("%f",&N1.real);
   scanf("%f",&N1.imag);
   printf("For 2nd complex number : \n");
   printf("Enter real and imaginary respectively : ");
   scanf("%f",&N2.real);
   scanf("%f",&N2.imag);
   Sum =  add(N1,N2);
   printf("Sum = %.1f + %.1fi",Sum.real,Sum.imag);

   
    return 0;
}
