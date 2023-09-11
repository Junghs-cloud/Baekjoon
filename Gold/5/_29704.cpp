#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, T;
	cin >> N >> T;
	int* moneys = new int[N];
	int* days = new int[N];
	int** dp = new int*[N];
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> days[i] >> moneys[i];
		sum += moneys[i];
	}
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[T+1];
		for (int j = 0; j < T+1; j++)
		{
			dp[i][j]=sum;
		}
	}
	dp[0][days[0]] = dp[0][days[0]] - moneys[0];
	for (int i = 1; i < T + 1; i++)
	{
		dp[0][i] = min(dp[0][i], dp[0][i - 1]);
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < T + 1; j++)
		{
			if (j - days[i] < 0)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - days[i]] - moneys[i]);
			}
		}
	}
	cout << dp[N - 1][T] << "\n";
	return 0;
}