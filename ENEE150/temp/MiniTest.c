#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *num1, *num2, diff;
    int n[10];      //say address starts at 100
    
    for (int i = 0; i < 10; i++)
    {
        n[i] = i;
    }

    num1 = &n[4];
    // printf("This is the num1: %d\n", *num1);
    num2 = &n[5];

    diff = num2 - num1;
    /*diff = 120 - 116*/

    printf("This is the difference between num2 and num1 (num2-num1): %d\n", diff);
}