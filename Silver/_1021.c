#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int count = 0;
struct deque* d;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct deque
{
	struct node* front;
	struct node* back;
	int size;
};

void initialize()
{
	d = (struct deque*)malloc(sizeof(struct deque));
	d->front = NULL;
	d->back = NULL;
	d->size = 0;
}
void pushFront(int item)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = item;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (d->size == 0)
	{
		d->front = newNode;
		d->back = newNode;
	}
	else
	{
		d->front->prev = newNode;
		newNode->next = d->front;
		d->front = newNode;
	}
	(d->size)++;
}
void pushBack(int item)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = item;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (d->size == 0)
	{
		d->front = newNode;
		d->back = newNode;
	}
	else
	{
		d->back->next = newNode;
		newNode->prev = d->back;
		d->back = newNode;
	}
	(d->size)++;
}

int popFront()
{
	struct node* popNode = d->front;
	if (d->size == 0)
	{
		return -1;
	}
	else if (d->size == 1)
	{
		d->front = NULL;
		d->back = NULL;
		d->size = 0;
		return popNode->data;
	}
	else
	{
		d->front = d->front->next;
		d->front->prev = NULL;
		d->size--;
		return popNode->data;
	}

}

int popBack()
{
	struct node* popNode = d->back;
	if (d->size == 0)
	{
		return -1;
	}
	else if (d->size == 1)
	{
		d->front = NULL;
		d->back = NULL;
		d->size--;
		return popNode->data;
	}
	else
	{
		d->back = d->back->prev;
		d->back->next = NULL;
		d->size--;
		return popNode->data;
	}

}


int searchOrder(int num)
{
	int i = 1;
	struct node* temp = d->front;
	while (temp->data != num)
	{
		temp = temp->next;
		i++;
	}
	return i;
}
int main()
{
	initialize();
	int N=0;
	int M=0;
	int num=0;
	int temp=0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		pushBack(i+1);
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num);
		temp = searchOrder(num);
		if (temp-1<=(d->size)-temp+1)
		{
			for (int j = 0; j < temp-1 ;j++) //왼쪽으로 이동.
			{
				pushBack(popFront());
				count++;
			}
		}
		else
		{

			for (int j = 0; j <= (d->size)-temp;j++) //오른쪽으로 이동
			{
				pushFront(popBack());
				count++;
			}
		}
		popFront();
	}
	printf("%d\n", count);
	return 0;
}