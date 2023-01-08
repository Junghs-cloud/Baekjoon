#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)
#pragma warning (disable: 6031)

int main()
{
	int array[100];
	int num=0;
	int gap, result=0;
	int N;
	int flag = 1;
	scanf("%d", &N);

	for (int i = 2; i < 120; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			array[num++] = i;
		}
		flag = 1;
	}
	for (int i = 0; i < 99; i++)
	{
		gap = array[i] * array[i + 1];
		if (gap > N)
		{
			result = array[i] * array[i + 1];
			break;
		}
	}
	printf("%d\n", result);
	return 0;
}