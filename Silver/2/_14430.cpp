#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** arr = new int*[N];
	int** dp = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		dp[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = dp[i - 1][0]+arr[i][0];
	}
	for (int i = 1; i < M; i++)
	{
		dp[0][i] = dp[0][i - 1] + arr[0][i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j-1]) + arr[i][j];
		}
	}
	cout << dp[N - 1][M - 1] << "\n";
	return 0;
}