#include <stdio.h>
struct SInfo {
    char name[100];
    int roll_number ;
    float marks ;
    
}students;
int main()
{
   printf("Enter information of students : \n");
   printf("Enter name : ");
   scanf("%s",&students.name);
   printf("Enter roll : ");
   scanf("%d",&students.roll_number);
   printf("Enter marks : ");
   scanf("%f",&students.marks);
   
   printf("Displaying information\n name : %s \n Roll : %d \n Marks : %f ",students.name,students.roll_number,students.marks);

    return 0;
}
