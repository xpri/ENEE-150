#include <stdio.h>  
#include <stdbool.h>


void noBuffer(int var, int UpperBound, int LowerBound, bool hi)      //includes an initial scanf and scanf recoverable buffer error. Stores 
{
    // int var; 
    int rv;
    char trash[100];
    // printf("Hello this is a testing facility for testing the input buffer erasing function.\n");
    rv = scanf("%d", &var);
    while (rv != 1 || UpperBound < var || LowerBound > var)
    {
        if (rv != 1)
        {
            printf("Invalid input. Please try again: ");
            gets(trash); //clears input buffer.
        }

        else if (UpperBound < var)
        {
            printf("Maximum input is 10. Please try again: ");
        }
        if (true == hi)
        {
            if (0 == var)
            {
                printf("Input cannot be zero. Please try again: ");
            }
        }
        else if (LowerBound > var)
        {
            printf("Input cannot be negative. Please try again: ");
        }

        rv = scanf("%d", &var);        
    }

}
void main()
{
    int hello;
    printf("Enter number here: ");
    noBuffer(hello,10,-1,1);
}

