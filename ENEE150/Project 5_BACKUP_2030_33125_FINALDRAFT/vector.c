#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int areInputsInCorrectFormat(double **p, int k)
{
    if (k <= 4 && k > 0)
    {
        if (p[k] == NULL)
        {
            printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[1]);
            return 0;       //inputs do not check out.
        }
    }
    else if (k == -1)
    {
        printf("Error. Invalid vector name! Please try again.\n");
        return 0;
    }    
    if (p[k] == NULL)
    {
        printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[1]);
        return 0;
    }
    return 1;       //inputs check out.
}

int areInputsInCorrectFormatSecondParameter(double **p, int k)
{
    if (k <= 4 && k > 0)
    {
        if (p[k] == NULL)
        {
            printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[2]);
            return 0;       //inputs do not check out.
        }
    }
    else if (k == -1)
    {
        printf("Error. Invalid vector name! Please try again.\n");
        return 0;
    }    
    if (p[k] == NULL)
    {
        printf("Error. Vector %s is not assigned yet! Please try again.\n", tokensOfUserInput[2]);
        return 0;
    }
    return 1;       //inputs check out.
}

int isNumber(const char *str)
{
    int hasDecimalPoint = 0;

    if (*str == '+' || *str == '-')     //checks if there is a sign.
    {
        str++;
    }

    if (*str == '\0' || ((*str < '0' || *str > '9') && *str != '.'))        //if the string is empty or the character is not a digit or a decimal point.
    {
        return 0;
    }

    while (*str)        //parsing entire string.
    {
        if (*str == '.') {
            if (hasDecimalPoint) 
            {
                return 0;       //more than one decimal point found.
            }
            hasDecimalPoint = 1;
        } else if (*str < '0' || *str > '9')        //non digit character found.
        {
            return 0;
        }
        str++;
    }
    return 1;       //valid number.
}

int isSizeAnInteger(const char *str)
{
    if (*str == '+' || *str == '-')
    {
        str++;
    }

    if (*str < '0' || *str > '9')
    {
        return 0;
    }

    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            return 0;
        }
        str++;
    }
    return 1;
}

void vector_new(double **p, int *n, int k)
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
            free(new_vec);
            return;
        }
        else if (1 == isNumber(tokensOfUserInput[i + 2])) 
        {
            new_vec[i] = atof(tokensOfUserInput[i + 2]);
        }
    }
    
    free(p[k]);     //freeing previous vector if reassignment is good.

    p[k] = new_vec;

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

void vector_prn(double **p, const int *n)
{
    int areeInputsInCorrectFormat;
    if (*tokensOfUserInput[1] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k = GetVectorIndexByLetter(tokensOfUserInput[1]);
    
    areeInputsInCorrectFormat = areInputsInCorrectFormat(p, k);
    
    if (0 == areeInputsInCorrectFormat) 
    {
        return;
    }
    
    else if (1 == areeInputsInCorrectFormat) 
    {
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
}

void vector_sum (double **p, const int *n)
{
    int areeInputsInCorrectFormat;
    if (*tokensOfUserInput[1] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k = GetVectorIndexByLetter(tokensOfUserInput[1]);
    areeInputsInCorrectFormat = areInputsInCorrectFormat(p, k);

    if (areeInputsInCorrectFormat == 0)     //false
    {
        return;
    }

    else if (areeInputsInCorrectFormat == 1)        //true  
    {
        double sum = 0.0;
        for (int i = 0; i < *n; i++)
        {
            sum += p[k][i];
        }
        printf("Sum of elements of vector %s: %.2f\n", tokensOfUserInput[1], sum);
    }
}

void vector_neg (double **p, int *n)
{
    int areeInputsInCorrectFormat;
    // double **temp = p;
    if (*tokensOfUserInput[1] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k = GetVectorIndexByLetter(tokensOfUserInput[1]);
    // checkInputs(p,k);

    areeInputsInCorrectFormat = areInputsInCorrectFormat(p, k);

    if (0 == areeInputsInCorrectFormat)     //false
    {
        return; // Inputs do not check out, exit the function
    }
    else if (1 == areeInputsInCorrectFormat)        //true
    {
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
}

void vector_rms (double **p, int *n)
{
    int areeInputsInCorrectFormat;
    if (*tokensOfUserInput[1] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k = GetVectorIndexByLetter(tokensOfUserInput[1]);
    areeInputsInCorrectFormat = areInputsInCorrectFormat(p, k);

    if (areeInputsInCorrectFormat == 0)     //false
    {
        return;
    }

    else if (areeInputsInCorrectFormat == 1)        //true  
    {
        double sum = 0.0;
        for (int i = 0; i < *n; i++)
        {
            sum += p[k][i] * p[k][i];
        }
        double rms = sqrt(sum / *n);
        printf("RMS of vector %s: %.2f\n", tokensOfUserInput[1], rms);
    }
}

void vector_add (double **p, int *n)
{
    int areeInputsInCorrectFormat1;
    int areeInputsInCorrectFormat2;
    if (*tokensOfUserInput[1] == '\0' || *tokensOfUserInput[2] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k1 = GetVectorIndexByLetter(tokensOfUserInput[1]);
    int k2 = GetVectorIndexByLetter(tokensOfUserInput[2]);
    
    areeInputsInCorrectFormat1 = areInputsInCorrectFormat(p, k1);
    areeInputsInCorrectFormat2 = areInputsInCorrectFormatSecondParameter(p, k2);

    if (0 == areeInputsInCorrectFormat1|| 0 == areeInputsInCorrectFormat2)     //false
    {
        return;
    }

    else if (1 == areeInputsInCorrectFormat1|| 1 == areeInputsInCorrectFormat2)        //true  
    {
        double *temp = (double *)malloc(*n * sizeof(double));
        if (!temp)
        {
            printf("Error. Memory allocation failed!\n");
            return;
        }
        for (int i = 0; i < *n; i++)
        {
            temp[i] = p[k1][i] + p[k2][i];
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
}

void vector_sub (double **p, int *n)
{
    int areeInputsInCorrectFormat1;
    int areeInputsInCorrectFormat2;
    if (*tokensOfUserInput[1] == '\0' || *tokensOfUserInput[2] == '\0')
    {
        printf("Error. No vector specified! Please try again.\n");
        return;
    }
    int k1 = GetVectorIndexByLetter(tokensOfUserInput[1]);
    int k2 = GetVectorIndexByLetter(tokensOfUserInput[2]);
    
    areeInputsInCorrectFormat1 = areInputsInCorrectFormat(p, k1);
    areeInputsInCorrectFormat2 = areInputsInCorrectFormatSecondParameter(p, k2);

    if (0 == areeInputsInCorrectFormat1|| 0 == areeInputsInCorrectFormat2)     //false
    {
        return; // Inputs do not check out, exit the function
    }

    else if (1 == areeInputsInCorrectFormat1|| 1 == areeInputsInCorrectFormat2)        //true  
    {
        double *temp = (double *)malloc(*n * sizeof(double));
        if (!temp)
        {
            printf("Error. Memory allocation failed!\n");
            return;
        }
        for (int i = 0; i < *n; i++)
        {
            temp[i] = p[k1][i] - p[k2][i];
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