#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
char car[1000][9];
char overtake[1000][9];
int top = 0;
int num = 0;
int flag = 0;
int main()
{
	int N;
	char out[9] = {'\0'};
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		gets(car[i]);

	}
	printf("�Էµ�����\n-------------------\n");
	for (int i = 0; i < N; i++)
	{
		gets(out);
		if (!(strcmp(out, car[top])))
		{
			top++;
		}
		else
		{
			printf("������ ��: %s top��: %s\n", out, car[top]);
			for (int j = 0; j < num; j++)
			{
				printf("num ��: %d top��: %d\n", num, top);
				if (!(strcmp(car[top], overtake[j])))
				{
					printf("j��: %d,  %s ���� �߿��ؼ� �̹� ��������\n", j, car[top]);
					top++;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				printf("�߿�\n");
				strcpy(overtake[num], out);
				num++;
			}
			flag = 0;

		}

		printf("-------------------\n");
	}
	printf("%d\n", num);

	return 0;
}