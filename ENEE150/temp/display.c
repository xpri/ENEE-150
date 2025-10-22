#include <stdio.h>

int main (void)
{
    int value;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Please Enter an Integer: ");
        scanf("%d", &value);
        sum += value;
    }
    printf("Your sum is: %d.\n", sum);   
}