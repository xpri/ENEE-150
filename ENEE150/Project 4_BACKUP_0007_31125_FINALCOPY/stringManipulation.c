#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_HISTORY_SIZE 10 /*the maximum size of the history*/
#define MAX_STR_LEN 100 /*the maximum size of strings*/
#define MAX_CMD_LEN 10 /*the maximum size of a command*/

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
        printf("   frequency of '%c': %d\n", a.myLetter, a.count);
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

int NumOfWords(const char *current)
{
    char *tokenPtr;
    char NewCurrent[100];
    char temp[100][100];
    int i = 0, j = 0;

    strcpy(NewCurrent, current);
    tokenPtr = strtok(NewCurrent, " ");

    while (tokenPtr != NULL)
    {
        strcpy(temp[i++], tokenPtr);
        tokenPtr = strtok(NULL, " ");
        j++;
    }
    return j;
}

void printHelp()
{
    printf("[new] Enter new string\n"
    "[list] List current string\n"
    "[find] Find occurrence of a character in current string\n"
    "[toggle] Toggle the case of current string\n"
    "[compress] Print non-repeated characters of the current string\n"
    "[reverse] Print current string in reverse order word by word\n"
    "[replace] Replace current String with output of last command\n"
    "[stat] Print statistics of current string\n"
    "[help] Print this help screen\n"
    "[hist] Print a history of commands entered\n"
    "[quit] Quit program\n");
}

void getString(char *current)
{
    printf("Enter new string: ");
    gets(current);
}

void list(char *current)
{
    printf("%s\n", current);
}

void findString (const char *current)
{
    char FindChar[1];
    int FindCharNumberOfTimes;
    printf("Enter a character: ");
    gets(FindChar);         //Gets sometimes messes up assignment integer variables before gets is executed. gcc 14.2.0. J&E
    FindCharNumberOfTimes = 0;

    for (int i = 0; i < strlen(current); i++)
    {
        if (FindChar[0] == current[i])
        {
            FindCharNumberOfTimes++;
            // printf("'%c' matched %d\n", FindChar[0], FindCharNumberOfTimes);
        }
    }
    
    printf("The character '%c' exists %d times in the current string.\n", FindChar[0], FindCharNumberOfTimes);
    // printf("The character '' exists %d times in the current string", FindCharNumberOfTimes);
}

void toggleString(const char *current, char *result)
{
    char temp[100];
    strcpy(temp, current);
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] >= 97 && temp[i] <= 122)      //uses ascii codes 97 (a) to 112 (z) and checks if it is in the lowercase range and then translates it into the uppercase range by subtracting 32.
        {
            temp[i] = temp[i] - 32;
        }
        else if (temp[i] >= 65 && temp[i] <= 90)        //uses ascii codes 65 (A) to 90 (Z) and checks if it is in the uppercase range and then translates it into the lowercase range by adding 32.
        {
            temp[i] = temp[i] + 32;
        }
    }
    // printf("%s\n", temp);
    strcpy(result, temp);
    printf("%s\n", result);
}

void replaceString (char *current, char *result)
{
    strcpy(current, result);
    printf("%s\n",current);
}

void printHistory(char history[MAX_HISTORY_SIZE][MAX_CMD_LEN], int historySize)
{
    printf("The history is: \n");
    if (historySize <= 10)
    {
        for (int i = 0; i < historySize; i++)
        {
            printf("    %s\n", history[i]);
        }
    }
    else if (historySize > 10)
    {
        for (int i = historySize - 10; i < historySize; i++)
        {
            printf("    %s\n", history[i]);
        }
    }
    
}

void reverseString (const char *current, char *result)
{
    // char string[100];
    char charWeUsing[100];
    char *tokenPtr;
    char temp1[100][100];
    char temp2[100] = "test";
    int i = 0, j;

    strcpy(charWeUsing, current);
    // printf("Please enter a sentence: ");
    // gets(string);

    // printf("Tokens are:\n");

    tokenPtr = strtok(charWeUsing, " ");

    while (tokenPtr != NULL)
    {

        strcpy(temp1[i++], tokenPtr);

        // printf("%d\n", i);
        // strcpy(temp2, temp1[i]);
        // puts(temp2);
        
        // strcat(temp2, temp1[i]);

        tokenPtr = strtok(NULL, " ");
    }
    for (j = i - 1; j >= 0; j--)
    {
        printf("%s ",temp1[j]);

        if (j == i - 1)
        {
            strcpy(result, temp1[j]);  //Overwrites for the first word
        }
        else
        {
            strcat(result, " ");
            strcat(result, temp1[j]);
        }
    }
    printf("\n");
}

