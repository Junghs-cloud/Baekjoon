#include <stdio.h>
int apart[15][15];
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

void initArray()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			apart[i][j] = 0;
		}

	}
}

void fillZeroFloor()
{
	for (int j = 0; j < 15; j++)
	{
		apart[0][j] = j;
	}
}

int plus(int i, int j)
{
	int member = 0;
	for (int k = 0; k <= j; k++)
	{
		member += apart[i][k];
	}
	return member;
}

void dp()
{
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			apart[i][j] = plus(i - 1, j);
		}

	}
}
int main()
{
	int T, k, n;
	initArray();
	fillZeroFloor();
	dp();
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);
		printf("%d\n", apart[k][n]);
	}
	return 0;
}