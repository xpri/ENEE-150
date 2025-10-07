#include <stdio.h>
#include <stdlib.h>
char trash[100];        //making the trash for the recoverable function in scanfs.
int seat[12][6];
int rv;         //variable for the scanf if buffer fails
int total;      //was supposed to be used in connection with the sum function but later it was then used on it's own.
int UserInput;      //Variable for the userinput when asked which seat assignemnt they desire.
char ColumnHeader[] = {'A', 'B', 'C', 'D', 'E', 'F'};
int IssFirstFull;       //stores the output of the "IsFirstFull" function.
int IssEconomyFull;         //stores the output of the "IsEconomyFull" function.
int IssEconomyAisleFull;        //stores the output of "IsEconomyAisleFull" function.
int IssEconomyWindowFull;       //stores the output of "IsEconomyWindowFull" function.
int UserInputSwitchFromFirstClassToEconomy;         //variable to take in the user input when prompted with asking if first class is full if they wanted to go into economy.
int UserInputSwitchFromEconomyClassToFirst;         //variable to take in the user input when prompted with asking if economy class is full if they wanted to go into first.
int UserInputEconomySeatPreference;         //variable to hold the user input when prompted which seat preference they desire in economy.

void sum(int seat[12][6], int tot)        //This function was made to find out how many seats are taken. Did not end up using this function.
{
    tot = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            tot += seat[i][j];
        }
    }
    printf("THIS IS LINE 26 AND THE TOTAL IS %d AND SHOULD BE TWO", tot);
    // return tot;
}

int NoScanfBufferFail(int var)         //Takes out when scanf is an int but gets a string. Deletes the buffer and asks user to try again. Initial scanf already built in. Returns the correct and acceptable variable.
{
    rv = scanf("%d", &var);
    while (rv != 1)
    {
        printf("Invalid input. Please try again: ");
        gets(trash); //clears input buffer.
        rv = scanf("%d", &var);
    }
    return var;
}

void display(int seat[12][6])       //Displays the seats availble for the whole plane and then also displays the total capacity and how much seats are taken. seat[i][j]
{
    printf("     A B C D E F\n");
    for (int i = 0; i < 12; i++)
    {
        if (i < 9)      //If i is less than 9 (aka 8) then it will show 4 whitespaces.
        {
            printf("%d    ", i + 1);
        }
        else if (i > 8)         //If i is greater than 8 (aka 9) then it will show 3 whitespaces. This works because even thought i = 9 the number is 10. Thus there is an extra digit that takes up space.
        {
            printf("%d   ", i + 1);
        }
        for (int j = 0; j < 6; j++)
        {
            if (0 == i || 1 == i)
            {
                // printf(" ");
                if ((1 == j) || (4 == j))       //for the spaces for first class in column B and column E where there are no assignable seats.
                {
                    printf("  ");
                }
                else
                {
                    // printf(" ");
                    // printf("%d ", seat[i][j]);

                    if (1 == seat[i][j])
                    {
                        printf("X ");
                    }
                    else if (0 == seat[i][j])
                    {
                        printf("- ");
                    }
                }
            }
            else
            {
                if (1 == seat[i][j])        //If seat[i][j] is 1 aka if it is already assigned then mark it with an X.
                {
                    printf("X ");
                }
                else if (0 == seat[i][j])       //If seat[i][j] is not assigned (aka 0) then it will be marked with a -
                {
                    printf("- ");
                }
            }
        }
        printf("\n");
    }

    total = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            total += seat[i][j];
        }
    }
    // printf("THIS IS LINE 26 AND THE TOTAL IS %d AND SHOULD BE FOUR", total);      //testing purposes

    printf("\nTotal seats assigned (capacity 68): %d\n", total - 4);
}

int first(int seat[12][6])      //code that assigns a seat at random when customer asks for first class
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (0 == seat[i][j])        //checks if the seat is not assigned and then if it is not assigned then it assigns it and outputs the boarding pass.
            {
                printf("Your seat assignment: %d%c first class\n", i + 1, ColumnHeader[j]);
                seat[i][j] = 1;
                return 1;
            }
            // break;
        }
    }
    return 0;
}

