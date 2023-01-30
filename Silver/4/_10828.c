#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int stack[10000];
int top = -1;

void push(int item)
{
	stack[++top] = item;
}
int pop()
{
	if (top < 0)
	{
		return -1;
	}
	else
	{
		return stack[top--];
	}

}
int size()
{
	return top+1;
}

int empty()
{
	if (top < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int print_top()
{
	if (top < 0)
	{
		return -1;
	}
	else
	{
		return stack[top];
	}
}

int main()
{
	int N;
	char command[50] = {"\0"};
	char* token;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(command);
		token = strtok(command, " ");
		if (strcmp(token, "push")==0)
		{
			token = strtok(NULL, " ");
			push(atoi(token));
		}
		else if (strcmp(token, "pop") == 0)
		{
			printf("%d\n",pop());
		}
		else if (strcmp(token, "top") == 0)
		{
			printf("%d\n", print_top());
		}
		else if (strcmp(token, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(token,"empty") == 0)
		{
			printf("%d\n", empty());
		}
	}
	return 0;
}