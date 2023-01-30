#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int stack[100000];
int top = -1;
int sum = 0;
void push(int num)
{
	stack[++top] = num;
}

void pop()
{
	stack[--top];
}

void print()
{
	for (int i = 0; i <= top; i++)
	{
		sum += stack[i];
	}
}
int main()
{
	int N;
	int K;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &K);
		if (K != 0)
		{
			push(K);
		}
		else
		{
			pop();
		}

	}
	print();
	printf("%d\n", sum);
	return 0;
}