int IsFirstFull(int seat[12][6])        //checks if the first class cabin is full. If true output 1 if false output 0.
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (0 == seat[i][j])
            {
                return 0;       //false
            }
        }
    }
    return 1;       //true
}

int IsEconomyFull(int seat[12][6])      //checks if the main cabin is full. If true output 1 if false output 0.
{
    for (int i = 2; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (0 == seat[i][j])
            {
                return 0;       //false
            }
        }
    }
    return 1;       //true
}

int IsEconomyAisleFull(int seat[12][6])         //checks if aisle column is full in the main cabin.
{
    for (int i = 2; i < 12; i++)
    {
        if (0 == seat[i][2])
        {
            return 0;       // false
        }
        else if (0 == seat[i][3])
        {
            return 0;       //false
        }       
    }
    return 1;       //true
}

int IsEconomyWindowFull(int seat[12][6])        //checks if window column is full in the main cabin.
{
    for (int i = 2; i < 12; i++)
    {
        if (0 == seat[i][0])
        {
            return 0;       // false
        }
        else if (0 == seat[i][5])
        {
            return 0;       //false
        }       
    }
    return 1;       //true
}

int economy(int seat[12][6])       //code that assigns a seat when customer asks. Seat preference is also in here. If output is 1 then seat is correctly assigned.
{
    printf("Economy seat preference (1 - window, 2 - aisle, 3 - any seat): ");
    UserInputEconomySeatPreference = NoScanfBufferFail(UserInputEconomySeatPreference);         //removes the buffer if incorrect variable is placed.
    switch (UserInputEconomySeatPreference)
    {
    case 1:         //When window position is chosen. ColumnHeader[0] is A, ColumnHeader[5] is F.
        IssEconomyWindowFull = IsEconomyWindowFull(seat);
        if (0 == IssEconomyWindowFull)
        {
            for (int i = 2; i < 12; i++)
            {
                if (0 == seat[i][0])
                {
                    printf("Your seat assignment: %d%c economy class\n", i + 1, ColumnHeader[0]);
                    seat[i][0] = 1;
                    return 1;
                }
                else if (0 == seat[i][5])
                {
                    printf("Your seat assignment: %d%c economy class\n", i + 1, ColumnHeader[5]);
                    seat[i][5] = 1;
                    return 1;
                }
            }
        }
        else if (1 == IssEconomyWindowFull)
        {
            printf("Sorry, all the window seats in the main cabin are full. Random seat will be assigned.\n");
            for (int i = 2; i < 12; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (0 == seat[i][j])
                    {
                        printf("Your seat assignment: %d%c economy class\n", i + 1, ColumnHeader[j]);
                        seat[i][j] = 1;
                        return 1;
                    }
                }
            }
        }
        
        break;
    case 2:         //When aisle position is chosen. ColumnHeader[2] is C, ColumnHeader[3] is D.
        IssEconomyAisleFull = IsEconomyAisleFull(seat);
        if (0 == IssEconomyAisleFull)
        {
            for (int i = 2; i < 12; i++)
            {            
                if (0 == seat[i][2])
                {
                    printf("Your seat assignment: %d%c economy class\n", i + 1, ColumnHeader[2]);
                    seat[i][2] = 1;
                    return 1;
                }
                else if (0 == seat[i][3])
                {
                    printf("Your seat assignment: %d%c economy class\n", i + 1, ColumnHeader[3]);
                    seat[i][3] = 1;
                    return 1;
                }
            }
        }
        else if (1 == IssEconomyAisleFull)
        {
            printf("Sorry, all the aisle seats in the main cabin are full. Random seat will be assigned.\n");
            for (int i = 2; i < 12; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (0 == seat[i][j])
                    {
                        printf("Your seat assignment: %d%c economy class\n", i + 1, ColumnHeader[j]);
                        seat[i][j] = 1;
                        return 1;
                    }
                }
            }
        }
        break;
    case 3:         //When random position is chosen.
        for (int i = 2; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (0 == seat[i][j])
                {
                    printf("Your seat assignment: %d%c economy class\n", i + 1, ColumnHeader[j]);
                    seat[i][j] = 1;
                    return 1;
                }
            }
        }
        break;
    default:
        printf("Please only enter valid options. No seat is assigned.\n");          //Not needed. In int main this statement is already given with the return of 0.
        return 0;
        break;
    }
    return 0;
}

