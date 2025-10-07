#include <stdio.h>
#include <stdlib.h>

void main()
{
    while ((c= getchar()) != '\n' )
    {
        stack_push(s, c);
        }
            while (stack_height(s) > 0)
        {
        
        printf("%c", stack_pop(s));
    }
}