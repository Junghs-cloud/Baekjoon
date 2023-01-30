#include <stdio.h>
#define _CRT_SECURE_NO_WANRNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int final[20] = {0,0};
int finalNum = 0;
struct photo
{
	int ID;
	int recommendCount;
	int isEmpty;
	int old;
};
struct photo p[20];
void init(int N)
{
	for (int i = 0; i < N; i++)
	{
		p[i].isEmpty = 1;
		p[i].ID = 0;
		p[i].recommendCount = 0;
		p[i].old = 0;
	}

}
void search(int N, int reco, int k)
{
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].isEmpty == 1)
		{
			p[i].ID = reco;
			p[i].recommendCount++;
			p[i].isEmpty = 0;
			p[i].old = k;
			flag = 1;
			break;
		}
		else
		{
			if (p[i].ID == reco)
			{
				p[i].recommendCount++;
				flag = 1;
				break;
			}

		}
	}
	if (flag == 0)
	{
		int min=p[0].recommendCount;
		int minNum = 0;
		for (int i = 0; i < N; i++)
		{
			if (min > p[i].recommendCount)
			{
				min = p[i].recommendCount;
				minNum = i;
			}
			if (min == p[i].recommendCount)
			{
				if (p[minNum].old > p[i].old)
				{
					min = p[i].recommendCount;
					minNum = i;
				}
			}
		}
		p[minNum].ID = reco;
		p[minNum].recommendCount = 1;
		p[minNum].old = k;
	}
}

void print(int N)
{
	for (int i = 0; i < N; i++)
	{
		if (p[i].ID != 0)
		{
			final[finalNum++] = p[i].ID;
		}

	}
}

void sort()
{
	for (int i = 0; i < finalNum; i++)
	{
		int min = i;
		int temp=-999;
		for (int j = i; j < finalNum; j++)
		{
			if (final[min] > final[j])
			{
				min=j;
			}
		}
		temp=final[i];
		final[i] = final[min];
		final[min] = temp;
	}
}
void printSort()
{
	for (int i = 0; i < finalNum; i++)
	{
		if (i != finalNum - 1)
		{
			printf("%d ", final[i]);
		}
		else
		{
			printf("%d\n", final[i]);
		}
	}
}
int main()
{

	int N;
	int num;
	int recommend;
	scanf("%d", &N);
	scanf("%d", &num);
	init(N);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &recommend);
		search(N, recommend, i);
	}
	print(N);
	sort();
	printSort();
	return 0;
}