#include <stdio.h>
#pragma warning(disable: 4996)
#pragma warning(disable: 6031)
#define _CRT_SECURE_NO_WARNING
int GCD(int r1, int r2)
{
	if (r2 == 0)
	{
		return r1;
	}
	else
	{
		return GCD(r2, r1 % r2);
	}

}


int main()
{
	int N;
	int r;
	int r1;
	int gcd;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &r);
		if (i == 0)
		{
			r1 = r;
		}
		else if (i != 0)
		{
			gcd = GCD(r1, r);
			printf("%d/%d\n", (r1 / gcd), (r / gcd));

		}

	}


	return 0;
}