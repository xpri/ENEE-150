#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LetterDictionary
{
    char myLetter;
    int count;
};



void DisplayStats(struct LetterDictionary a)
{
    //check if struct of letter 'a' has a count != 0. If so print the count.
    //check if struct of letter 'b' has a count != 0. If so print the count.
    if (a.count != 0)
    {
        printf("frequency of '%c': %d\n", a.myLetter, a.count);
    }
}

void CharCheck(struct LetterDictionary CurrentLetter, const char *current)
{
    for (int i = 0; i < strlen(current); i++)
    {
        if (current[i] == CurrentLetter.myLetter)
        {
            CurrentLetter.count++;
        }
    }
    DisplayStats(CurrentLetter);
}

void main()
{
    char arr[100];
    strcpy(arr,"Hello!A");


    struct LetterDictionary a;
    a.myLetter = 'a';
    a.count = 3;

    struct LetterDictionary b;
    b.myLetter = 'b';
    b.count = 5;

    struct LetterDictionary A;
    A.myLetter = 'A';
    A.count = 0;

    // DisplayStats(a);
    // DisplayStats(b);
    // DisplayStats(A);
    CharCheck(A, arr);
}

