#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int pos[100][100];

void initArray()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			pos[i][j] = 0;
		}
	}
}
int main()
{
	int N;
	int x, y;
	int finalArea = 0;
	initArray();
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				if (pos[j][k] == 0)
				{
					pos[j][k] = 1;
					finalArea++;
				}
			}
		}
	}
	printf("%d\n", finalArea);
	return 0;
}