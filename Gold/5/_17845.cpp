#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N>>K;
	pair<int, int>* subjects = new pair<int, int>[K];
	long long** dp = new long long*[K+1];
	for (int i = 0; i < K+1; i++)
	{
		dp[i] = new long long[N + 1];
		for (int j = 0; j < N + 1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> subjects[i].second >> subjects[i].first;
	}
	sort(subjects, subjects + K);
	for (int i = 0; i < K; i++)
	{
		int studyTime = subjects[i].first;
		int importance = subjects[i].second;
		for (int j = 0; j < N+1; j++)
		{
			if (j < studyTime)
			{
				dp[i + 1][j] = dp[i][j];
			}
			else
			{
				dp[i + 1][j] = max(dp[i][j - studyTime] + importance, dp[i][j]);
			}
		}
	}
	cout << dp[K][N] << "\n";
	return 0;
}