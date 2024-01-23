#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int** dp = new int* [N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[N];
		cin >> arr[i];
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		dp[0][i] = arr[0] * (i + 1);
	}
	for (int i = 1; i < N; i++)
	{
		int current = 0;
		for (int j = 0; j < N; j++)
		{
			if (j < i)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if ((j + 1) % (i + 1) == 0)
			{
				int division = (j + 1) / (i + 1);
				dp[i][j] = max(dp[i - 1][j], arr[i] * division);
				current = j;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][current] + dp[i - 1][j - current - 1]);
			}
		}
	}
	cout << dp[N - 1][N - 1] << "\n";
	return 0;
}