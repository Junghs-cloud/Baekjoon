#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int queue[900];
int doc_num[900];
int front = 0;
int rear = 0;
int count = 0;
void push(int priority, int docNum)
{
	queue[rear] = priority;
	doc_num[rear++] = docNum;
}

void pop(int num)
{
	int flag = 0;
	for (int i = front; i < rear; i++)
	{
		if (queue[front] < queue[i])
		{
			push(queue[front], doc_num[front]);
			front++;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		count++;
		if (doc_num[front++] == num)
		{
			printf("%d\n", count);
		}
	}
}
int main()
{
	int T;
	int doc = 0;
	int num = 0;
	int prior;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		front = 0;
		rear = 0;
		count = 0;
		scanf("%d %d", &doc, &num);

		for (int j = 0; j < doc; j++)
		{
			scanf("%d", &prior);
			push(prior, j);
		}
		while (1)
		{
			pop(num);
			if (count == doc)
			{
				break;
			}
		}
		
	}



	return 0;
}