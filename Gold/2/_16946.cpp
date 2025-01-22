#include <iostream>
#include <queue>
#include <utility>
#include <set>
using namespace std;
int N, M;
char** map;
bool** isVisited;
pair<int, int>** startPoint;
int** countRecord;

queue<pair<int, int>> bfsQueue;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void bfs(int x, int y)
{
	isVisited[x][y] = true;
	bfsQueue.push(pair(x, y));
	int count = 0;
	while (!bfsQueue.empty())
	{
		pair<int, int> current = bfsQueue.front();
		for (int i = 0; i < 4; i++)
		{
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && isVisited[nextX][nextY] == false && map[nextX][nextY] == '0')
			{
				isVisited[nextX][nextY] = true;
				bfsQueue.push(pair(nextX, nextY));
				startPoint[nextX][nextY].first = x;
				startPoint[nextX][nextY].second = y;
			}
		}
		bfsQueue.pop();
		count++;
	}
	countRecord[x][y] = count;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map = new char*[N];
	isVisited = new bool*[N];
	startPoint = new pair<int, int>*[N];
	countRecord = new int*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new char[M];
		isVisited[i] = new bool[M];
		startPoint[i] = new pair<int, int>[M];
		countRecord[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			isVisited[i][j] = false;
			startPoint[i][j] = pair(i, j);
			countRecord[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isVisited[i][j] == false && map[i][j] == '0')
			{
				bfs(i, j);
			}
		}
	}
	set<pair<int, int>> s;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			s.clear();
			if (map[i][j] == '1')
			{
				countRecord[i][j] = 1;
				for (int k = 0; k < 4; k++)
				{
					int nextX = i + dx[k];
					int nextY = j + dy[k];
					if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && map[nextX][nextY] == '0')
					{
						s.insert(startPoint[nextX][nextY]);
					}
				}
				for (set<pair<int, int>>::iterator it = s.begin(); it != s.end(); it++ )
				{
					countRecord[i][j] += countRecord[it->first][it->second];
				}
				cout << countRecord[i][j] % 10;
			}
			else
			{
				cout << "0";
			}
		}
		cout << "\n";
	}
	return 0;
}