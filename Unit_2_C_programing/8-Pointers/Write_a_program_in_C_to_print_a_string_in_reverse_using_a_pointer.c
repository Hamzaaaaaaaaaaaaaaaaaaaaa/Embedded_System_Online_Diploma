
#include <stdio.h>
#include <string.h>
int main()
{
    char arr[50], reverse[50];
    printf("Input string :");
    scanf ("%s",arr);
    char*Ps = arr;
    printf("\nPointer : print a string in reverse order :\n");
    printf("\n-------------------------------------------\n");

    printf("Input string : %s\n",arr);
    int n = strlen(arr);
     for(int i = 0 ; i<n/2 ; i++)
     {
       int temp = *(Ps+i);
       *(Ps+i)  = *(Ps+n-1-i);
       *(Ps+n-1-i) = temp ;
       
     }
     for(int i = 0 ; i<n ; i++)
    reverse[i]=*(Ps+i);
     printf("Reverse of the string is :%s",reverse);
    return 0;
}
