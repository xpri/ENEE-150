#include <stdio.h>
#include <stdlib.h>

void main()
{
    int x[10];
    int *p1;
    *p1 = x; // p points to the first element of x
    int y[] = {2, 4, -1, 1, 10, 6, 25, 0, 5};
    int *p3 = &y[5];
    printf("p3 = %d\n", *p3);
    printf("p1 = %d\n", *p1);
}