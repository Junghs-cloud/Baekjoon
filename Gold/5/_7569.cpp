#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int dx[] = {-1, 0, 0, 1, 0, 0};
int dy[] = {0, -1, 1, 0, 0, 0};
int dz[] = { 0, 0, 0, 0, -1, 1 };
queue<tuple<int, int, int, int>> bfsQueue;
int*** arr;
int ripenTomatoes;
int tomatoes;
int M, N, H;
int maxDay = 0;

void bfs()
{
	while (!bfsQueue.empty())
	{
		tuple<int, int, int, int> front = bfsQueue.front();
		int z = get<0>(front);
		int x = get<1>(front);
		int y = get<2>(front);
		int day = get<3>(front);
		ripenTomatoes++;
		maxDay = max(day, maxDay);
		for (int i = 0; i < 6; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			int nextZ = z + dz[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && nextZ >= 0 && nextZ < H && arr[nextZ][nextX][nextY] == 0)
			{
				arr[nextZ][nextX][nextY] = 1;
				bfsQueue.push(tuple(nextZ, nextX, nextY, day+1));
			}
		}
		bfsQueue.pop();
	}
	if (ripenTomatoes == tomatoes)
	{
		cout << maxDay << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >>M>> N>>H;
	arr = new int**[H];
	for (int i = 0; i < H; i++)
	{
		arr[i] = new int* [N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = new int[M];
			for (int k = 0; k < M; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] != -1)
				{
					tomatoes++;
				}
				if (arr[i][j][k] == 1)
				{
					bfsQueue.push(tuple(i, j, k, 0));
				}
			}
		}
	}
	bfs();
	return 0;
}