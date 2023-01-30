#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int N[5001];

int min(int x, int y)
{
	if (x < y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

void initArray()
{
	for (int i = 0; i < 5001; i++)
	{
		N[i] = -1;
	}
}

void multiple(int n)
{
	for (int i = 2 * n; i < 5001; i += n)
	{
		N[i] = N[i - n] + 1;
	}
}

void dp()
{
	for (int i = 6; i < 5001; i++)
	{
		if (N[i - 3] != -1 && N[i-5] != -1)
		{
			N[i] = min(N[i - 3], N[i - 5]) + 1;
		}
	}
}

int main()
{
	int n;
	initArray();
	N[3] = 1;
	N[5] = 1;
	multiple(3);
	multiple(5);
	dp();
	scanf("%d", &n);
	printf("%d\n", N[n]);
	return 0;
}