#include <stdio.h>

int main() {
    int x, y;
    printf("Enter value of x: ");
    scanf("%d", &x);
    printf("Enter value of y: ");
    scanf("%d", &y);

    x = x ^ y; 
    y = x ^ y; 
    x = x ^ y; 

    printf("After swapping, value of x: %d\n", x);
    printf("After swapping, value of y: %d\n", y);

    return 0;
}