void printStatistics (const char *current)
{
    struct LetterDictionary L_a;
    L_a.myLetter = 'a';
    L_a.count = 0;
    struct LetterDictionary L_b;
    L_b.myLetter = 'b';
    L_b.count = 0;
    struct LetterDictionary L_c;
    L_c.myLetter = 'c';
    L_c.count = 0;
    struct LetterDictionary L_d;
    L_d.myLetter = 'd';
    L_d.count = 0;
    struct LetterDictionary L_e;
    L_e.myLetter = 'e';
    L_e.count = 0;
    struct LetterDictionary L_f;
    L_f.myLetter = 'f';
    L_f.count = 0;
    struct LetterDictionary L_g;
    L_g.myLetter = 'g';
    L_g.count = 0;
    struct LetterDictionary L_h;
    L_h.myLetter = 'h';
    L_h.count = 0;
    struct LetterDictionary L_i;
    L_i.myLetter = 'i';
    L_i.count = 0;
    struct LetterDictionary L_j;
    L_j.myLetter = 'j';
    L_j.count = 0;
    struct LetterDictionary L_k;
    L_k.myLetter = 'k';
    L_k.count = 0;
    struct LetterDictionary L_l;
    L_l.myLetter = 'l';
    L_l.count = 0;
    struct LetterDictionary L_m;
    L_m.myLetter = 'm';
    L_m.count = 0;
    struct LetterDictionary L_n;
    L_n.myLetter = 'n';
    L_n.count = 0;
    struct LetterDictionary L_o;
    L_o.myLetter = 'o';
    L_o.count = 0;
    struct LetterDictionary L_p;
    L_p.myLetter = 'p';
    L_p.count = 0;
    struct LetterDictionary L_q;
    L_q.myLetter = 'q';
    L_q.count = 0;
    struct LetterDictionary L_r;
    L_r.myLetter = 'r';
    L_r.count = 0;
    struct LetterDictionary L_s;
    L_s.myLetter = 's';
    L_s.count = 0;
    struct LetterDictionary L_t;
    L_t.myLetter = 't';
    L_t.count = 0;
    struct LetterDictionary L_u;
    L_u.myLetter = 'u';
    L_u.count = 0;
    struct LetterDictionary L_v;
    L_v.myLetter = 'v';
    L_v.count = 0;
    struct LetterDictionary L_w;
    L_w.myLetter = 'w';
    L_w.count = 0;
    struct LetterDictionary L_x;
    L_x.myLetter = 'x';
    L_x.count = 0;
    struct LetterDictionary L_y;
    L_y.myLetter = 'y';
    L_y.count = 0;
    struct LetterDictionary L_z;
    L_z.myLetter = 'z';
    L_z.count = 0;
    struct LetterDictionary L_A;
    L_A.myLetter = 'A';
    L_A.count = 0;
    struct LetterDictionary L_B;
    L_B.myLetter = 'B';
    L_B.count = 0;
    struct LetterDictionary L_C;
    L_C.myLetter = 'C';
    L_C.count = 0;
    struct LetterDictionary L_D;
    L_D.myLetter = 'D';
    L_D.count = 0;
    struct LetterDictionary L_E;
    L_E.myLetter = 'E';
    L_E.count = 0;
    struct LetterDictionary L_F;
    L_F.myLetter = 'F';
    L_F.count = 0;
    struct LetterDictionary L_G;
    L_G.myLetter = 'G';
    L_G.count = 0;
    struct LetterDictionary L_H;
    L_H.myLetter = 'H';
    L_H.count = 0;
    struct LetterDictionary L_I;
    L_I.myLetter = 'I';
    L_I.count = 0;
    struct LetterDictionary L_J;
    L_J.myLetter = 'J';
    L_J.count = 0;
    struct LetterDictionary L_K;
    L_K.myLetter = 'K';
    L_K.count = 0;
    struct LetterDictionary L_L;
    L_L.myLetter = 'L';
    L_L.count = 0;
    struct LetterDictionary L_M;
    L_M.myLetter = 'M';
    L_M.count = 0;
    struct LetterDictionary L_N;
    L_N.myLetter = 'N';
    L_N.count = 0;
    struct LetterDictionary L_O;
    L_O.myLetter = 'O';
    L_O.count = 0;
    struct LetterDictionary L_P;
    L_P.myLetter = 'P';
    L_P.count = 0;
    struct LetterDictionary L_Q;
    L_Q.myLetter = 'Q';
    L_Q.count = 0;
    struct LetterDictionary L_R;
    L_R.myLetter = 'R';
    L_R.count = 0;
    struct LetterDictionary L_S;
    L_S.myLetter = 'S';
    L_S.count = 0;
    struct LetterDictionary L_T;
    L_T.myLetter = 'T';
    L_T.count = 0;
    struct LetterDictionary L_U;
    L_U.myLetter = 'U';
    L_U.count = 0;
    struct LetterDictionary L_V;
    L_V.myLetter = 'V';
    L_V.count = 0;
    struct LetterDictionary L_W;
    L_W.myLetter = 'W';
    L_W.count = 0;
    struct LetterDictionary L_X;
    L_X.myLetter = 'X';
    L_X.count = 0;
    struct LetterDictionary L_Y;
    L_Y.myLetter = 'Y';
    L_Y.count = 0;
    struct LetterDictionary L_Z;
    L_Z.myLetter = 'Z';
    L_Z.count = 0;
    
    printf("Statistics: \n");
    printf("   Length:     %d\n", strlen(current));
    printf("   Word:       %d\n", NumOfWords(current));
    printf("Frequency:\n");
    CharCheck(L_a, current);
    CharCheck(L_b, current);
    CharCheck(L_c, current);
    CharCheck(L_d, current);
    CharCheck(L_e, current);
    CharCheck(L_f, current);
    CharCheck(L_g, current);
    CharCheck(L_h, current);
    CharCheck(L_i, current);
    CharCheck(L_j, current);
    CharCheck(L_k, current);
    CharCheck(L_l, current);
    CharCheck(L_m, current);
    CharCheck(L_n, current);
    CharCheck(L_o, current);
    CharCheck(L_p, current);
    CharCheck(L_q, current);
    CharCheck(L_r, current);
    CharCheck(L_s, current);
    CharCheck(L_t, current);
    CharCheck(L_u, current);
    CharCheck(L_v, current);
    CharCheck(L_w, current);
    CharCheck(L_x, current);
    CharCheck(L_y, current);
    CharCheck(L_z, current);
    CharCheck(L_A, current);
    CharCheck(L_B, current);
    CharCheck(L_C, current);
    CharCheck(L_D, current);
    CharCheck(L_E, current);
    CharCheck(L_F, current);
    CharCheck(L_G, current);
    CharCheck(L_H, current);
    CharCheck(L_I, current);
    CharCheck(L_J, current);
    CharCheck(L_K, current);
    CharCheck(L_L, current);
    CharCheck(L_M, current);
    CharCheck(L_N, current);
    CharCheck(L_O, current);
    CharCheck(L_P, current);
    CharCheck(L_Q, current);
    CharCheck(L_R, current);
    CharCheck(L_S, current);
    CharCheck(L_T, current);
    CharCheck(L_U, current);
    CharCheck(L_V, current);
    CharCheck(L_W, current);
    CharCheck(L_X, current);
    CharCheck(L_Y, current);
    CharCheck(L_Z, current);    
}

void compressString(const char *current, char *result)
{
    int LastPositionInTemp = 0;
    char temp[100];
    for (int i = 0; i < strlen(current); i++)
    {
        const char *output = strchr(temp, current[i]);
        if (output != NULL)
        {
            //skip
        }
        else if (output == NULL)
        {
            LastPositionInTemp++;
            strncat(temp, &current[i], 1);
        }
    }
    strcpy(result, temp);
    printf("%s\n", result);
}

int IsThereAString(const char *current)     //return 0 if false, return 1 is true
{
    // printf("This is string length: %d", strlen(current));
    if (strlen(current) == 0)
    {
        return 0;
    }
    else if (!(strlen(current) == 0))
    {
        return 1;
    }
    
    return 1;
}