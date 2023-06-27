#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

char video[65][65];

void divide(int startX, int startY, int length)
{
	int nextLength = length / 2;
	char temp = video[startX][startY];
	int isAllSamePixel = 1;
	for (int i = startX; i < startX + length; i++)
	{
		for (int j = startY; j < startY + length; j++)
		{
			if (video[i][j] != temp)
			{
				isAllSamePixel = 0;
			}
		}
	}
	if (isAllSamePixel == 1 || length == 1)
	{
		printf("%c", temp);
	}
	else if (isAllSamePixel == 0)
	{
		printf("(");
		divide(startX, startY, nextLength);
		divide(startX, startY + nextLength, nextLength);
		divide(startX + nextLength, startY, nextLength);
		divide(startX + nextLength, startY + nextLength, nextLength);
		printf(")");
	}
}

int main()
{
	int N;
	char line[65];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", line);
		for (int j = 0; j < N; j++)
		{
			video[i][j] = line[j];
		}

	}
	divide(0, 0, N);
	return 0;
}