#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4496)
#pragma warning(disable: 6031)
int guitar[6][300000] = {0,0};
int top[6] = {0,0,0,0,0,0};
int finger = 0;
int check(int line)
{
	if (top[line] == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void pop(int line, int item)
{
	while (1)
	{
		if (guitar[line][top[line]-1]>item)
		{
			guitar[line][--top[line]];
			finger++;
		}
		else if (guitar[line][top[line] - 1] == item)
		{
			break;
		}
		else
		{
			guitar[line][top[line]++]=item;
			finger++;
			break;
		}

	}

}
void push(int line, int item)
{
	if (check(line) == 1)
	{
		guitar[line][top[line]++] = item;
		finger++;
	}
	else if (guitar[line][top[line]-1]<item)
	{
		guitar[line][top[line]++] = item;
		finger++;
	}
	else
	{
		pop(line, item);
	}
}

int main()
{
	int N, P;
	int line, fret;
	scanf("%d %d", &N, &P);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &line, &fret);
		push(line - 1, fret);
	}

	printf("%d\n", finger);
	return 0;
}