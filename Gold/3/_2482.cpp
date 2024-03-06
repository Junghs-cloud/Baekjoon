#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int** dp = new int*[1001];
	long long answer = 0;
	for (int i = 0; i < 1001; i++)
	{
		dp[i] = new int[1001];
		for (int j = 0; j < 1001; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i< 1001; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j] % 1000000003 + dp[i - 1][j - 1] % 1000000003;
			dp[i][j] %= 1000000003;
		}
	}
	int N, K;
	cin >> N>>K;
	if (N % 2 == 0 && K > N / 2)
	{
		cout << "0" << "\n";
	}
	else if (N % 2 == 1 &&  K >= (N / 2 + 1))
	{
		cout << "0" << "\n";
	}
	else
	{
		int a = N - 1;
		int b = K;
		if (N - K - b >= 0)
		{
			answer = dp[N - K][b];
		}
		int c = N - 3;
		int d = K - 1;
		if (N-K-1 -d >= 0)
		{
			answer += dp[N-K-1][d];
		}
		answer %= 1000000003;
		cout << answer << "\n";
	}
	return 0;
}