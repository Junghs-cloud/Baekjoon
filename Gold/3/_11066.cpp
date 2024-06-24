#include <iostream>
#define INF 987654321
using namespace std;
int dp[501][501];
int sums[501];

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N, pages;
		cin >> N;
		sums[0] = 0;
		for (int i = 1; i < N + 1; i++)
		{
			cin >> pages;
			sums[i] = sums[i - 1] + pages;
		}
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1 - i; j++)
			{
				dp[j][i + j] = INF;
				for (int mid = j; mid < i + j; mid++)
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][mid] + dp[mid + 1][i + j] + sums[i + j] - sums[j - 1]);
				}
			}
		}
		cout << dp[1][N] << "\n";
	}
	return 0;
}