#include <stdio.h>
void reverse_array (int size,int a[],int b[])
{
    int i,j;
    for (i=size-1,j=0;i>=0;i--,j++)
    b[j]=a[i];
    printf("reverse array: ");
    for(i=0;i<size;i++)
    printf("\t%d",b[i]);
}
int main()
{
    int a[100],b[100],i,size;
    printf("Enter the size :");
    scanf("%d",&size);
   for(i=0;i<size;i++){
    printf("Enter Element %d : ",i+1);
     scanf("%d",&a[i]);
}
reverse_array(size ,a,b);

    return 0;
}
