#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
long long int t[36];

void initArray()
{
	for (int i = 0; i < 36; i++)
	{
		t[i] = 0;
	}
}

int main()
{
	int n;
	initArray();
	t[0] = 1;
	for (int i = 1; i < 36; i++)
	{
		for (int j = 0; j < i; j++)
		{
			t[i] += t[j] * t[i - j - 1];
		}

	}
	scanf("%d", &n);
	printf("%lld\n", t[n]);
	return 0;
}