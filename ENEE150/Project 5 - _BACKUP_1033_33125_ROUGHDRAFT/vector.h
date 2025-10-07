/****************************************************************
Dynamic Vector Operations Header File "vector.h"
Include required function prototypes. You can define additional
function as needed.
****************************************************************/
/* Create a new vector. Read the length of the vector followed by value
of each element of the vector. If length is invalid, or elements are
invalid, display the informative error message and return to the main
program. Integer k (0, 1, 2, or 3) corresponds to vector A, B, C, D */
void vector_new(double **p, int *n, int k);
/* Display a vector on the screen. Read the name of the vector from
standard input.
For example: prn D
*/
void vector_prn(double **p, int *n);
/* Calculate and display the sum of all the elements of the vector.
Read the name of the vector from standard input.
For example: sum A
*/
void vector_sum (double **p, int *n);
/* Calculate and display the rms value of the vector. Read the name of
the vector from standard input.
For example: rms B
*/
void vector_rms (double **p, int *n);
/* Calculate and display the nagation of the vector. Read the name of
the vector from standard input.
For example: neg C
*/
void vector_neg (double **p, int *n);
/* Add two vectors. Read names of two vectors from standard input.
For example: add A B
*/
void vector_add (double **p, int *n);
/* Subtract two vectors. Read names of two vectors from standard input
For example: sub A B
*/
void vector_sub (double **p, int *n);

//To transform char to int and declare a vector.
int GetVectorIndexByLetter(char *letter);

void displayMenuAndGetUserInput();

int isNumber(const char *str);

int isSizeAnInteger(const char *str);


extern char tokensOfUserInput[100][100]; // Declare the variable as external