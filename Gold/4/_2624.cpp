#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, K;
	cin >> T;
	cin >> K;
	int** dp = new int*[K];
	pair<int, int>* arr = new pair<int, int>[K];
	for (int i = 0; i < K; i++)
	{
		dp[i] = new int[T + 1];
		cin >> arr[i].first >> arr[i].second;
		for (int j = 0; j < T + 1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = arr[0].first; i <= min(arr[0].first * arr[0].second, T); i+=arr[0].first)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i < K; i++)
	{
		for (int j = 0; j < T + 1; j++)
		{
			dp[i][j] = dp[i-1][j];
			for (int k = arr[i].first; k <= min(arr[i].first * arr[i].second, j); k+= arr[i].first)
			{
				dp[i][j] += dp[i-1][j - k];
			}
		}
	}
	cout << dp[K - 1][T] << "\n";
	return 0;
}