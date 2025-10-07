#include <stdio.h>
#include <stdlib.h>

void selectSort(int *arr, int n)        //n is size of array.
{
    int temp;
    for (int i = 0; i < n - 1; i++)     //i < n - 1 because array indexes start at 0.
    {
        int minimum = i;
        for (int j = i + 1; j < n; j++)     //Iterates after current index to find the minimum element.
        {
            if (arr[minimum] > arr[j]) //If the current element is greater the next element.
            {
                minimum = j; //Set the minimum to the current index.
            }
        }

        temp = arr[i]; //Set the temp to the current index.
        arr[i] = arr[minimum]; //Set the current index to the minimum index.
        arr[minimum] = temp; //Set the minimum index to the temp.       
    }
}

void main()
{
    int arr[] = {22, 11, 34, -5, 3, 40, 9, 16, 6};
    int n = sizeof(arr) / sizeof(arr[0]); //Calculate the size of the array.
    selectSort(arr, n); //Call the selectSort function.
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); //Print the sorted array.
    }
    printf("\n");
}