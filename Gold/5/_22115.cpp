#include <iostream>
#include <algorithm>
#define MAX 10000000
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** dp = new int*[N];
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[M+1];
		cin >> arr[i];
		for (int j = 0; j < M+1; j++)
		{
			dp[i][j] = MAX;
		}
	}
	if (M == 0)
	{
		cout << 0 << "\n";
	}
	else
	{
		sort(arr, arr + N);
		for (int i = 0; i < M + 1; i++)
		{
			if (i == arr[0])
			{
				dp[0][i] = 1;
			}
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < M + 1; j++)
			{
				if (j < arr[i])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else if (j == arr[i])
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][j - arr[i]]);
				}
			}
		}
		if (dp[N - 1][M] == MAX)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << dp[N - 1][M] << "\n";
		}
	}
	return 0;
}