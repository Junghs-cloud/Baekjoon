#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4496)
#pragma warning(disable: 6031)
int array[1000] = { 0,0 };
void sort(int n)
{
	int min;
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i; j < n; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}

}
int main()
{
	int N;
	int P;
	long long int temp = 0;
	long long int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &P);
		array[i] = P;
	}
	sort(N);
	for (int i = 0; i < N; i++)
	{
		temp += array[i];
		sum+=temp;
	}
	printf("%lld\n", sum);
	return 0;
}