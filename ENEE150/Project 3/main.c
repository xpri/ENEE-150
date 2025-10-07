#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsItRect;
int IsItPolar;
char trash[100]; 

#define M_PI acos(-1)       //defines M_PI as pi.
//M_PI; Use for pi.

void thetaCALC(double x, double y,  double *thetaPtr)        //completes the calculation for any of the theta values.
{
    if (x > 0)
    {
        *thetaPtr = atan(y/x);
    }
    else if(x < 0)
    {
        *thetaPtr = atan(y/x) + M_PI;
    }
    else if(0 == x && y > 0)
    {
        *thetaPtr = M_PI/2;
    }
    else if(0 == x && y < 0)
    {
        *thetaPtr = -M_PI/2;
    }
    else if(0 == x && 0 == y)
    {
        *thetaPtr = 0;
    }
}

void RadToDeg(double *thetaPtr)     //changes a rad variable to degrees (for output to terminal).
{
    *thetaPtr = *thetaPtr * 180/M_PI;
    // printf("This is the value of theta (in degrees): %lf", thetaPtr);        //testing purposes
}

void DegToRad(double *thetaPtr)         //changes a degree variable to radians (for Userinput into trig functions).
{
    *thetaPtr = *thetaPtr * M_PI/180;
}

int getRect(double *xPtr, double *yPtr)         // Get rectangular coordinate. Validate inputs. Returns true(1) if rect is in correct /false(0) if rect is incorrect
{
    int ab;
    int cd;
    printf("Please input x value: ");
    ab = scanf("%lf", xPtr);

    if (ab != 1)
    {
        gets(trash);
        return 0;
    }    

    printf("Please input y value: ");
    cd = scanf("%lf", yPtr);

    if (cd != 1)
    {
        gets(trash);
        return 0;
    }
    return 1;
}

int getPolar(double *rPtr, double *thetaPtr)        //Get polar coordinate. Validate inputs. Return true/false
{
    int ab;
    int cd;
    printf("Please input r value: ");
    ab = scanf("%lf", rPtr);

    if (ab != 1)
    {
        gets(trash);
        return 0;
    }

    printf("Please input theta value: ");
    cd = scanf("%lf", thetaPtr);

    if (cd != 1)
    {
        gets(trash);
        return 0;
    }

    return 1;

}

void displayPolar(double r, double theta)       //Display the polar coordinate
{
    printf("This is the value of r: %.3f\n", r);
    printf("This is the value of theta (in degrees): %.3f\n", theta);
}

void displayRect(double x, double y)        //Display the rectangular coordinate
{
    printf("This is the value of x: %.3f\n", x);
    printf("This is the value of y: %.3f\n", y);
}

void RectToPolar(double x, double y, double *rPtr, double *thetaPtr)        //Convert rectangular coordinate to polar coordinate. Do not include the display of the polar coordinate.
{
    *rPtr = sqrt(x * x + y * y);
    // printf("This is r: %lf\n", *rPtr);       //testing purposes
    thetaCALC(x,y,thetaPtr);
    RadToDeg(thetaPtr);
    // printf("This is theta: %lf\n", *thetaPtr);       //testing purposes
}

void PolarToRect(double r, double theta, double *xPtr, double *yPtr)        //Conver polar coordinate to rectangular coordinate. Do not include the display of the rectangular coordinate.
{
    DegToRad(&theta);
    *xPtr = r*cos(theta);
    *yPtr = r*sin(theta);
}

void main()
{
    system("cls");      //make sure to change to system("clear") when running on UNIX based systems.
    int UserInput;
    int rv;
    double x;
    double y;
    double r;
    double theta;

    while (!(3 == UserInput))       //loops until user chooses 3.
    {
        printf("There are three options to choose from: 1 - rectangular to polar, 2 - polar to rectangular, or 3 - exit the program.\n");
        printf("The program will loop until option 3 is chosen.\n");
        printf("Please choose which option you desire: ");
        rv = scanf("%d", &UserInput);
        if (rv != 1)
        {
            gets(trash);
            UserInput = 0;
        }
        
        if (1 == UserInput)
        {
            // printf("This is when you picked 1.\n");
            IsItRect = getRect(&x, &y);         //the output of getRect is placed into IsItRect and IsItRect acts as a bool variable.
            if (1 == IsItRect)
            {
                RectToPolar(x,y,&r,&theta);
                displayPolar(r,theta);
                printf("\n");
            }
            else if (0 == IsItRect)         //this is what happenes when IsItRect is false.
            {
                printf("Invalid Data input. No calculations performed.\n\n");
            }           
        }
        else if(2 == UserInput)
        {
            IsItPolar = getPolar(&r, &theta);
            if (1 == IsItPolar)
            {
                PolarToRect(r,theta,&x,&y);
                displayRect(x,y);
                printf("\n");
            }
            else if(0 == IsItPolar)
            {
                printf("Invalid Data input. No calculations performed\n\n");
            }
        }
        else if (3 == UserInput)
        {
            printf("Program Terminated!\n");
            exit(0);
        }
        else
        {
            printf("Invalid input. Please enter an number between 1 and 3.\n");
            printf("\n");
        }
    }
}