#include <stdio.h>
#include <stdlib.h>

double sum;
int x;
int n;
char trash[100];

void noBufferFunc(int rv)
{
        while (rv != 1)
    {
        if (rv != 1)
        {
            printf("Invalid input. Please try again: ");
            gets(trash); //clears input buffer.
        }
}

void SumFunc(int j, int k)
{
    sum = 1;
    for (int i = 0; i <= k; i++)
    {
        // printf("Iteration i = %d\n", i);        //testing purposes
        sum += (double)i / (double)j;
        // printf("%f\n", sum);         //testing purposes
    }
    printf("%g", sum);
}

void main()
{
    printf("Please enter x: ");
    rv = scanf("%d", &x);
    printf("Please enter n: ");
    scanf("%d", &n);
    if (0 == x)
    {
        printf("x cannot be zero. Divide by zero error.");
        exit(1);
    }
    
    // printf("This is x: %d. This is n: %d.\n", x, n);     //testing purposes
    SumFunc(x,n);
}