#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int normal[100][100];
int rg[100][100];
int search[100][100];
int normalCount = 0;
int rgbCount = 0;
void search1(int i, int j, int color)
{
	search[i][j] = 1;
	if (j < 99)
	{
		if (normal[i][j + 1] == color && search[i][j + 1] == 0)
		{
			search1(i, j + 1, color);
		}
	}
	if (j > 0)
	{
		if (normal[i][j - 1] == color && search[i][j - 1] == 0)
		{
			search1(i, j - 1, color);
		}
	}
	if (i < 99)
	{
		if (normal[i + 1][j] == color && search[i + 1][j] == 0)
		{
			search1(i + 1, j, color);
		}
	}
	if (i > 0)
	{
		if (normal[i - 1][j] == color && search[i - 1][j] == 0)
		{
			search1(i - 1, j, color);
		}
	}

}
void search2(int i, int j, int color)
{
	search[i][j] = 1;
	if (j < 99)
	{
		if (rg[i][j + 1] == color && search[i][j + 1] == 0)
		{
			search2(i, j + 1, color);
		}
	}
	if (j > 0)
	{
		if (rg[i][j - 1] == color && search[i][j - 1] == 0)
		{
			search2(i, j - 1, color);
		}
	}
	if (i < 99)
	{
		if (rg[i + 1][j] == color && search[i + 1][j] == 0)
		{
			search2(i + 1, j, color);
		}
	}
	if (i > 0)
	{
		if (rg[i - 1][j] == color && search[i - 1][j] == 0)
		{
			search2(i - 1, j, color);
		}
	}

}
int main()
{
	int N;
	char pixel[100] = {'\0'};
	scanf("%d", &N);
	
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			normal[i][j] = 0;
		}
	}
	
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(pixel);
		for (int j = 0; j < N; j++)
		{
			search[i][j] = 0;
			if (pixel[j] == 'R')
			{
				normal[i][j] = 1;
				rg[i][j] = 1;
			}
			else if (pixel[j] == 'G')
			{
				normal[i][j] = 2;
				rg[i][j] = 1;
			}
			else
			{
				normal[i][j] = 3;
				rg[i][j] = 2;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (search[i][j] == 0 && normal[i][j]==1)
			{
				search1(i, j, 1);
				normalCount++;
			}
			else if (search[i][j] == 0 && normal[i][j] == 2)
			{
				search1(i, j, 2);
				normalCount++;
			}
			else if (search[i][j] == 0 && normal[i][j] == 3)
			{
				search1(i, j, 3);
				normalCount++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			search[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (search[i][j] == 0 && rg[i][j] == 1)
			{
				search2(i, j, 1);
				rgbCount++;
			}
			else if (search[i][j] == 0 && rg[i][j] == 2)
			{
				search2(i, j, 2);
				rgbCount++;
			}
		}
	}
	printf("%d %d\n", normalCount, rgbCount);
	return 0;
}