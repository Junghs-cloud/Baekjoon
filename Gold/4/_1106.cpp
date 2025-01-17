#include <iostream>
#include <utility>
#define MAX 123456789
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int C, N;
	cin >> C >> N;
	int** dp = new int*[N];
	pair<int, int>* cities = new pair<int, int>[N];
	int answer = MAX;
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[2001];
		cin >> cities[i].first >> cities[i].second;
		for (int j = 0; j < 2001; j++)
		{
			if (j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = MAX;
			}
		}
	}
	for (int i = cities[0].second; i < 2001; i += cities[0].second)
	{
		int multiple = i / cities[0].second;
		int money = cities[0].first * multiple;
		dp[0][i] = money;
		if (i >= C)
		{
			answer = min(answer, dp[0][i]);
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 2001; j++)
		{
			dp[i][j] = dp[i - 1][j];

			int maxMultiple = j / cities[i].second;
			for (int k = 0; k <= maxMultiple; k++)
			{
				int money = cities[i].first * k;
				int person = cities[i].second * k;
				dp[i][j] = min(dp[i][j], dp[i][j - person] + money);
			}

			if (j >= C)
			{
				answer = min(answer, dp[i][j]);
			}
		}
	}
	std::cout << answer << "\n";
	return 0;
}