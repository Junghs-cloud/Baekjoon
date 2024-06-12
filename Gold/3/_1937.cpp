#include <iostream>
#include <algorithm>
using namespace std;
int** arr;
int** dp;
int N;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int dfs(int x, int y)
{
	if (dp[x][y] != -1)
	{
		return dp[x][y];
	}
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
		{
			if (arr[x][y] < arr[nextX][nextY])
			{
				dp[x][y] = max(dp[x][y], dfs(nextX, nextY)+1);
			}
		}
	}
	return dp[x][y];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int* [N];
	dp = new int* [N];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		dp[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer = max(answer, dfs(i, j));
		}
	}
	cout << answer << "\n";
	return 0;
}