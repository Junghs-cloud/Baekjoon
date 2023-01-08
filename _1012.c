#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int search[50][50];
int array[50][50];
int bug[10000] = {0,0};
int r;
void show(int N, int M);

void find_zero(int i, int j)
{
	search[i][j] = 1;
	
	if (j < 49)
	{
		if (search[i][j + 1] == 0 && array[i][j + 1] == 1)
		{
			find_zero(i, j + 1);
		}
	}
	if (i < 49)
	{
		if (search[i + 1][j] == 0 && array[i + 1][j] == 1)
		{
			find_zero(i + 1, j);
		}
	}

	if (j > 0)
	{
		if (search[i][j - 1] == 0 && array[i][j - 1] == 1)
		{
			find_zero(i, j - 1);
		}
	}
	if (i > 0)
	{
		if (search[i - 1][j] == 0 && array[i - 1][j] == 1)
		{
			find_zero(i - 1, j);
		}
	}


}

void find(int N, int M)
{
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < M; b++)
		{
			if (array[a][b] == 1 && search[a][b]==0)
			{
				find_zero(a, b);
				bug[r]++;
			}

		}
	}
}

int main()
{
	int i = 0;
	int j = 0;
	int M, N, K;
	int T;
	int x, y;
	scanf("%d", &T);
	for (r = 0; r < T; r++)
	{
		scanf("%d %d %d", &M, &N, &K);
		bug[r] = 0;
		for (i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (i < N && j < M)
				{
					array[i][j] = 0;
				}
				else
				{
					array[i][j] = 2;
				}
				search[i][j] = 0;
			}
		}
		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &x, &y);
			array[y][x] = 1;
		}
		find(N, M);

	}

	for (int i = 0; i < T; i++)
	{
		printf("%d\n", bug[i]);

	}

	return 0;
}