#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N;
	int** dp = new int* [2];
	pair<int, int>* jumps = new pair<int, int>[N-1];
	for (int i = 0; i < 2; i++)
	{
		dp[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = 987654321;
		}
	}
	for (int i = 0; i < N-1; i++)
	{
		cin >> jumps[i].first >> jumps[i].second;
	}
	cin >> K;
	dp[0][0] = 0;
	dp[1][0] = 0;
	for (int i = 1; i < N; i++)
	{
		if (i == 1)
		{
			dp[0][i] = jumps[i-1].first;
		}
		else
		{
			dp[0][i] = min(dp[0][i - 1] + jumps[i - 1].first, dp[0][i - 2] + jumps[i - 2].second);
		}
		if (i >= 3)
		{
			dp[1][i] = min({ dp[0][i - 3] + K, dp[1][i - 1] + jumps[i - 1].first, dp[1][i - 2] + jumps[i - 2].second });
		}
	}
	cout << min(dp[0][N - 1], dp[1][N - 1])<<"\n";
	return 0;
}