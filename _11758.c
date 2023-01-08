#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int main()
{
	int x1, y1, x2, y2, x3, y3;
	int a, b;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	a = x1 * y2 + x2 * y3 + x3 * y1;
	b = x2 * y1 + x3 * y2 + x1 * y3;
	if (a == b)
	{
		printf("0\n");
	}
	else if (a > b)
	{
		printf("1\n");
	}
	else
	{
		printf("-1\n");
	}
	return 0;
}