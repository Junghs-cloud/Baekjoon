#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int main()
{
	int a, b;
	int hap_num=0;
	int temp=-1;
	int sum=0;
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++)
	{
		temp++;
		if (temp == hap_num)
		{
			temp = 0;
			hap_num++;
		}
	}
	for (int i = a; i <= b; i++)
	{
		sum += hap_num;
		temp++;
		if (temp == hap_num)
		{
			temp = 0;
			hap_num++;
		}
	}
	printf("%d\n",sum);
	return 0;
}