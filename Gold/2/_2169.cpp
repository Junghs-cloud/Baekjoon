#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N>>M;
	int** arr = new int*[N];
	int*** dp = new int**[3];
	for (int i = 0; i < 3; i++)
	{
		dp[i] = new int* [N];
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = new int [M];
			for (int k = 0; k < M; k++)
			{
				dp[i][j][k] = -99999999;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0][0] = arr[0][0];
	dp[1][0][0] = arr[0][0];
	dp[2][0][0] = arr[0][0];
	//0은 왼쪽, 1은 위쪽, 2는 오른쪽에서 온 것.
	for (int i = 1; i < M; i++)
	{
		dp[0][0][i] = dp[0][0][i - 1]+ arr[0][i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			dp[1][i][j] = max({ dp[0][i - 1][j], dp[1][i - 1][j], dp[2][i - 1][j] }) + arr[i][j];
		}
		dp[0][i][0] = dp[1][i][0];
		dp[2][i][M - 1] = dp[1][i][M - 1];
		for (int j = 1; j < M; j++)
		{
			dp[0][i][j] = max(dp[0][i][j - 1], dp[1][i][j-1]) + arr[i][j];
		}
		for (int j = M - 2; j >= 0; j--)
		{
			dp[2][i][j] = max(dp[2][i][j + 1], dp[1][i][j + 1]) + arr[i][j];
		}
	}
	cout << max(dp[0][N - 1][M - 1], dp[1][N-1][M-1]) << "\n";
	return 0;
}