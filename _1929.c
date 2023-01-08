#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

int array[1000001] = {0,0};
int main()
{
	int M, N=0;
	scanf("%d %d", &M, &N);
	for (int i = 0; i <= N; i++)
	{
		array[i] = i;
	}
	array[1] = 0;
	for (int i = 2; i <= N; i++)
	{
		if (array[i] != 0)
		{
			for (int j = i*2; j <= N; j += i)
			{
				array[j] = 0;
			}
		}
	}
	for (int i = M; i <= N; i++)
	{
		if (array[i] != 0)
		{
			printf("%d\n", array[i]);
		}

	}

	return 0;
}