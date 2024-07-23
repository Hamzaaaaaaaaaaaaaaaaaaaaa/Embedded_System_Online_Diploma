#include <stdio.h>

int main()
{
    char A = 'A';
    char * Alpha = &A;  
    for(int i = 0 ; i < 26 ; i++){
        printf("%c\t",*Alpha);
        ++*Alpha;
    }
    return 0;
}
