#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int*[N];
	long long** dp = new long long*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		dp[i] = new long long[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)
			{
				continue;
			}
			int nextX = i + arr[i][j];
			int nextY = j + arr[i][j];
			if (nextX < N)
			{
				dp[nextX][j] += dp[i][j];
			}
			if (nextY < N)
			{
				dp[i][nextY]+=dp[i][j];
			}
		}
	}
	cout << dp[N - 1][N - 1] << "\n";
	return 0;
}