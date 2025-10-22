#include <stdio.h>

void main()
{
    int x = 25;
    int *ptr;
    ptr = &x;
    printf("This is the address of x: %p\n", ptr); //unsigned integer in hexadecimal system
    printf("This is the address of x using: %d\n", ptr); //unsigned integer in hexadecimal system
    printf("This is the address of x using * infront of ptr: %p\n", *ptr); //unsigned integer in hexadecimal system
    printf("This is the value of x: %d\n", *ptr);
}