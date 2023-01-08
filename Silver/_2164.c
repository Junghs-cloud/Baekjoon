#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#define MAX 500001
int front=-1;
int rear=-1;
int queue[MAX] = {0,0};

void push(int item)
{
	rear = (rear + 1) % MAX;
	queue[rear] = item;
}
int pop()
{
	if (front == rear)
	{
		return -999;
	}
	front = (front + 1) % MAX;
	return queue[front];

}
void print()
{
	int i=front;
	while (i != rear)
	{
		i = (i + 1) % MAX;
		printf("%d\n", queue[i]);
	}

}
int main()
{
	int N;
	int num;
	int card;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		push(i + 1);
	}
	card = N;
	while (card!=1)
	{
		pop();
		num=pop();
		if (num == -999)
		{
			break;
		}
		else
		{
			push(num);
		}
		card--;
	}
	print();


	return 0;
}