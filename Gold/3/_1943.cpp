#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 0; t < 3; t++)
	{
		int N;
		int sum = 0;
		cin >> N;
		pair<int, int>* coins = new pair<int, int>[N];

		for (int i = 0; i < N; i++)
		{
			cin >> coins[i].first >> coins[i].second;
			sum += coins[i].first * coins[i].second;
		}
		if (sum % 2 == 1)
		{
			cout << 0 << "\n";
		}
		else
		{
			sort(coins, coins + N);
			bool** dp = new bool* [N];
			for (int i = 0; i < N; i++)
			{
				dp[i] = new bool[sum / 2 + 1];
				dp[i][0] = true;
				for (int j = 1; j < sum / 2 + 1; j++)
				{
					dp[i][j] = false;
				}
			}
			for (int i = coins[0].first; (i < sum / 2 + 1 && i <= coins[0].first * coins[0].second); i += coins[0].first)
			{
				dp[0][i] = true;
			}
			for (int i = 1; i < N; i++)
			{
				for (int j = 0; j < sum / 2 + 1; j++)
				{
					if (dp[i - 1][j] == true)
					{
						dp[i][j] = true;
						for (int k = coins[i].first; k <= coins[i].first * coins[i].second; k += coins[i].first)
						{
							if (j + k < sum / 2 + 1)
							{
								dp[i][j + k] = true;
							}
						}
					}
				}
			}
			cout << dp[N - 1][sum / 2] << "\n";
		}
	}
	return 0;
}