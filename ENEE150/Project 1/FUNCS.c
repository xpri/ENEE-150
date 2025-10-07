#include <stdio.h>
#include <math.h>

int length;
int rv; //initializing varaible for rv = scanf(__)
char trash[100]; //making the trash
int userDataChoose;         //in the ui where the user gets to pick which data analysis to choose.
int size;       //placeholder for size of the array for functions
double sum;        //sum for functions that need an 'average' way and for the mean function
double Average; //for the average and standard deviation function
double Var;
double VarTotal;
double VarAvg;

void mean(double *arr, int ArraySize)       //gets the average of all the numbers. Adds them all together and divides by the length of the array.
{
    sum = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        sum += arr[i];
    }
    // printf("%lf\n", sum);         //testing purposes
    Average = sum/ArraySize;
    printf("The mean is %.2lf\n", Average);
}

void Minimum(double *arr, int ArraySize)        //finds the minimum value in an array. Checks the next element in arr and see if it is smaller than the predetermined min.
{
    double min = arr[0];
    for (int i = 0; i < ArraySize; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("The minimum of the user inputs is: %.2lf\n", min);
}

void Maximum(double *arr, int ArraySize)        //finds the maximum value in an array. Checks the next element in arr and see if it is larger than the predetermined max.
{
    double max = arr[0];
    for (int i = 0; i < ArraySize; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("The maximum of the user inputs is: %.2lf\n", max);
}

void StandardDeviation(double *arr, int ArraySize)      //long long math... An (element minus the mean) squared divided by the length of arr. Then you take this value and take the square root.
{
    for (int i = 0; i < ArraySize; i++)
    {
        Var = Average - arr[i];     //average - arr or arr - average. Doesn't mater since it will be sequared anyway so the sign is lost.
        VarTotal += (Var * Var);
    }
    VarAvg = VarTotal/ArraySize;

    double a;
    a = sqrt(VarAvg);
    printf("Standard Deviation: %.2lf\n", a);
}

void AveragePower(double *arr, int ArraySize)       //square of an element and divides by the length of arr.
{

    double a;
    double atotal;
    double AvgPwr;
    atotal = 0;
    for (int i = 0; i < ArraySize; i++)
    {
        a = arr[i]*arr[i];
        atotal += a;
    }
    AvgPwr = atotal/ArraySize;
    printf("Average Power: %.2lf\n", AvgPwr);
}

void zcross(double *abc, int ArraySize) //counts how much zero crossings there are. enter while loop for which data analysis the user wants. Will only stop when 7 == userDataChoose which is when the exit option will be chosen.
{
    double b;
    // double tempN = 0; //any previous non-zero value
    int ZeroCrossing = 0;
    double c;
    for (int i = 0; i < ArraySize - 1; i++)
    {
        b = abc[(i + 1)] * abc[i];
        if (b < 0) //if b is a negative number than there has been a zero crossing (if the initial times the next number is negative then the values changed signs).
        {
            ZeroCrossing += 1;
            // printf("zero crossing: %d \n", ZeroCrossing); //this was used for preliminary testing
            // tempN = abc[i];      testing purposes
        }
        if (b == 0)
        {
            if(abc[i] != 0)
            {
                c = abc[i]*abc[(i + 2)]; //when the final i value is reached, it will become ArraySize + 1 and give a -0 error. This error helps us in this case but keep this in mind.
                if (c < 0) //if abc[i] times the next next number is negative, then there is a zero crossing.
                {
                    ZeroCrossing += 1;
                    // printf("abc[i] = %d \n", abc[i]);  //this was used for preliminary testing
                }
                // printf("tempN = %lf \n", tempN); //used for preliminary testing
                // tempN = abc[i];      testing purposes
            }
        }
    }
    printf("Total Zero Crossing: %d \n", ZeroCrossing);
}

void displayDataAnalysis()      //displays ui for the data analysis and asks user to input data
{
    printf("Now pick between these operations for data analysis.\n");
    printf("The question will be asked until user chooses 'exit.'\n");
    printf("(0) Display all data (precision of two).\n");
    printf("(1) Find the mean of the data.\n");
    printf("(2) Find the minimum of the data.\n");
    printf("(3) Find the maximum of the data.\n");
    printf("(4) Find the standard deviation of the data.\n");
    printf("(5) Find the average power of the data.\n");
    printf("(6) Find the number of zero crossings of the data.\n");
    printf("(7) Exit the program.\n\n");
    // printf("\n");
    printf("Please enter the data analysis option that you desire: ");
    rv = scanf("%d", &userDataChoose);
    // noBuffer(userDataChoose);
    while (rv != 1 || 7 < userDataChoose || 0 > userDataChoose)
    {
        if (rv != 1)
        {
            printf("Invalid input. Please try again: ");
            gets(trash); //clears input buffer.
        }

        else if (7 < userDataChoose)
        {
            printf("Maximum input is 7. Please try again: ");
        }

        else if (0 > userDataChoose)
        {
            printf("Input cannot be negative. Please try again: ");
        }

        rv = scanf("%d", &userDataChoose);        
    }
}