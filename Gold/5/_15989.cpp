#include <iostream>
using namespace std;

int main()
{
	int T, N;
	long long** dp = new long long* [10001];
	for (int i = 0; i < 10001; i++)
	{
		dp[i] = new long long[3];
		for (int j = 0; j < 3; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	for (int i = 4; i < 10001; i++)
	{
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		cin >> N;
		cout << dp[N][0] + dp[N][1] + dp[N][2] << "\n";
	}

	return 0;
}