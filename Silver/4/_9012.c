#include <stdio.h>
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
char input[51];
int top = -1;

void push(char item)
{
	input[++top] = item;
}

char pop()
{
	if (top <= -1)
	{
		return 'e';
	}
	else
	{
		return input[top--];
	}

}
int isempty()
{
	if (top >= 0) 
	{
		return 0;
	}
	else //비어있음.
	{
		return 1;
	}
}


int main()
{
	int flag = 0;
	char temp;
	int N;
	char ps[51] = {'\0'};
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(ps);
		for (int j = 0; ps[j] != '\0'; j++)
		{
			if (ps[j] == '(')
			{
				push('(');
			}
			else
			{
				temp=pop();
				if (temp=='e')
				{
					flag = 1;
				}

			}
		}
		if (flag == 0)
		{
			if (isempty() == 1)
			{
				flag = 0;
			}
			else
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
		while (1)
		{
			char tem = pop();
			if (tem == 'e')
			{
				break;
			}
		}
		top = -1;
		flag = 0;
	}

	return 0;
}