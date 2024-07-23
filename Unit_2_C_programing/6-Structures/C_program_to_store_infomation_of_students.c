/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
struct Student {
    char name[50];
    int roll;
    float marks ;
    
};

int main()
{
    struct Student s[10];
    int i ;
   printf("Enter information of students: \n");
   for(i=0;i<10;++i){
       s[i].roll = i+1 ;
       printf("For roll number %d: \n",s[i].roll);
       printf("Enter name : \n");
       scanf("%s",&s[i].name);
       printf("Enter marks : \n");
       scanf("%f",&s[i].marks);
       printf("\n");


   }
      printf("Displaying information of students : \n");
for(i=0;i<10;++i){
       printf("\ninformation of roll number %d\n",i+1);
       printf("name : ");
       puts(s[i].name);
       printf("Marks: %.1f",s[i].marks);

   }
    return 0;
}
