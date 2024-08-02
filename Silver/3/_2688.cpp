#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	long long** dp = new long long* [65];
	for (int i = 0; i < 65; i++)
	{
		dp[i] = new long long[10];
		for (int j = 0; j < 10; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i < 65; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		long long answer = 0;
		for (int i = 0; i < 10; i++)
		{
			answer += dp[N][i];
		}
		cout << answer << "\n";
	}

	return 0;
}