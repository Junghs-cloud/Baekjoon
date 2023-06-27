#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
char first[27];
char AQ[1000][27];
char answer[26];
int main()
{
	int N;
	char want[27];
	char ladder[27] = {"\0"};
	char temp;
	int garo;
	int check = 0;
	int r=0;
	int q = 0;
	int flag = 0;
	scanf("%d", &N);
	scanf("%d", &garo);
	for (int i = 0; i < N; i++)
	{
		first[i] = 65 + i;
	}
	scanf("%s", &want);
		for (int j = 0; j < garo; j++)
		{
			scanf("%s", &ladder);
			if (ladder[0] == '?')
			{
				check = 1;
			}
			else
			{
				if (check == 0)
				{

					for (int k = 0; ladder[k] != '\0'; k++)
					{
						if (ladder[k] == '-')
						{
							temp = first[k];
							first[k] = first[k + 1];
							first[k + 1] = temp;
						}
						else
						{
							continue;
						}
					}
				}
				else
				{
					for (int a = 0; a < N; a++)
					{
						AQ[r][a] = ladder[a];
					}
					r++;

				}
			}
		}
		
	
	for (int i = r-1; i >= 0; i--)
	{
		for (int k = 0; AQ[i][k] != '\0'; k++)
		{
			if (AQ[i][k] ==  '-')
			{
				temp = want[k];
				want[k] = want[k + 1];
				want[k+1] =temp;
			}
			else
			{
				continue;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i == N - 1)
		{
			break;
		}
		if (first[i] == want[i])
		{
			answer[q] = '*';
		}
		else if (first[i] == want[i + 1])
		{
			answer[q] = '-';
			temp = first[i];
			first[i] = first[i + 1];
			first[i + 1] = temp;
		}
		else
		{
			for (int j = 0; j < N - 1; j++)
			{
				printf("x");
			}
			printf("\n");
			flag = 1;
			break;
		}
		q++;
	}
	if (flag == 0)
	{
		printf("%s\n", answer);
	}

	return 0;
}