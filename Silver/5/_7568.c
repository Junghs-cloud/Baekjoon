#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int num[50];
int w[50];
int h[50];
int main()
{
	int ran=0;
	int N;
	int x, y;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		w[i] = x;
		h[i] = y;
	}
	for (int i = 0; i < N; i++)
	{
		ran = 1;
		for (int j = 0; j < N; j++)
		{
			if (w[i] < w[j] && h[i] < h[j])
			{
				ran++;
			}
		}
		num[i] = ran;
	}
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			printf("%d ", num[i]);
		}
		else
		{
			printf("%d\n", num[i]);
		}
	}

	return 0;
}