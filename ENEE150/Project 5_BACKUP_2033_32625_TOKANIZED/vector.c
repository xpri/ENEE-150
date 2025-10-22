#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tokensOfUserInput[100][100];

void vector_new(double **p, int *n, int k) 
{
    int len;
    double *new_vec = NULL;
    
    new_vec = (double*)malloc(len * sizeof(double)); 
    if (!new_vec) 
    {
        printf("Error. Memory allocation failed!\n");
        exit(1);
    }

    // Read all elements in one continuous parse
    for (int i = 0; i < len; i++) 
    {
        if (scanf("%lf", &new_vec[i]) != 1) 
        {
            printf("Error. Invalid vector element!\n");
            free(new_vec);
            while (getchar() != '\n'); // Clear remaining input
            return;
        }
    }

    // Free old vector if it exists
    if (p[k]) 
    {
        free(p[k]);
    }

    // Assign new vector
    p[k] = new_vec;
    n[k] = len;

    // Print the vector
    printf("(");
    for (int i = 0; i < len; i++) 
    {
        printf("%.2f%s", p[k][i], (i < len-1) ? ", " : "");
    }
    printf(")\n");
}

int GetVectorIndexByLetter(char *letter)
{
    if (strcmp(letter, "A") == 0)
    {
        // printf("A is 0\n");
        return 0;
    }
    else if (strcmp(letter, "B") == 0)
    {
        // printf("B is 1\n");
        return 1;
    }
    else if (strcmp(letter, "C") == 0)
    {
        // printf("C is 2\n");
        return 2;
    }
    else if (strcmp(letter, "D") == 0)
    {
        // printf("D is 3\n");
        return 3;
    }
    else
    {
        // printf("Error. Invalid command!\n");
        return -1;
    }
}

void displayMenuAndGetUserInput(char *UserInput, char tokensOfUserInput[][100])
{
    char charWeUsing[100];
    char *tokenPtr;
    // char temp1[100][100];
    int i = 0;

    printf("calc> ");
    gets(UserInput);

    strcpy(charWeUsing, UserInput);

    tokenPtr = strtok(charWeUsing, " ");

    while (tokenPtr != NULL)
    {
        strcpy(tokensOfUserInput[i++], tokenPtr);
        tokenPtr = strtok(NULL, " ");
    }
}