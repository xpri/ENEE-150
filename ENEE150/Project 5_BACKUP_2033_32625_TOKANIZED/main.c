#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

char tokensOfUserInput[100][100];

void main()
{
    int NumNameOfVector;
    int SizeOfArray;
    double elements[100][100];         //This is a 2D array of doubles. The first number corresponds to NumNameOfVector and the second number corresponds to elements of the array.
    // char str[100];
    char UserInput[100];


    while (strcmp(UserInput, "exit") != 0)
    {
        displayMenuAndGetUserInput(UserInput, tokensOfUserInput);

        if ((GetVectorIndexByLetter(tokensOfUserInput[0]) != -1))
        {
            //0 1 2   3
            //A 2 3.5 2.0
            NumNameOfVector = GetVectorIndexByLetter(tokensOfUserInput[0]);
            SizeOfArray = atoi(tokensOfUserInput[1]);       //atio is ASCII to integer function. It converts ASCII to integer.
            for (int i = 0; i < SizeOfArray; i++)
            {
                // printf("P ITEMS %s\n", tokensOfUserInput[i + 2]);
                elements[NumNameOfVector][i] = atof(tokensOfUserInput[i + 2]); //atof is ASCII to double function. It converts ASCII to float.
                // printf("ELEMENT ITEMS %lf\n", elements[NumNameOfVector][i]);
                vector_new(&elements, &SizeOfArray, NumNameOfVector);
            }
            
            printf("NumNameOfVector: %d\n", NumNameOfVector);
            // printf("SizeOfArray: %d\n", SizeOfArray);
            // vector_new(&elements, &SizeOfArray, NumNameOfVector);
        }
        



        
        
        // scanf("%c %d %lf", );
        // NumNameOfVector = 1;

        // SizeOfArray = 3; // Update the size to match the number of elements
        // elements = (double *)malloc(SizeOfArray * sizeof(double)); // Allocate memory
        // if (elements == NULL) {
        //     printf("Memory allocation failed\n");
        //     return;
        // }
        
        // Assign values to the array
        // elements[0] = 2.0;
        // elements[1] = 3.5;
        // elements[2] = 2.0;

        // if (scanf("%d", &len) != 1 || len <= 0) 
        // {
        //     printf("Error. Invalid vector length!\n");
        //     while (getchar() != '\n'); // Clear the entire input line
        //     return;
        // }
        
        // vector_new(&elements, &SizeOfArray, NumNameOfVector);

        // NumNameOfVector = GetVectorIndexByLetter("B");
        // printf("NumNameOfVector: %d\n", NumNameOfVector);
    }
}