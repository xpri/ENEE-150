#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fraction.h"

char tokensOfUserInput[100][100] = {{0}};

int main()
{
    char UserInput[100];
    system("cls");
    // system("clear"); // For Linux or MacOS

    Fraction fraction1, fraction2, fractionOutput, result;
    char operator;

    while (strcmp(UserInput, "$") !=0)
    {       
        displayMenuAndGetUserInput(UserInput, tokensOfUserInput);
        
        if (0 == isInteger(tokensOfUserInput[1]) || 0 == isInteger(tokensOfUserInput[2]) || 0 == isInteger(tokensOfUserInput[3]) || 0 == isInteger(tokensOfUserInput[4]))
        {
            printf("Please enter a valid input.\n");
        }
        else if (tokensOfUserInput[5][0] != '\0')
        {
            printf("Too many inputs! Please try again.\n");
        }
        else if (atoi(tokensOfUserInput[2]) == 0 || atoi(tokensOfUserInput[4]) == 0)
        {
            printf("Denominator cannot be zero. Please try again.\n");
        }
        else
        {
            fraction1.numerator = atoi(tokensOfUserInput[1]);
            fraction1.denominator = atoi(tokensOfUserInput[2]);
            fraction2.numerator = atoi(tokensOfUserInput[3]);
            fraction2.denominator = atoi(tokensOfUserInput[4]);

            if (strcmp(tokensOfUserInput[0], "+") == 0)
            {
                fractionOutput = addFraction(fraction1, fraction2);
                displayFraction(fractionOutput);
            }
            else if (strcmp(tokensOfUserInput[0], "-") == 0)
            {
                fractionOutput = subFraction(fraction1, fraction2);
                displayFraction(fractionOutput);
            
            }
            else if (strcmp(tokensOfUserInput[0], "*") == 0)
            {
                fractionOutput = multiplyFraction(fraction1, fraction2);
                displayFraction(fractionOutput);
            }
            else if (strcmp(tokensOfUserInput[0], "/") == 0)
            {
                fractionOutput = divideFraction(fraction1, fraction2);
                displayFraction(fractionOutput);
            }
            else if (strcmp(tokensOfUserInput[0], "$") == 0)
            {
                printf("Exiting the program.\n");
                break;
            }
            else 
            {
                printf("Invalid operator. Please use +, -, *, or /.\n");
            }
        }
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
}