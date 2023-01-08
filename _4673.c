#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int isSelfNum[10001];

void initArray()
{
	for (int i = 0; i <= 10000; i++)
	{
		isSelfNum[i] = 1;
	}
}


void makeSequence(int i)
{
	int nextSqeuence = i;
	char string[7] = {"\0"};
	sprintf(string , "%d", i);
	for (int j = 0; string[j] != '\0'; j++)
	{

		nextSqeuence += string[j]-48;
	}
	if (i <= 10000)
	{
		isSelfNum[nextSqeuence] = 0;
		makeSequence(nextSqeuence);
	}
	else
	{
		return;
	}

}

void printSelfNum()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (isSelfNum[i] == 1)
		{
			printf("%d\n", i);
		}
	}
}

void solveProblem()
{
	for (int i = 1; i <= 10000; i++)
	{
		if (isSelfNum[i] == 1)
		{
			makeSequence(i);
		}
	}
}

int main()
{
	initArray();
	solveProblem();
	printSelfNum();
	return 0;
}