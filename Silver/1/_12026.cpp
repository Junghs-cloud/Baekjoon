#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string str;
	cin >> N;
	int* dp = new int[N];
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		dp[i] = INF;
	}
	dp[0] = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (str[i] == 'J' && str[j]=='O' && dp[j] != INF)
			{
				dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
			else if (str[i] == 'O' && str[j] == 'B' && dp[j] != INF)
			{
				dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
			else if (str[i] == 'B' && str[j] == 'J' && dp[j] != INF)
			{
				dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
		}
	}
	if (dp[N - 1] == INF)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << dp[N - 1] << "\n";
	}
	return 0;
}