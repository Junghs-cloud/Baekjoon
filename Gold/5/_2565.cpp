#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first < p2.first)
	{
		return false;
	}
	else if (p1.first == p2.first)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	pair<int, int>* arr = new pair<int, int>[N];
	int** dp = new int*[N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[2];
		for (int j = 0; j < 2; j++)
		{
			dp[i][j] = 0;
		}
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	dp[0][1] = 1;
	for (int i = 1; i < N; i++)
	{
		int currentSecond = arr[i].second;
		int upLength = 0;
		int downLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j].second < currentSecond && dp[j][1] > upLength)
			{
				upLength = dp[j][1];
			}
			if (arr[j].second > currentSecond && dp[j][1] < downLength)
			{
				downLength = dp[j][1];
			}
		}
		dp[i][1] = max(upLength + 1, downLength+1);
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (dp[i][0] > answer)
		{
			answer = dp[i][0];
		}
		if (dp[i][1] > answer)
		{
			answer = dp[i][1];
		}
	}
	answer = N - answer;
	cout << answer << "\n";
	return 0;
}