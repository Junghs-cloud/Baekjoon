#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	long long** dp = new long long*[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = new long long[4];
		for (int j = 0; j < 4; j++)
		{
			dp[i][j] = -200000000;
		}
	}
	dp[0][0] = arr[0];
	dp[0][1] = 2 * arr[0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i-1][3]) + arr[i];
		dp[i][1] = max(dp[i - 1][0], dp[i-1][3]) + 2 * arr[i];
		dp[i][2] = dp[i - 1][1] + 2 * arr[i];
		dp[i][3] = dp[i - 1][2] + 2 * arr[i];
	}
	cout << max({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2], dp[N - 1][3] })<<"\n";
	return 0;
}