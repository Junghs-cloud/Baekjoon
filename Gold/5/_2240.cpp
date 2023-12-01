#include <iostream>
using namespace std;
int N, M;
int* plums;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N>>M;
	plums= new int[N];
	int*** dp = new int** [M+1];
	int answer = 0;
	for (int i = 0; i < M+1; i++)
	{
		dp[i] = new int*[N];
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = new int[2];
			for (int k = 0; k < 2; k++)
			{
				dp[i][j][k] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> plums[i];
	}
	if (plums[0] == 1)
	{
		dp[0][0][0] = 1;
	}
	else
	{
		dp[1][0][1] = 1;
	}
	for (int j = 1; j < N; j++)
	{
		if (plums[j] == 1)
		{
			dp[0][j][0] = dp[0][j-1][0] + 1;
		}
		else
		{
			dp[0][j][0] = dp[0][j - 1][0];
		}
	}
	for (int i = 1; i < M+1; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (plums[j] == 1)
			{
				dp[i][j][0] = max(dp[i][j - 1][0] + 1, dp[i - 1][j - 1][1] + 1);
				dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i][j - 1][1]);
			}
			else
			{
				dp[i][j][0] = max(dp[i][j - 1][0], dp[i - 1][j - 1][1]);
				dp[i][j][1] = max(dp[i - 1][j - 1][0] + 1, dp[i][j - 1][1] + 1);
			}
		}
	}
	for (int i = 0; i < M+1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (dp[i][j][k] > answer)
				{
					answer = dp[i][j][k];
				}
			}
		}
	}
	cout << answer<< "\n";
	return 0;
}