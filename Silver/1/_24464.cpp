#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	long long** dp = new long long*[N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = new long long[5];
		for (int j = 0; j < 5; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;
	dp[0][3] = 1;
	dp[0][4] = 1;
	for (int i = 1; i < N; i++)
	{
		dp[i][0]= (dp[i - 1][1] + dp[i-1][2] + dp[i - 1][3] + dp[i - 1][4]) %1000000007;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][3]+dp[i-1][4]) % 1000000007;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][4]) % 1000000007;
		dp[i][3] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
		dp[i][4] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 1000000007;
	}
	cout << (dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2] + dp[N - 1][3] + dp[N - 1][4]) % 1000000007 << "\n";
	return 0;
}