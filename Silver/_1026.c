#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int A[50];
int tempA[50];
int B[50];
int tempB[50];
int main()
{
	int N;
	int num;
	int arrayNum=0;
	int arrayNumB=0;
	scanf("%d", &N);
	int min;
	int max;
	int sum = 0;
	for (int j = 0; j < N; j++)
	{
		scanf("%d", &num);
		A[j] = num;
	}
	for (int j = 0; j < N; j++)
	{
		scanf("%d", &num);
		tempA[j] = 0;
		tempB[j] = 0;
		B[j] = num;
	}

	for (int k = 0; k < N; k++)
	{
		min = 100;
		max = 0;
		for (int i = 0; i < N; i++)
		{
			if (min >= A[i] && tempA[i] == 0)
			{
				min = A[i];
				arrayNum = i;
			}
			if (max <= B[i] && tempB[i] == 0)
			{
				max = B[i];
				arrayNumB = i;
			}
		}
		tempA[arrayNum] = 1;
		tempB[arrayNumB] = 1;
		sum += (A[arrayNum] * B[arrayNumB]);
	}
	printf("%d\n", sum);
	return 0;
}