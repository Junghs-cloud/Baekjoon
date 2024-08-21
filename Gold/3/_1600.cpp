#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
queue<tuple<int, int, int>> bfsQueue;
int K, W, H;
int*** isVisited;
int** arr;
int dx[] = {-1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0 };
int hDx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hDy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs()
{
	bfsQueue.push(make_tuple(0, 0, 0));
	for (int i = 0; i < K+1; i++)
	{
		isVisited[i][0][0] = 0;
	}
	while (!bfsQueue.empty())
	{
		tuple<int, int, int> currentInfo = bfsQueue.front();
		int x = get<0>(currentInfo);
		int y = get<1>(currentInfo);
		int horeseMoveCount = get<2>(currentInfo);
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextX < H && nextY >= 0 && nextY < W && isVisited[horeseMoveCount][nextX][nextY]==-1 && arr[nextX][nextY]==0)
			{
				isVisited[horeseMoveCount][nextX][nextY] = isVisited[horeseMoveCount][x][y] + 1;
				bfsQueue.push(make_tuple(nextX, nextY, horeseMoveCount));
			}
		}
		if (horeseMoveCount < K)
		{
			for (int i = 0; i < 8; i++)
			{
				int nextX = x + hDx[i];
				int nextY = y + hDy[i];
				if (nextX >= 0 && nextX < H && nextY >= 0 && nextY < W && isVisited[horeseMoveCount+1][nextX][nextY] == -1 && arr[nextX][nextY] == 0)
				{
					isVisited[horeseMoveCount+1][nextX][nextY] = isVisited[horeseMoveCount][x][y] + 1;
					bfsQueue.push(make_tuple(nextX, nextY, horeseMoveCount+1));
				}
			}
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K;
	cin >> W >> H;
	arr = new int* [H];
	isVisited = new int** [K+1];
	for (int i = 0; i < K+1; i++)
	{
		isVisited[i] = new int* [H];
		for (int j = 0; j < H; j++)
		{
			isVisited[i][j] = new int[W];
			for (int k = 0; k < W; k++)
			{
				isVisited[i][j][k] = -1;
			}
		}
	}

	for (int i = 0; i < H; i++)
	{
		arr[i] = new int[W];
		for (int j = 0; j < W; j++)
		{
			cin >> arr[i][j];
		}
	}
	bfs();
	bool canGo = false;
	int answer = 987654321;
	for (int i = 0; i < K+1; i++)
	{
		if (isVisited[i][H - 1][W - 1] != -1)
		{
			canGo = true;
			answer = min(answer, isVisited[i][H - 1][W - 1]);
		}
	}
	if (canGo == true)
	{
		cout << answer << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
	return 0;
}