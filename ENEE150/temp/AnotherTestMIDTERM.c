#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x[10];
    int *UsingAsterisk;
    int *NotUsingAsterisk;

    for (int i = 0; i < 10; i++)
    {
        x[i] = i;
    }
    *UsingAsterisk = *x;
    NotUsingAsterisk = x;
    printf("This is using Asterisk: %d", UsingAsterisk);
    printf("This is not using Asterisk: %d", NotUsingAsterisk);
}