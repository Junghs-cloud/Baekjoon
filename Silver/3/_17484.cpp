#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** arr = new int*[N];
	int*** dp = new int**[3];
	int answer = 987654321;
	for (int i = 0; i < 3; i++)
	{
		dp[i] = new int* [N];
		for (int j = 0; j < N; j++)
		{
			dp[i][j] = new int[M];
			for (int k = 0; k < M; k++)
			{
				dp[i][j][k] = 0;
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
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ((i == 2 && j == 0) ||( i==0 && j==M-1))
			{
				dp[i][0][j] = 999999;
			}
			else
			{
				dp[i][0][j] = arr[0][j];
			}
		}
	}
	for (int j = 1; j < N; j++)
	{
		for (int k = 0; k < M; k++)
		{
			if (k == M - 1)
			{
				dp[0][j][k]= 999999;
			}
			else
			{
				dp[0][j][k] = min(dp[1][j - 1][k + 1], dp[2][j - 1][k + 1]) + arr[j][k];
			}
			dp[1][j][k] = min(dp[0][j - 1][k], dp[2][j - 1][k]) + arr[j][k];
			if (k == 0)
			{
				dp[2][j][k]= 999999;
			}
			else
			{
				dp[2][j][k] = min(dp[0][j-1][k - 1], dp[1][j-1][k - 1]) + arr[j][k];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ( dp[i][N - 1][j] < answer)
			{
				answer = dp[i][N - 1][j];
			}
		}
	}
	cout << answer << "\n";
	return 0;
}