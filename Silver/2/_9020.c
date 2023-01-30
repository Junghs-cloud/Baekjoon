#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int array[10001];
int main()
{
	int T=0;
	int N=0;
	int half=0;
	int a=0;
	int b=0;
	scanf("%d", &T);
	for (int k = 0; k < T; k++)
	{
		scanf("%d", &N);
		for (int i = 0; i <= 10000; i++)
		{
			array[i] = i;
		}
		array[1] = 0;
		for (int i = 2; i <= 10000; i++)
		{
			if (array[i] != 0)
			{
				for (int j = 2 * i; j <= 10000; j += i)
				{
					array[j] = 0;
				}
			}
		}

		a = N / 2;
		b = a;
		while (1)
		{
			if ((array[a] != 0) && (array[b] != 0))
			{
				break;
			}
			a--;
			b++;
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}