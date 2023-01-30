#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

struct node
{
	int data;
	struct node* next;
};
struct queue
{
	struct node* front;
	struct node* rear;
	int count;
};
void initQueue(struct queue* q)
{
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
}
int isEmpty(struct queue* q)
{
	if (q->count == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
int printSize(struct queue* q)
{
	return q->count;
}
void push(struct queue* q, int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->next = NULL;
	if (isEmpty(q) == 1)
	{
		q->front = temp;
		q->rear = temp;
		(q->count)++;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
		(q->count)++;
	}

}

int pop(struct queue* q)
{
	if (q->count == 0)
	{
		return -1;
	}
	else
	{
		struct node* fN = q->front;
		int item = q->front->data;
		q->front = q->front->next;
		(q->count)--;
		free(fN);
		return item;
	}

}

int print_front(struct queue* q)
{
	if (q->count == 0)
	{
		return -1;
	}
	else
	{
		return q->front->data;
	}

}
int print_back(struct queue* q)
{
	if (q->count == 0)
	{
		return -1;
	}
	else
	{
		return q->rear->data;
	}

}
int main()
{
	int N;
	scanf("%d", &N);
	char command[100] = { "\0" };
	char* token;
	struct queue Queue;
	initQueue(&Queue);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(command);
		token = strtok(command, " ");
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " ");
			push(&Queue, atoi(token));
		}
		else if (strcmp(token, "pop") == 0)
		{
			printf("%d\n", pop(&Queue));
		}
		else if (strcmp(token, "size") == 0)
		{
			printf("%d\n", printSize(&Queue));
		}
		else if (strcmp(token, "empty") == 0)
		{
			printf("%d\n", isEmpty(&Queue));
		}
		else if (strcmp(token, "front") == 0)
		{
			printf("%d\n", print_front(&Queue));
		}
		else
		{
			printf("%d\n", print_back(&Queue));
		}
	}

	return 0;
}