#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

char tokensOfUserInput[100][100] = {{0}};

int main()
{
    system("cls");
    // system("clear"); // For Linux or MacOS
    int NumNameOfVector;
    int vectorSizes[100] = {0}; // Stores sizes for each vector

    int SizeOfArray;
    double *elements[100] = {NULL};         //This is a 2D array of doubles. The first number corresponds to NumNameOfVector and the second number corresponds to elements of the array.
    // char str[100];
    char UserInput[100];


    while (strcmp(UserInput, "exit") != 0)
    {
        displayMenuAndGetUserInput(UserInput, tokensOfUserInput);

        if ((GetVectorIndexByLetter(tokensOfUserInput[0]) != -1))
        {
            // printf("HELLO WORLD\n");
            //0 1  2   3
            //A 2 3.5 2.0
            NumNameOfVector = GetVectorIndexByLetter(tokensOfUserInput[0]);
            if ((0 == isSizeAnInteger(tokensOfUserInput[1])) || (0 == isValidVectorLength(tokensOfUserInput[1])))
            {
                printf("Error. Invalid vector length!\n");
            }
            else if (tokensOfUserInput[1][0] == '\0')
            {
                printf("Error. No vector length specified!\n");
            }
            else if (tokensOfUserInput[2][0] == '\0')
            {
                printf("Error. No vector elements specified!\n");
            }
            else if (1 == isSizeAnInteger(tokensOfUserInput[1]))
            {
                int isVectorGood = 0;       // check if the vector is good

                for (int i = 0; i < atoi(tokensOfUserInput[1]); i++)
                {
                    if (0 == isNumber(tokensOfUserInput[i + 2])) 
                    {
                        printf("Error. Invalid vector input!\n");
                        isVectorGood++; // vector is not good
                        // free(new_vec);
                        // n[k] = 0;       //reset the size of the vector to 0.
                    }
                }
                if (0 == isVectorGood)
                {
                    SizeOfArray = atoi(tokensOfUserInput[1]);       //atio is ASCII to integer function. It converts ASCII to integer.
                    vectorSizes[NumNameOfVector] = SizeOfArray; // Store size of vector
                    vector_new(elements, vectorSizes, NumNameOfVector); //This function creates a new vector. It takes the 2D array of doubles, the size of the array and the name of the vector as parameters.
                }
                
                // SizeOfArray = atoi(tokensOfUserInput[1]);       //atio is ASCII to integer function. It converts ASCII to integer.
                // vectorSizes[NumNameOfVector] = SizeOfArray; // Store size of vector
                // vector_new(elements, vectorSizes, NumNameOfVector); //This function creates a new vector. It takes the 2D array of doubles, the size of the array and the name of the vector as parameters.
            }
        }
        else if (strcmp(tokensOfUserInput[0], "prn") == 0)
        {
            vector_prn(elements, vectorSizes);
        }
        else if (strcmp(tokensOfUserInput[0], "sum") == 0)
        {
            vector_sum(elements, vectorSizes);
        }
        else if (strcmp(tokensOfUserInput[0], "rms") == 0)
        {
            vector_rms(elements, vectorSizes);
        }
        else if (strcmp(tokensOfUserInput[0], "neg") == 0)
        {
            vector_neg(elements, vectorSizes);
        }
        else if (strcmp(tokensOfUserInput[0], "add") == 0)
        {
            vector_add(elements, vectorSizes);
        }
        else if (strcmp(tokensOfUserInput[0], "sub") == 0)
        {
            vector_sub(elements, vectorSizes);
        }
        else if (strcmp(tokensOfUserInput[0], "exit") == 0)
        {
            printf("Exiting the program...\n");
            // free allocated memory for vectors
            for (int i = 0; i < 100; i++)
            {
                if (elements[i] != NULL)
                {
                    // printf("Iteration %d\n", i);
                    free(elements[i]);
                }
            }
            break;
        }
        else
        {
            printf("Error. Invalid command!\n");
        }
        //clear the UserInput and tokensOfUserInput arrays
        for (int i = 0; i < (int)sizeof(UserInput); i++)
        {
            UserInput[i] = '\0';
        }
        
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                tokensOfUserInput[i][j] = '\0';
            }
        }
    }
    return 0;
}