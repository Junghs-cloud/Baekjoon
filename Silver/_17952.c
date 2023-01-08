#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int time[1000001];
int point[1000001];
int top=-1;

int main()
{
	int N;
	int homework;
	int T;
	int A;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &homework);
		if (homework == 0)
		{
			if (top == -1)
			{
				continue;
			}
		}
		else
		{
			scanf("%d %d", &A, &T);
			point[++top] = A;
			time[top] = T;
		}
		time[top]--;
		if (time[top] == 0)
		{
			sum += point[top];
			top--;
		}
	}
	printf("%d\n", sum);
	return 0;
}