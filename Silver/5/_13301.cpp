#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long* x = new long long[N+1];
	long long* dp = new long long[N + 1];
	if (N == 1)
	{
		cout << 4 << "\n";
	}
	else
	{
		x[1] = 1;
		x[2] = 1;
		dp[1] = 4;
		dp[2] = 6;
		for (int i = 3; i < N + 1; i++)
		{
			x[i] = x[i - 1] + x[i - 2];
			dp[i] = dp[i - 1] + 2 * x[i];
		}
		cout << dp[N] << "\n";
	}
	return 0;
}