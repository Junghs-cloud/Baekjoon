#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, D;
	cin >> N >> D;
	pair<pair<int, int>,int>* arr = new pair<pair<int, int>, int>[N];
	int* dp = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first.first >> arr[i].first.second>>arr[i].second;
		dp[i] = 0;
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		if (arr[i].first.second <= D)
		{
			if (arr[i].second <= arr[i].first.second - arr[i].first.first)
			{
				int length = 987654321;
				for (int j = 0; j < i; j++)
				{
					if (arr[j].first.second <= arr[i].first.first && ((arr[i].first.first - arr[j].first.second)+dp[j] < length))
					{
						length = dp[j]+(arr[i].first.first-arr[j].first.second);
					}
				}
				if (length == 987654321)
				{
					dp[i] = arr[i].first.first + arr[i].second;
				}
				else
				{
					dp[i] = arr[i].second + length;
				}
			}
			else
			{
				dp[i] = 987654321;
			}
		}
		else
		{
			dp[i] = 987654321;
		}
	}
	int min = D;
	for (int i = 0; i < N; i++)
	{
		if (dp[i] + D - arr[i].first.second < min)
		{
			min = dp[i] + D - arr[i].first.second;
		}
	}
	cout << min << "\n";
	return 0;
}