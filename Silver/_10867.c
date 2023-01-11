#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int number[100000];
int length = 0;

int findNumber(int n)
{
	for (int i = 0; i < length; i++)
	{
		if (number[i] == n)
		{
			return 1;
		}
	}
	return 0;
}

void merge(int left, int right)
{
	int mergedArray[3000] = {0,0};
	int tempPos = left;
	int middle = (left + right) / 2 + 1;
	int leftEnd = middle - 1;
	int arrayLength = right - left + 1;

	while ((left <= leftEnd) && (middle <= right))
	{
		if (number[left] <= number[middle])
		{
			mergedArray[tempPos++] = number[left++];
		}
		else
		{
			mergedArray[tempPos++] = number[middle++];
		}
	}
	while (left <= leftEnd)
	{
		mergedArray[tempPos++] = number[left++];
	}
	while (middle <= right)
	{
		mergedArray[tempPos++] = number[middle++];
	}
	for (int i = 0; i < arrayLength; i++)
	{
		number[right] = mergedArray[right];
		right--;
	}
}

void mergeSort(int left, int right)
{
	int middle;
	if (left < right)
	{
		middle = (left + right) / 2;
		mergeSort(left, middle);
		mergeSort(middle + 1, right);
		merge(left, right);
	}
}

void printArray()
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", number[i]);
	}
}

int main()
{
	int N;
	int currentNum;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &currentNum);
		if (findNumber(currentNum) == 0)
		{
			number[length++] = currentNum;
		}
	}
	if (length == 1)
	{
		printf("%d", number[0]);
	}
	else
	{
		mergeSort(0, length - 1);
		printArray();
	}

	return 0;
}