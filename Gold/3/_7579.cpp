#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	int* memories = new int[N];
	int* costs = new int[N];
	int costSum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> memories[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> costs[i];
		costSum += costs[i];
	}
	int** dp = new int*[N+1];
	for (int i = 0; i < N+1; i++)
	{
		dp[i] = new int[costSum+1];
		for (int j = 0; j < costSum+1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 0; j < costSum+1; j++)
		{
			if (j == costs[i-1])
			{
				if (j == 0)
				{
					dp[i][j] = dp[i - 1][j] + memories[i-1];
				}
				else
				{
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - costs[i - 1]] + memories[i - 1]);
				}
			}
			else if (j < costs[i - 1])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j-costs[i-1]]+memories[i-1]);
			}
		}
	}
	for (int i = 0; i < costSum+1; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i << "\n";
			break;
		}
	}
	return 0;
}