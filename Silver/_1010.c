#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
long long int combination[30][30];

void dp(int n, int m)
{
	combination[m][n] = combination[m - 1][n - 1] + combination[m - 1][n];
}

int main()
{
	for (int i = 0; i < 30; i++)
	{
		combination[i][0] = 1;
	}

	for (int i = 1; i < 30; i++)
	{
		for (int j = 1; j < 30; j++)
		{
			if (i <= j)
			{
				dp(i, j);
			}
		}
	}
	int T;
	int M, N;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);
		printf("%lld\n", combination[M][N]);
		
	}
	return 0;
}