#define MAX_HISTORY_SIZE 10 /*the maximum size of the history*/
#define MAX_STR_LEN 100 /*the maximum size of strings*/
#define MAX_CMD_LEN 10 /*the maximum size of a command*/
//for the stat feature.
struct LetterDictionary
{
    char myLetter;
    int count;
};

/* Print a listing of the different commands */
void printHelp(void);
/* Read a string from the keyboard */
void getString(char *current);
/* Toggle the case of the string */
void toggleString(const char *current, char *result);
/* Compress the string */
void compressString(const char *current, char *result);
/* Reverse the string word by word*/
void reverseString (const char *current, char *result);
/* Replace the current string with the last result */
void replaceString (char *current, char *result);
/* User inputs a character and prints and number of times it appears
in the current string */
void findString (const char *current);
/* Print the statistics of the current string */
void printStatistics (const char *current);
/* Add a command to the history table if command is not empty. If the
history table is full, discard the oldest command. Function takes
three arguments: history table, the command to be added into the
table, and the current history table size. The function returns the
updated history size. */
int updateHistory (char history[MAX_HISTORY_SIZE][MAX_CMD_LEN], char
command[], int historySize);
/* Print a history of the commands */
void printHistory(char history[MAX_HISTORY_SIZE][MAX_CMD_LEN], int
historySize);

//Prints currrent string to the screen.
void list(char *current);
//Also for the stat function.
void DisplayStats(struct LetterDictionary a);
//For the stat option.
void CharCheck(struct LetterDictionary CurrentLetter, const char *current);
//for error checking
int IsThereAString(const char *current);     //return 0 if false, return 1 is true



