#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* HP = new int[N];
	int* happiness = new int[N];
	int** dp = new int* [N + 1];
	for (int i = 0; i < N; i++)
	{
		cin >> HP[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> happiness[i];
	}
	for (int i = 0; i < N+1; i++)
	{
		dp[i] = new int[100];
		for (int j = 0; j < 100; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < 100; j++)
		{
			if (j < HP[i-1])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j-HP[i-1]]+happiness[i-1]);
			}
		}
	}
	cout << dp[N][99] << "\n";
	return 0;
}