#include <stdio.h>

int main() 
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    double arr[size];

    // Use the array
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%lf", &arr[i]);
    }

    printf("The array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%lf ", arr[i]);
    }
    printf("\n");

    return 0;
}