#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* dp = new int[abs(N) + 1];
	if (N >= 0)
	{
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i < N+1; i++)
		{
			dp[i] = dp[i-1] % 1000000000 + dp[i - 2] % 1000000000;
			dp[i] %= 1000000000;
		}
	}
	else
	{
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i < abs(N) + 1; i++)
		{
			dp[i] = dp[i - 2] % 1000000000 - dp[i - 1] % 1000000000;
			dp[i] %= 1000000000;
		}
	}
	if (dp[abs(N)] > 0)
	{
		cout << 1 << "\n";
	}
	else if (dp[abs(N)] == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
	cout << abs(dp[abs(N)]) << "\n";
	return 0;
}