#include <iostream>
#include <queue>
#include <utility>
#include <tuple>
#define MAX 987654321
using namespace std;

int dx[] = { -1,0, 0, 1 };
int dy[] = {0, -1, 1, 0};
int N, M, K;
int*** arr;
string* map;

bool isInRange(int nextX, int nextY)
{
	if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void bfs()
{
	queue<tuple<int, int, int>> bfsQueue;
	arr[0][0][0] = 1;
	bfsQueue.push(tuple(0, 0, 0));
	while (!bfsQueue.empty())
	{
		tuple<int, int, int> current = bfsQueue.front();
		int x = get<0>(current);
		int y = get<1>(current);
		int k = get<2>(current);
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY =  y + dy[i];
			if (isInRange(nextX, nextY) && map[nextX][nextY] == '0' && arr[k][nextX][nextY] == MAX)
			{
				arr[k][nextX][nextY] = arr[k][x][y] + 1;
				bfsQueue.push(tuple(nextX, nextY, k));
			}
			if (isInRange(nextX, nextY)&& k < K && map[nextX][nextY] == '1' && arr[k + 1][nextX][nextY] == MAX)
			{
				arr[k+1][nextX][nextY] = arr[k][x][y] + 1;
				bfsQueue.push(tuple(nextX, nextY, k+1));
			}
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int answer = MAX;
	cin >> N >> M >> K;
	arr = new int**[K+1];
	map = new string[N];
	for (int i = 0; i < K+1; i++)
	{
		arr[i] = new int*[N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = new int[M];
			for (int k = 0; k < M; k++)
			{
				arr[i][j][k] = MAX;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> map[i];
	}
	bfs();
	for (int i = 0; i < K + 1; i++)
	{
		answer = min(answer, arr[i][N - 1][M-1]);
	}
	if (answer == MAX)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << answer << "\n";
	}
	return 0;
}