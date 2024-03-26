#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long** dp = new long long*[N+1];
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = new long long[8];
		for (int j = 0; j < 8; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i < N + 1; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 1000000007;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2] + dp[i-1][3]) %1000000007;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i-1][3] + dp[i-1][4]) % 1000000007;
		dp[i][3] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][5]) % 1000000007;
		dp[i][4] = (dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][7]) % 1000000007;
		dp[i][5] = (dp[i - 1][3] + dp[i - 1][4] + dp[i - 1][6]) % 1000000007;
		dp[i][6] = (dp[i - 1][5] + dp[i - 1][7]) % 1000000007;
		dp[i][7] = (dp[i - 1][4] + dp[i - 1][6]) % 1000000007;
	}
	cout<<dp[N][0]<<"\n";
	return 0;
}