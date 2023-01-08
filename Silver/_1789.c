#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)

int main()
{
	long long int N;
	long long int i = 1;
	long long int sum = 0;
	scanf("%lld", &N);
	while (1)
	{
		sum += i;
		if (sum > N)
		{
			--i;
			break;
		}
		i++;
	}

	printf("%lld\n", i);
	return 0;
}