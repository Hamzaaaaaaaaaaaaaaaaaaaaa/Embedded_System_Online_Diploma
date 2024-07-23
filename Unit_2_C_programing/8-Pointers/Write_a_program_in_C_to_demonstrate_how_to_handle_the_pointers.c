
#include <stdio.h>

int main()
{
    int m = 29;
printf("\nAddress of m : %x\n Value of m : %d\n",&m,m);
    int*ab = &m ;
    printf("\nNow ab is assigned with the address of m.\n");
printf("\nAddress of pointer ab : %x\n content of pointer ab : %d\n",&ab,*ab);
    m = 34;
    printf("\nThe value of m assigned to 34 now.\n");
printf("\nAddress of pointer ab : %x\n content of pointer ab : %d\n",&ab,*ab);
     *ab = 7 ;
    printf("\nThe pointer variable ab is assigned with the value 7 now.\n");
printf("Address of m : %x\n Value of m : %d",&m,m);
    return 0;
}
