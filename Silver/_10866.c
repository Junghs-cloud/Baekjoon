#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
struct deque* d;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
struct deque
{
	struct node * front;
	struct node * back;
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
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
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

int isEmpty()
{
	if (d->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void printDeque()
{
	struct node* temp = d->front;
	while (temp!=NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

int popFront()
{
	struct node* popNode=d->front;
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
int printSize()
{
	return (d->size);
}

int printFront()
{
	if (d->size == 0)
	{
		return -1;
	}
	else
	{
		return d->front->data;
	}

}

int printBack()
{
	if (d->size == 0)
	{
		return -1;
	}
	else
	{
		return d->back->data;
	}

}
int main()
{
	initialize();
	int N;
	char command[30] = {"\0"};
	char* token;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(command);
		token = strtok(command, " ");
		if (strcmp(token, "push_front") == 0)
		{
			token = strtok(NULL, " ");
			pushFront(atoi(token));
		}
		else if (strcmp(token, "push_back") == 0)
		{
			token = strtok(NULL, " ");
			pushBack(atoi(token));
		}
		else if (strcmp(token, "pop_front") == 0)
		{
			printf("%d\n", popFront());
		}
		else if (strcmp(token, "pop_back") == 0)
		{
			printf("%d\n", popBack());
		}
		else if (strcmp(token, "size") == 0)
		{
			printf("%d\n", printSize());
		}
		else if (strcmp(token, "front") == 0)
		{
			printf("%d\n", printFront());
		}
		else if (strcmp(token, "back") == 0)
		{
			printf("%d\n", printBack());
		}
		else
		{
			printf("%d\n", isEmpty());
		}
	}

	return 0;
}