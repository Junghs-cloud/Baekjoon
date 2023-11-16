#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int** dp = new int*[N];
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[10];
		for (int j = 0; j < 10; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] += dp[i - 1][k] % 10007;
				dp[i][j] %= 10007;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		answer += dp[N - 1][i] % 10007;
		answer %= 10007;
	}
	cout << answer << "\n";
	return 0;
}