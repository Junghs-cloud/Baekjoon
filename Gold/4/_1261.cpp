#include <iostream>
#include <queue>
#include <utility>
#define MAX 987654321
using namespace std;
int N, M;
int** arr;
int** distances;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void dijkstra()
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push(pair(0, pair(0, 0)));
	while (!pq.empty())
	{
		pair<int, pair<int, int>> current = pq.top();
		int x = current.second.first;
		int y = current.second.second;
		int cost = current.first;
		pq.pop();
		if (cost > distances[x][y])
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			{
				int currentCost = cost + arr[nextX][nextY];
				if (distances[nextX][nextY] > currentCost)
				{
					distances[nextX][nextY] = currentCost;
					pq.push(pair(currentCost, pair(nextX, nextY)));
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> M >> N;
	arr = new int*[N];
	distances = new int*[N];
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		arr[i] = new int[M];
		distances[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = str.at(j) - 48;
			distances[i][j] = MAX;
		}
	}
	distances[0][0] = 0;
	dijkstra();
	cout << distances[N - 1][M - 1] << "\n";
	return 0;
}