int main()
{
    UserInput = 0;
    system("cls");
    // seat[]
    seat[0][1] = 1;     //these N/A seats cannot be assignable
    seat[0][4] = 1;     //these N/A seats cannot be assignable
    seat[1][1] = 1;     //these N/A seats cannot be assignable
    seat[1][4] = 1;     //these N/A seats cannot be assignable
        
    // seat[1][3] = 1;     //stubbing
    // seat[3][4] = 1;
    // seat[7][5] = 1;
    
    while (!(3 == UserInput))
    {
        printf("Seat Assignment: (1 - first class, 2 - economy class, 3 - exit program): ");
        UserInput = NoScanfBufferFail(UserInput);

        // rv = scanf("%d", &UserInput);
        // while (rv != 1)
        // {
        //     printf("Invalid input. Please enter which seat assignment you desire: ");
        //     gets(trash); //clears input buffer.
        //     rv = scanf("%d", &UserInput);
        // }

        if (1 == UserInput)
        {
            printf("\n");
            IssFirstFull = IsFirstFull(seat);
            if (1 == IssFirstFull)
            {
                IssEconomyFull = IsEconomyFull(seat);
                if (0 == IssEconomyFull)
                {
                    printf("First class is full, do you want to be placed in the economy class: (1- yes, 0 - no): ");

                    UserInputSwitchFromFirstClassToEconomy = NoScanfBufferFail(UserInputSwitchFromFirstClassToEconomy);

                    if (1 == UserInputSwitchFromFirstClassToEconomy)
                    {
                        economy(seat);
                    }
                    else if (0 == UserInputSwitchFromFirstClassToEconomy)
                    {
                        printf("Sorry, no seat is assigned.\n");
                    }
                    else if (!(1 == UserInputSwitchFromFirstClassToEconomy || 0 == UserInputSwitchFromFirstClassToEconomy))
                    {
                        printf("Please enter a valid input. No seat is assigned.\n");
                    }
                }
                else if (1 == IssEconomyFull)
                {
                    display(seat);
                    printf("Both cabins are full. Please find another flight.\n");
                    exit(1);
                }                                
            }
            else if (0 == IssFirstFull)
            {
                first(seat);

                // display(seat);      //Testing purposes
            }
        }
        else if (2 == UserInput)        //where economy is chosen
        {
            printf("\n");
            IssEconomyFull = IsEconomyFull(seat);         
            if (1 == IssEconomyFull)      //if it is true
            {   
                IssFirstFull = IsFirstFull(seat);
                if (0 == IssFirstFull)
                {
                    printf("Economy class is full, do you want to be placed in the first class: (1- yes, 0 - no): ");
                    UserInputSwitchFromEconomyClassToFirst = NoScanfBufferFail(UserInputSwitchFromEconomyClassToFirst);
                    if (1 == UserInputSwitchFromEconomyClassToFirst)
                    {
                        first(seat);
                        // printf("Test\n");        //testing purposes
                    }
                    else if (0 == UserInputSwitchFromEconomyClassToFirst)
                    {
                        printf("Sorry, no seat is assigned.\n");
                    }
                    else if (!(1 == UserInputSwitchFromEconomyClassToFirst || 0 == UserInputSwitchFromEconomyClassToFirst))
                    {
                        printf("Please enter a valid input. No seat is assigned.\n");
                    }
                    
                }
                else if (1 == IssFirstFull)
                {
                    display(seat);
                    printf("Both cabins are full. Please find another flight.\n");
                    exit(1);
                }
            }
            else if (0 == IssEconomyFull)
            {
                economy(seat);
                // display(seat);
            }
        }    
        else if (3 == UserInput)         //where user wants to exit
        {
            printf("\n");
            display(seat);
            exit(0);
        }
        else if (!(1 == UserInput || 2 == UserInput || 3 == UserInput))
        {
            printf("Invalid input. Please enter a number within the range.\n");
        }
        // else
        
        // {
        //     printf("Please enter a number within the range.");
        // }
        // display(seat);
        // return 0;
    }
    return 0;
}