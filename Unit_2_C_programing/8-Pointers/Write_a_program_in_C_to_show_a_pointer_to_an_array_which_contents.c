#include <stdio.h>

struct employee 
{
    char *emp_name;
    int emp_id;
};

int main()
{
    struct employee emp1 = {"Hamza", 2002};
    struct employee emp2 = {"Ahmed", 4002};
    struct employee emp3 = {"Alex", 1002}; 
    struct employee *arr[] = {&emp1, &emp2, &emp3};
    struct employee *(*pt[3]) = {&arr[0], &arr[1], &arr[2]};

    printf("Employee Name: %s", (**(*pt+2)).emp_name);
    printf("\nEmployee ID: %d", (*(*pt+2))->emp_id);

    return 0;
}
