
#include <stdio.h>
union job{
    char name [32];
    float salary;
    int worker_no;
    
}u;
struct job1{
    char name [32];
    float salary;
    int worker_no;
    
}s;
int main()
{
    printf("Size of union = %d\n",sizeof(u));
    printf("Size of struct  = %d",sizeof(s));

    return 0;
}
