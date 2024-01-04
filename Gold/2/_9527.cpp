#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long* dp;

long long get(long long x)
{
	if (x == 0)
	{
		return 0;
	}
	long long n = 1;
	long long N = 0;
	while (true)
	{
		if (n > x)
		{
			break;
		}
		n = n << 1;
		N++;
	}
	if (n/2 == x)
	{
		return  dp[N];
	}
	else
	{
		return dp[N] + get(x - n/2) + x - n/2;
	}
}

int main()
{
	long long A, B;
	dp = new long long[56];
	dp[0] = 0;
	dp[1] = 1;
	long long N = 1;
	for (int i = 2; i < 56; i++)
	{
		dp[i] = dp[i - 1] * 2 + N - 1;
		N = N << 1;
	}
	cin >> A >> B;
	cout << get(B) - get(A - 1) << "\n";
	return 0;
}