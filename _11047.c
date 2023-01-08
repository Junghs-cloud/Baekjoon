#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int A[10];
int main()
{
	int n;
	int money;
	int dan;
	int count = 0;
	scanf("%d %d", &n, &money);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dan);
		A[i] = dan;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (money >= A[i])
		{
			int d = money / A[i];
			count += d;
			money = money - (d * A[i]);
		}
	}
	printf("%d\n", count);

	return 0;
}