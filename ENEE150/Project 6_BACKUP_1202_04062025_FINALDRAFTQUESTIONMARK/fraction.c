#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct
{
    int numerator;
    int denominator;
}   Fraction;

int findGCF(int a, int b)
{
    //Euclidean algorithm
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void displayMenuAndGetUserInput(char *UserInput, char tokensOfUserInput[][100])
{
    char charWeUsing[100];
    char *tokenPtr;
    // char temp1[100][100];
    int i = 0;

    printf("> ");
    gets(UserInput);

    strcpy(charWeUsing, UserInput);

    tokenPtr = strtok(charWeUsing, " ");

    while (tokenPtr != NULL)
    {
        strcpy(tokensOfUserInput[i++], tokenPtr);
        tokenPtr = strtok(NULL, " ");
    }
}

Fraction addFraction(Fraction Fraction1, Fraction Fraction2)
{
    Fraction result;
    result.numerator = (Fraction1.numerator * Fraction2.denominator) + (Fraction2.numerator * Fraction1.denominator);
    result.denominator = Fraction1.denominator * Fraction2.denominator;
    
    int gcf = findGCF(result.numerator, result.denominator);
    result.numerator /= gcf;
    result.denominator /= gcf;

    return result;
}

Fraction subFraction (Fraction Fraction1, Fraction Fraction2)
{
    Fraction result;
    result.numerator = (Fraction1.numerator * Fraction2.denominator) - (Fraction2.numerator * Fraction1.denominator);
    result.denominator = Fraction1.denominator * Fraction2.denominator;
    
    int gcf = findGCF(result.numerator, result.denominator);
    result.numerator /= gcf;
    result.denominator /= gcf;

    return result;
}

Fraction multiplyFraction (Fraction Fraction1, Fraction Fraction2)
{
    Fraction result;
    result.numerator = Fraction1.numerator * Fraction2.numerator;
    result.denominator = Fraction1.denominator * Fraction2.denominator;
    
    int gcf = findGCF(result.numerator, result.denominator);
    result.numerator /= gcf;
    result.denominator /= gcf;

    return result;
}

Fraction divideFraction (Fraction Fraction1, Fraction Fraction2)
{
    Fraction result;
    
    result.numerator = Fraction1.numerator * Fraction2.denominator;
    result.denominator = Fraction1.denominator * Fraction2.numerator;
    
    int gcf = findGCF(result.numerator, result.denominator);
    result.numerator /= gcf;
    result.denominator /= gcf;

    return result;
}

void displayFraction(Fraction fraction)
{
    if (fraction.denominator == 0)
    {
        printf("Denomintor cannot be zero. Please try again.\n");
        return;
    }

    else if (fraction.denominator == 1)
    {
        printf("Result is %d\n", fraction.numerator);
        return;
    }
    else if (fraction.numerator == 0)
    {
        printf("Result is 0\n");
        return;
    }

    else if (fraction.numerator < 0 && fraction.denominator < 0)
    {
        fraction.numerator = abs(fraction.numerator);
        fraction.denominator = abs(fraction.denominator);
    }
    else if (fraction.denominator < 0)
    {
        fraction.numerator = -fraction.numerator;
        fraction.denominator = abs(fraction.denominator);
    }
    // else if (fraction.numerator < 0)
    // {
    //     fraction.numerator = abs(fraction.numerator);
    //     fraction.denominator = abs(fraction.denominator);
    // }
    printf("Result is %d/%d\n", fraction.numerator, fraction.denominator);
}

int isInteger(const char *str)
{
    if (*str == '+' || *str == '-') // Check if there is a sign.
    {
        str++;
    }

    if (*str == '\0') // If the string is empty after the sign.
    {
        return 0;
    }

    while (*str) // Parse the entire string.
    {
        if (*str == '.') // Decimal point found.
        {
            return 0; // Return 0 for decimal numbers.
        }
        if (*str < '0' || *str > '9') // Non-digit character found.
        {
            return 0;
        }
        str++;
    }

    return 1; // Return 1 for valid integers.
}