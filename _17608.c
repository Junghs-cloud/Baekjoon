#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4496)
int array[100000];

int main()
{
	int N;
	int i = 0;
	int max_num;
	int see = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}

	max_num = array[N-1];
	for (int i = N-1; i >=0; i--)
	{
		if (array[i] > max_num)
		{
			max_num = array[i];
			see++;
		}
	}
	printf("%d", see);
	return 0;
}