#include <iostream>
#include <utility>
using namespace std;
int** arr;
int** dp;
int N, M;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int dfs(int x, int y)
{
	if (x == N - 1 && y == M - 1)
	{
		return 1;
	}
	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}
	else
	{
		dp[x][y] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX == -1 || nextX == N || nextY==-1 || nextY == M)
			{
				continue;
			}
			if (arr[x][y] > arr[nextX][nextY])
			{
				dp[x][y] += dfs(nextX, nextY);
			}
		}
	}
	return dp[x][y];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >>M;
	arr = new int* [N];
	dp = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		dp[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}
	cout << dfs(0, 0) << "\n";
	return 0;
}