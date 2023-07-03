#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct info
{
	int x;
	int y;
	int length;
	info(int a, int b, int c)
	{
		x = a;
		y = b;
		length = c;
	}
};
queue<info> bfsQueue;
int** arr;
bool** isVisited;
int N, M;
int maxLength = 0;

void bfs(int i, int j)
{
	bfsQueue.push(info(i, j, 0));
	isVisited[i][j] = true;
	while (!bfsQueue.empty())
	{
		info currentInfo = bfsQueue.front();
		if (arr[currentInfo.x][currentInfo.y] < currentInfo.length)
		{
			arr[currentInfo.x][currentInfo.y] = currentInfo.length;
		}
		if (currentInfo.x < N - 1 && isVisited[currentInfo.x + 1][currentInfo.y] == false && arr[currentInfo.x + 1][currentInfo.y] != -1)
		{
			isVisited[currentInfo.x + 1][currentInfo.y] = true;
			bfsQueue.push(info(currentInfo.x + 1, currentInfo.y, currentInfo.length + 1));
		}
		if (currentInfo.x > 0 && isVisited[currentInfo.x - 1][currentInfo.y] == false && arr[currentInfo.x - 1][currentInfo.y] != -1)
		{
			isVisited[currentInfo.x - 1][currentInfo.y] = true;
			bfsQueue.push(info(currentInfo.x - 1, currentInfo.y, currentInfo.length + 1));
		}
		if (currentInfo.y < M - 1 && isVisited[currentInfo.x][currentInfo.y+1] == false && arr[currentInfo.x][currentInfo.y+1] != -1)
		{
			isVisited[currentInfo.x][currentInfo.y+1] = true;
			bfsQueue.push(info(currentInfo.x, currentInfo.y+1, currentInfo.length + 1));
		}
		if (currentInfo.y > 0 && isVisited[currentInfo.x][currentInfo.y - 1] == false && arr[currentInfo.x][currentInfo.y - 1] != -1)
		{
			isVisited[currentInfo.x][currentInfo.y - 1] = true;
			bfsQueue.push(info(currentInfo.x, currentInfo.y - 1, currentInfo.length + 1));
		}
		bfsQueue.pop();
		if (currentInfo.length > maxLength)
		{
			maxLength = currentInfo.length;
		}
	}
}

void reset()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> N >> M;
	arr = new int*[N];
	isVisited = new bool*[N];
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		isVisited[i] = new bool[M];
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
			if (str[j] == 'W')
			{
				arr[i][j] = -1;
			}
			else
			{
				arr[i][j] = 0;
				v.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		pair<int, int> p = v.at(i);
		bfs(p.first, p.second);
		reset();
	}
	cout << maxLength << "\n";
	return 0;
}