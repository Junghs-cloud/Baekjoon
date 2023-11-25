#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N;
	cin >> T;
	long long* dp = new long long[1000001];
	for (int i = 0; i < 1000001; i++)
	{
		dp[i] = 0;
	}
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 1000001; i++)
	{
		dp[i] += dp[i - 3] % 1000000009 + dp[i - 2] % 1000000009 + dp[i - 1] % 1000000009;
		dp[i] = dp[i] % 1000000009;
	}
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}