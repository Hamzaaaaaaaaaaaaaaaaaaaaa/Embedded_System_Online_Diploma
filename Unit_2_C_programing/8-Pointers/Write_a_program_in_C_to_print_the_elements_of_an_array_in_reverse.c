
#include <stdio.h>
#include <string.h>
int main()
{
   int size,*Px, arr[15];
   printf("Input the number of elements to store in the array (max 15) :");
   scanf("%d",&size);
   Px = &arr[0];
   if(size < 15){
        printf("Input %d number of elements in the array : ",size);
        for(int i = 0;i< size;i++){
         printf("\nelement-%d : ",i+1);
         scanf("%d",Px);
         Px++;
        }
        
    Px = &arr[size-1];
       for(int i = size;i> 0;i--){
         printf("\nelement-%d : %d ",i,*Px);
         --Px;
        }
   }
    return 0;
}
