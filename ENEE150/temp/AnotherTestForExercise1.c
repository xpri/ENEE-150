//strcpy(s1.firstName, "Paul");
//strcpy(s1.lastName, "Deitel");
#include <stdio.h>
#include <stdlib.h>

printf("%c.", s1.firstName[0]);
printf("%c.", s1.lastName[0]);

studentType students[40];

for(int i = 0; i < 40; i++)
{
printf("%s %s\n", students[i].firstName, students[i].lastName);
}

struct inventory
{
	char partName[40];
	int partNumber;
	float price;
	int stock;
	int reorder;
}

struct address
{
	char stressAddress[25];
	char city[20];
	char state[3];
	char zipCode[6];
}
// address homeAddress;

struct student
{
	char firstName[15];
	char lastName[15];
	address student;
}