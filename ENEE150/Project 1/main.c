/*
Project 1
Statistical Measurements using Array
In this project, you will implement a statistical measurement tool for user input data.
Your program will ask the user to enter the number of data inputs (no more than 10) and all the
data.
ByL James Aspilcueta
1/27/25
*/
#include <stdio.h>
#include <stdlib.h> //now can use exit(1)
#include <math.h>
#include "FUNCS.c"

int length;
int rv; //initializing varaible for rv = scanf(__)
char trash[100]; //making the trash
int userDataChoose;         //in the ui where the user gets to pick which data analysis to choose.
int size;       //placeholder for size of the array for functions
double Average;
double sum;        //sum for functions that need an 'average' way

void noBufferINT(int var)      //includes an initial scanf and scanf recoverable buffer error. (FAILED FUNCTION)
{
    // int var; 
    int rv;
    char trash[100];
    // printf("Hello this is a testing facility for testing the input buffer erasing function.\n");
    rv = scanf("%d", &var);
    while (rv != 1)
    {
        printf("Invalid input. Please try again: ");
        gets(trash); //clears input buffer.
        rv = scanf("%d", &var);
    }
}

void noBufferDOUBLE(double var)     //Same as noBufferINT but works with double variables. (FAILED FUNCTION)
{
    int rv;
    char trash[100];
    // printf("Hello this is a testing facility for testing the input buffer erasing function.\n");
    rv = scanf("%lf", &var);
    while (rv != 1)
    {
        printf("Invalid input. Please try again: ");
        gets(trash); //clears input buffer.
        rv = scanf("%lf", &var);
    }
}

// void userChose0(double desiredNumbersTEMP, int userInputArraySize)       //when user choose zero, terminal display array that user inputted. (FAILED FUNCTION)
// {
//     double desiredNumbersTEMP[userInputArraySize];
//     printf("Here are the numbers you inputted:\n");
//     for (int i = 0; i < length; i++)
//     {
//         // printf("Here before array given\n");
//         printf("%lf ", desiredNumbersTEMP[i]);
//         // printf("Here after array given\n");
//     }
// }

void main()
{
    system("cls");      //make sure to change to system("clear") when running on UNIX based systems.
    printf("**************************************************\n");
    printf("Hello! Welcome to my user input analysis. You will\n");
    printf("be prompted to input data then select your desired\n");
    printf("operation until you select the exit option.\n");
    printf("Please enter the number of data inputs (maximum 10): ");
    // length = 0;      //testing purposes

    rv = scanf("%d", &length);
    while (rv != 1 || 10 < length || 1 > length)        //recoverable buffer error & when the number is out of bounds.
    {
        if (rv != 1)
        {
            printf("Invalid input. Please try again: ");
            gets(trash); //clears input buffer.
        }

        else if (10 < length)
        {
            printf("Maximum input is 10. Please try again: ");
        }

        else if (0 == length)
        {
            printf("Input cannot be zero. Please try again: ");
        }

        else if (1 > length)
        {
            printf("Input cannot be negative. Please try again: ");
        }

        rv = scanf("%d", &length);        
    }

    // printf("User inputted a value of %d\n", length);     //testing purposes
    printf("\n");

    printf("You will have to enter %d numbers for the data analysis.\n", length);       //telling user to input however any numbers they intially put in.

    double inputNum[length];        //initializing array for getting the numbers that user inputted.
    
    // for (int i = 0; i < length; i++)     //testing purposes
    // {
    //     printf("Please enter a number: ");
    //     scanf("%lf", &inputNum[i]);
    //     // noBufferDOUBLE(inputNum[i]);
    // }

    for (int i = 0; i < length; i++)        //keep in mind that if element inputNum[length - 2] is negative and inputNum[length - 1] is a zero than it incorrectly determines it as a zero crossing.
    {
        printf("Enter element %d: ", i + 1);
        rv = scanf("%lf", &inputNum[i]);
        while (rv != 1)
        {
            printf("Invalid input. Please enter element %d again: ", i + 1);
            gets(trash); //clears input buffer.
            rv = scanf("%lf", &inputNum[i]);
        }
    }

    // double inputNum[] = {1.5, 2.8391};       //testing purposes
    // inputNum[0] = 1.5;
    // inputNum[1] = 2.8371;

    // length = 2;

    // printf("%lf\n", &inputNum[0]);
   
    printf("\n");

    // printf("Now pick between these operations for data analysis.\n");
    // printf("The question will be asked until user chooses 'exit.'\n");
    
    //showing ui for navagating the data analysis. SO glad there is no median
    displayDataAnalysis();
    printf("\n");
    while (!(7 == userDataChoose))      //enter while loop for which data analysis the user wants. Will only stop when 7 == userDataChoose which is when the exit option will be chosen.
    {
        switch (userDataChoose)
        {
        case 0:
            printf("Here are the numbers you inputted: ");
            for (int i = 0; i < length; i++)
            {
                // printf("Here before array given\n");     //testing purposes
                printf("%.2lf ", inputNum[i]);
                // printf("Here after array given\n");
            }
            printf("\n\n");
            break;
        case 1:
            mean(inputNum, length);
            printf("\n\n");
            break;
        case 2:
            Minimum(inputNum, length);
            printf("\n\n");
            break;
        case 3:
            Maximum(inputNum, length);
            printf("\n\n");
            break;
        case 4:
            StandardDeviation(inputNum, length);
            printf("\n\n");
            break;
        case 5:
            AveragePower(inputNum, length);
            printf("\n\n");
            break;
        case 6:
            zcross(inputNum,length);
            printf("\n\n");
            break;
        default:
            break;
        }
        displayDataAnalysis();
    }
    printf("Program End\n");
    // exit(1); //program end
}