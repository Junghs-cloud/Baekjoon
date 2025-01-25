#include <iostream>
#include <algorithm>
using namespace std;

long long pow(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	else
	{
		long long answer = x;
		for (int i = 1; i < y; i++)
		{
			answer *= x;
		}
		return answer;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int** map = new int*[N];
	long long** dp = new long long*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
		dp[i] = new long long[N];
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			dp[i][j] = 0;
		}
	}
	dp[0][0] = map[0][0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][0] * 2 + map[i][0];
		dp[0][i] = dp[0][i - 1] * 2  + map[0][i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			dp[i][j] = 2 * max(dp[i - 1][j], dp[i][j-1]) + map[i][j];
		}
	}
	cout << dp[N - 1][N - 1] << "\n";
	return 0;
}