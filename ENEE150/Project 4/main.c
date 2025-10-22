#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringManipulation.h"

void main()
{
   char UserInput[100];
   system("cls");
   char str[100][100] = {0};        //str[100] is a character array of 100 elements; str[100][100] is an array of 100 character arrays (str[100] times 100).
   char UserCommands[MAX_HISTORY_SIZE][MAX_CMD_LEN];
   int n;
   int IssThereAString;
    
   n = 0;
   while (!(UserInput == "quit"))
   {
      printf("cmd> ");
      gets(UserInput);

      if (strcmp(UserInput, "new") == 0)
      {
         char *p1 = "new";
         strcpy(UserCommands[n], p1);
         getString(str[0]);
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "list") == 0)
      {
         IssThereAString = IsThereAString(str[0]);
         if (0 == IssThereAString)
         {
            continue;
         }
         char *p2 = "list";
         strcpy(UserCommands[n], p2);
         list(str[0]);
         n++;
         printf("\n");
      }
      else if(strcmp(UserInput, "find") == 0)
      {
         IssThereAString = IsThereAString(str[0]);
         if (0 == IssThereAString)
         {
            continue;
         }   
         
         char *p3 = "find";
         strcpy(UserCommands[n], p3);
         findString(str[0]);
         printf("\n");
         n++;
      }
      else if(strcmp(UserInput, "toggle") == 0)
      {
         IssThereAString = IsThereAString(str[0]);
         if (0 == IssThereAString)
         {
            continue;
         }
         char *p4 = "toggle";
         strcpy(UserCommands[n], p4);
         toggleString(str[0],str[1]);
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "compress") == 0)
      {
         IssThereAString = IsThereAString(str[0]);
         if (0 == IssThereAString)
         {
            continue;
         }
         char *p5 = "compress";
         strcpy(UserCommands[n], p5);
         compressString(str[0], str[1]);
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "reverse") == 0)
      {
         IssThereAString = IsThereAString(str[0]);
         if (0 == IssThereAString)
         {
            continue;
         }
         char *p6 = "reverse";
         strcpy(UserCommands[n], p6);
         reverseString(str[0], str[1]);
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "replace") == 0)
      {
         IssThereAString = IsThereAString(str[0]);
         if (0 == IssThereAString)
         {
            continue;
         }
         char *p7 = "replace";
         strcpy(UserCommands[n], p7);
         replaceString(str[0], str[1]);
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "stat") == 0)
      {
         char *p8 = "stat";
         strcpy(UserCommands[n], p8);
         printStatistics(str[0]);
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "help") == 0)
      {
         char *p9 = "help";
         strcpy(UserCommands[n], p9);
         printHelp();
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "hist") == 0)
      {
         char *p10 = "hist";
         strcpy(UserCommands[n], p10);
         printHistory(UserCommands, n);
         n++;
         printf("\n");
      }
      else if (strcmp(UserInput, "quit") == 0)
      {
         printf("The code has quit.");
         exit(0);
      }
   }
   
   
   printf("\n");
   // printHelp();
   list(str[0]);
   // findString(str);

}