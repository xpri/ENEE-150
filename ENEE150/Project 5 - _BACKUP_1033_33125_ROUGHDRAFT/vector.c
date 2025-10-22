#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// char tokensOfUserInput[100][100];
extern char tokensOfUserInput[100][100]; // Declare the variable as external

int GetVectorIndexByLetter(const char *letter)
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

void checkInputs(double **p, int k)
{
    if (k <= 4 && k > 0)
    {
        if (p[k] == NULL)
        {
            printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[1]);
            return;
        }
    }
    else if (k == -1)
    {
        printf("Error. Invalid vector name! Please try again.\n");
        return;
    }    
    if (p[k] == NULL)
    {
        printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[1]);
        return;
    }
}

// int isNumber(const char *str) 
// {
//     if (*str == '\0' || (*str < '0' || *str > '9'))
//     {
//         return 0; // Not a valid number
//     }
//     return 1; // Valid number
// }

int isNumber(const char *str) 
{
    int hasDecimalPoint = 0; // Flag to track if a decimal point is present

    // Skip leading whitespace
    while (*str == ' ' || *str == '\t') 
    {
        str++;
    }

    // Check for optional sign
    if (*str == '+' || *str == '-') 
    {
        str++;
    }

    // Ensure there is at least one digit or a decimal point
    if (*str == '\0' || ((*str < '0' || *str > '9') && *str != '.')) 
    {
        return 0; // Not a valid number
    }

    // Iterate through the rest of the string
    while (*str) 
    {
        if (*str == '.') {
            if (hasDecimalPoint) 
            {
                return 0; // More than one decimal point
            }
            hasDecimalPoint = 1; // Mark that a decimal point was found
        } else if (*str < '0' || *str > '9') 
        {
            return 0; // Non-digit character found
        }
        str++;
    }

    return 1; // Valid number
}

int isSizeAnInteger(const char *str)
{
    // Skip leading whitespace
    while (*str == ' ' || *str == '\t')
    {
        str++;
    }

    // Check for optional sign
    if (*str == '+' || *str == '-')
    {
        str++;
    }

    // Ensure there is at least one digit
    if (*str < '0' || *str > '9')
    {
        return 0; // Not a valid integer
    }

    // Check the rest of the string
    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            return 0; // Non-digit character found
        }
        str++;
    }

    return 1; // Valid integer
}

void vector_new(double **p, const int *n, const int k) 
{

    
    double *new_vec = NULL;
    
    new_vec = (double*)malloc(*n * sizeof(double)); 
    if (!new_vec) 
    {
        printf("Error. Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < *n; i++)
    {
        if (0 == isNumber(tokensOfUserInput[i + 2])) 
        {
            printf("Error. Invalid vector input!\n");
            free(new_vec); // Free allocated memory before exiting
            return;
        }
        else if (1 == isNumber(tokensOfUserInput[i + 2])) 
        {
            new_vec[i] = atof(tokensOfUserInput[i + 2]); // Convert string to double
        }
    }
    free(p[k]);     //freeing previous vector if reassignment is good.

    // Assign new vector
    p[k] = new_vec;

    printf("(");
    for (int i = 0; i < *n; i++) {
        if (i < *n - 1) {
            printf("%.2f, ", p[k][i]);
        } else {
            printf("%.2f", p[k][i]);
        }
    }
    printf(")\n");
}

void vector_prn(double **p, const int *n)
{
    if (*tokensOfUserInput[1] == '\0') {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k = GetVectorIndexByLetter(tokensOfUserInput[1]);
    checkInputs(p, k);      //FIX BC CRASH
    // if (k <= 4 && k > 0)
    // {
    //     if (p[k] == NULL)
    //     {
    //         printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[1]);
    //         return;
    //     }
    // }
    // else if (k == -1)
    // {
    //     printf("Error. Invalid vector name! Please try again.\n");
    //     return;
    // }    
    // if (p[k] == NULL)
    // {
    //     printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[1]);
    //     return;
    // }
    // int len = atof(tokensOfUserInput[1]);
    printf("(");
    for (int i = 0; i < *n; i++)
    {
        if (i < *n - 1)
        {
            printf("%.2f, ", p[k][i]);
        } else
        {
            printf("%.2f", p[k][i]);
        }
    }
    printf(")\n");
}

void vector_sum (double **p, const int *n)
{
    if (*tokensOfUserInput[1] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k = GetVectorIndexByLetter(tokensOfUserInput[1]);
    if (p[k] == NULL)
    {
        printf("Error. Vector not initialized! Please try again.\n");
        return;
    }
    double sum = 0.0;
    for (int i = 0; i < *n; i++)
    {
        sum += p[k][i];
    }
    printf("Sum of elements of vector %s: %.2f\n", tokensOfUserInput[1], sum);
}

void vector_neg (double **p, int *n)
{
    // double **temp = p;
    if (*tokensOfUserInput[1] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k = GetVectorIndexByLetter(tokensOfUserInput[1]);
    checkInputs(p,k);
    double *temp = (double *)malloc(*n * sizeof(double));
    if (!temp)
    {
        printf("Error. Memory allocation failed!\n");
        return;
    }
    for (int i = 0; i < *n; i++)
    {
        temp[i] = -p[k][i];
    }
    printf("(");
    for (int i = 0; i < *n; i++)
    {
        if (i < *n - 1)
        {
            printf("%.2f, ", temp[i]);
        } else
        {
            printf("%.2f", temp[i]);
        }
    }
    printf(")\n");
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