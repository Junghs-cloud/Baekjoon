#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	int* days = new int[M];
	int* pages = new int[M];
	int** dp = new int*[M];
	for (int i = 0; i < M; i++)
	{
		dp[i] = new int[N+1];
		cin >> days[i] >> pages[i];
		for (int j = 0; j < N + 1; j++)
		{
			dp[i][j] = 0;
		}
	}
	if (days[0] <= N)
	{
		dp[0][days[0]] = pages[0];
	}
	for (int i = 1; i < N + 1; i++)
	{
		dp[0][i] = max(dp[0][i], dp[0][i - 1]);
	}
	for (int i = 1; i < M; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			if (j < days[i])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - days[i]]+pages[i]);
			}
		}
	}
	cout << dp[M-1][N] << "\n";
	return 0;
}