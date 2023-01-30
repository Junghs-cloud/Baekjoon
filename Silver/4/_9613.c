#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int nums[100];
long long GCD(long long x, long long y)
{
	if (y == 0)
	{
		return x;
	}
	else
	{
		return GCD(y, x % y);
	}

}

int main()
{
	int t;
	int N;
	int num;
	int i, j, k, l;
	long long sum = 0;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		sum = 0;
		scanf("%d", &N);
		for (j = 0; j < N; j++)
		{
			scanf("%d", &num);
			nums[j] = num;
		}

		for (k = 0; k < j; k++)
		{
			for (l = k + 1; l < j; l++)
			{
				sum+= GCD((long long)nums[k], (long long)nums[l]);
			}
		}
		printf("%lld\n", sum);
	}


	return 0;
}