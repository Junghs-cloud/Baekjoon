#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int answer = INF;
	cin >> N >> M;
	int*** dp = new int**[3];
	for (int i = 0; i < 3; i++)
	{
		dp[i] = new int* [N];
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = new int[M];
			for (int k = 0; k < M; k++)
			{
				dp[i][j][k] = INF;
			}
		}
	}
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	//0: 왼쪽, 1: 직진, 2: 오른쪽
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dp[i][0][j] = arr[0][j];
		}
	}
	dp[2][0][0] = INF;
	dp[0][0][M - 1] = INF;

	for (int j = 1; j < N; j++)
	{
		dp[0][j][0] = min(dp[1][j - 1][1], dp[2][j-1][1]) + arr[j][0];
		dp[1][j][0] = dp[0][j - 1][0] + arr[j][0];

		for (int k = 1; k < M - 1; k++)
		{
			dp[0][j][k] = min(dp[1][j - 1][k+1], dp[2][j - 1][k+1]) + arr[j][k];
			dp[1][j][k] = min(dp[0][j - 1][k], dp[2][j - 1][k]) + arr[j][k];
			dp[2][j][k] = min(dp[0][j - 1][k-1], dp[1][j - 1][k-1]) + arr[j][k];
		}

		dp[1][j][M - 1] = dp[2][j - 1][M - 1] + arr[j][M - 1];
		dp[2][j][M - 1] = min(dp[0][j - 1][M - 2], dp[1][j-1][M-2]) + arr[j][M - 1];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer = min(answer, dp[i][N - 1][j]);
		}
	}
	cout << answer << "\n";
	return 0;
}