#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int main()
{
	int N;
	int num;
	scanf("%d", &N);
	num = N;
	for (int i = 2; i <= sqrt(N); i++)
	{
		while (num % i == 0)
		{
			num = num / i;
			printf("%d\n", i);
		}
	}
	
	if (num != 1)
	{
		printf("%d\n", num);
	}

	return 0;
}