#include <stdio.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

char LRStack[200000];
char SKStack[200000];
int LRtop = 0;
int SKtop = 0;
int sucessCount = 0;
char skillName;

int isAdvancedSkill()
{
	if (skillName == 'L' || skillName == 'S')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFinalSkill()
{
	if (skillName == 'R' || skillName == 'K')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push()
{
	if (skillName == 'L' || skillName=='R')
	{
		LRStack[++LRtop] = skillName;
	}
	else
	{
		SKStack[++SKtop] = skillName;
	}

}

char pop()
{
	if (skillName == 'R')
	{
		return LRStack[LRtop--];
	}
	else
	{
		return SKStack[SKtop--];
	}

}

int isLinked(char first, char second)
{
	if (first == 'R' && second == 'L')
	{
		return 1;
	}
	else if (first == 'K' && second == 'S')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &skillName);
		if (isAdvancedSkill())
		{
			push();
		}
		else if (isFinalSkill())
		{
			push();
			char first = pop();
			char second = pop();
			if (!isLinked(first, second))
			{
				break;
			}
			else
			{
				sucessCount++;
			}

		}
		else
		{
			sucessCount++;
		}

	}

	printf("%d\n", sucessCount);
	return 0;
}