#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
long int array[1000000];
long int GCD(long int a, long int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);
	}
}

int main()
{
	long int temp=0;
	long int R;
	long int G;
	scanf("%ld %ld", &R, &G);
	long int big = GCD(R, G);
	for (long int i = 1; i * i<= big; i++)
	{
		if (i* i == big)
		{
			printf("%ld %ld %ld\n", i, R / i, G / i);
		}
		else if (big % i == 0)
		{
			printf("%ld %ld %ld\n", i, R / i, G / i);
			array[temp++] = big/i;
		}
	}
	temp--;
	for (temp; temp >= 0; temp--)
	{
		printf("%ld %ld %ld\n", array[temp], R / array[temp], G / array[temp]);
	}


	return 0;
}