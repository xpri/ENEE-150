#include <stdio.h>
#include <string.h>

void main()
{
    char string[100];
    char *tokenPtr;
    char temp[100][100];
    int i = 0, j;

    printf("Please enter a sentence: ");
    gets(string);

    printf("Tokens are:\n");

    tokenPtr = strtok(string, " ");

    while (tokenPtr != NULL)
    {
        strcpy(temp[i++], tokenPtr);
        tokenPtr = strtok(NULL, " ");
    }
    for (j = i - 1; j >= 0; j--)
    {
        puts(temp[j]);
    }
}