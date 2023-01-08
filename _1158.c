#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4496)
int array[5000] = {0,0};
int top = 0;
start = -1;


int pop(int N, int K)
{
	int i = 0;
	int temp;
	int num=0;
	while (1)
	{
		start = start + 1;
		if (start > N-1)
		{
			start = start - N;
		}
		if (array[start] == 0)
		{

		}
		else
		{
			num++;
		}

		if (num == K)
		{
			break;
		}
	}

	temp = array[start];
	array[start] = 0;
	return temp;

}
int main()
{
	int N;
	int K;
	int i = 0;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		array[i] = i + 1;
	}
	printf("<");
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			printf("%d, ", pop(N, K));
		}
		else
		{
			printf("%d", pop(N, K));
		}
		
	}
	printf(">");
	return 0;
}