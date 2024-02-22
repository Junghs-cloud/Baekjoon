#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int* [N];
	int** dp = new int* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		dp[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = 987654321;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i < N; i++)
	{
		if (arr[0][i] >= arr[0][i - 1])
		{
			dp[0][i] = dp[0][i - 1] + arr[0][i] - arr[0][i - 1] + 1;
		}
		else
		{
			dp[0][i] = dp[0][i - 1];
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (arr[i][0] >= arr[i - 1][0])
		{
			dp[i][0] = dp[i - 1][0] + arr[i][0] - arr[i - 1][0] + 1;
		}
		else
		{
			dp[i][0] = dp[i - 1][0];
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			int down, right;
			if (arr[i][j - 1] <= arr[i][j])
			{
				right = arr[i][j] - arr[i][j - 1] + 1;
			}
			else
			{
				right = 0;
			}
			if (arr[i - 1][j] <= arr[i][j])
			{
				down = arr[i][j] - arr[i - 1][j] + 1;
			}
			else
			{
				down = 0;
			}
			dp[i][j] = min(dp[i-1][j] + down, dp[i][j-1] + right);
		}
	}
	cout << dp[N-1][N-1] << "\n";
	return 0;
}