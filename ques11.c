#include <stdio.h>


void compareNumbers(int *num1, int *num2) {
    if (*num1 == *num2) {
        printf("Numbers are equal.\n");
    } else if (*num1 > *num2) {
        printf("First number is greater.\n");
    } else {
        printf("Second number is greater.\n");
    }
}

int main() {
    int num1, num2;


    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);


    compareNumbers(&num1, &num2);

    return 0;
}

