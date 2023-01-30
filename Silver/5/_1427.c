#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int intArray[12];
int length = 0;

void initArray()
{
	for (int i = 0; i < 12; i++)
	{
		intArray[i] = -1;
	}

}

void sort()
{
	int temp, i, j;
	int max = 0;
	for (i = 0; i < length; i++)
	{
		max = i;
		for (j = i + 1; j < length; j++)
		{
			if (intArray[max] < intArray[j])
			{
				max = j;
			}
		}
		temp = intArray[max];
		intArray[max] = intArray[i];
		intArray[i] = temp;
	}
}

void printArray()
{
	for (int i = 0; i < length; i++)
	{
		printf("%d", intArray[i]);
	}
	printf("\n");
}

int main()
{

	char N[12];

	initArray();
	scanf("%s", &N);
	for (int i = 0; N[i] != '\0'; i++)
	{
		intArray[i] = N[i] - 48;
		length++;
	}
	sort();
	printArray();
	return 0;
}