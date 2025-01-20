#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long** dp = new long long*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = new long long[3];
		for (int j = 0; j < 3; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[1][0] = 0;
	dp[1][1] = 0;
	dp[1][2] = 1;
	for (int i = 2; i < N + 1; i++)
	{
		dp[i][0] = (dp[i-1][2] + dp[i-1][1]) % 1000000007;
		dp[i][1] = (dp[i-1][2] + dp[i-1][0]) % 1000000007;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;

		dp[i][0] %= 1000000007;
		dp[i][1] %= 1000000007;
		dp[i][2] %= 1000000007;
	}
	cout << dp[N][0] << "\n";
	return 0;
}