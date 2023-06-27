#include <stdio.h>
#define _CRT_SECRUE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int score[100];
int count = 0;
int main()
{
	int N=0;
	int levelScore=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &levelScore);
		score[i] = levelScore;
	}
	for (int i = N - 2; i >= 0; i--)
	{
		while (score[i] >= score[i + 1])
		{
			count++;
			score[i]--;
		}
	}
	printf("%d\n", count);
	return 0;
}