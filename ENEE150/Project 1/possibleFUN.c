#include <stdio.h>

void main()
{
    int inputNum;
    printf("Please enter number: ");
    scanf("%d", inputNum);
    printf("Here is your input %s", inputNum);
    switch (inputNum)
    {
    case (0):
        printf("Please enter a value of greater than 1.");
        break;
    
    default:
        break;
    }
}

//clearing the input buffer is gets(trash)