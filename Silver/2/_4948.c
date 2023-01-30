#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
short num[300000];
int main()
{
	int Num=0;
	int N;
	while (1)
	{
		Num = 0;
		scanf("%d", &N);
		if (N == 0)
		{
			break;
		}
		for (int i = 0; i <= 2 * N; i++)
		{
			num[i] = 1;
		}
		num[0] = 0;
		num[1] = 0;
		for (int i = 2; i <= 2 * N; i++)
		{
			if (num[i] == 1)
			{
				for (int j = 2 * i; j <= 2 * N; j += i)
				{
					num[j] = 0;
				}
			}
		}
		for (int i = N+1; i <= 2 * N; i++)
		{
			if (num[i] == 1)
			{
				Num++;
			}

		}
		printf("%d\n", Num);
	}
	return 0;
}