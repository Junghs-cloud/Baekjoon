#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
int switchs[101];
int main()
{
	int N;
	int Switch;
	int changeNum;
	int gender;
	int receiveNum;
	int k;
	int count = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &Switch);
		switchs[i] = Switch;
	}
	scanf("%d", &changeNum);
	for (int i = 0; i < changeNum; i++)
	{
		scanf("%d %d", &gender, &receiveNum);
		if (gender == 1)
		{
			for (int j = receiveNum; j <= N; j += receiveNum)
			{
				if (switchs[j] == 0)
				{
					switchs[j] = 1;
				}
				else
				{
					switchs[j] = 0;
				}
			}
		}
		else
		{
			for (k = 1; receiveNum+k<=N; k++)
			{
				if (receiveNum - k == 0)
				{
					break;
				}
				if (switchs[receiveNum - k] == switchs[receiveNum + k])
				{
					continue;
				}
				else
				{
					break;
				}
			}
			for (int l = 0; l <= k - 1; l++)
			{
				if (switchs[receiveNum+l] == 1)
				{
					switchs[receiveNum + l] = 0;
					switchs[receiveNum - l] = 0;
				}
				else
				{
					switchs[receiveNum + l] = 1;
					switchs[receiveNum - l] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (count == 20)
		{
			printf("\n");
			count = 0;
		}
		if (i == N)
		{
			printf("%d\n", switchs[i]);
			count++;
		}
		else
		{
			printf("%d ", switchs[i]);
			count++;
		}

	}
	return 0;
}