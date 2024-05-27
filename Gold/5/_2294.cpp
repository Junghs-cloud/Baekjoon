#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int* arr = new int[N];
	int** dp = new int*[N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = new int[K+1];
		cin >> arr[i];
		dp[i][0] = 0;
		for (int j = 1; j < K+1; j++)
		{
			dp[i][j] = MAX;
		}
	}
	sort(arr, arr + N);
	for (int i = arr[0]; i < K+1; i += arr[0])
	{
		dp[0][i] = i / arr[0];
	}
	for (int i = 1; i < N; i++)
	{
		int currentMoney = arr[i];
		for (int j = 0; j < K + 1; j++)
		{
			if (j < currentMoney)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else if (j % currentMoney == 0)
			{
				dp[i][j] = min(j / arr[i], dp[i-1][j]);
			}
			else
			{
				dp[i][j] = min(dp[i][j - currentMoney]+1, dp[i-1][j]);
			}
		}
	}
	if (dp[N - 1][K] == MAX)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << dp[N - 1][K] << "\n";
	}
	return 0;
}