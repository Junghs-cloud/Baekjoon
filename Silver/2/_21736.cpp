#include <iostream>
#include <queue>
using namespace std;
bool** isVisited;
char** arr;
int N, M;

struct info
{
	int x;
	int y;
	info(int a, int b)
	{
		x = a;
		y = b;
	}
};
queue<info> bfsQueue;
int peopleCount = 0;

void bfs(int i, int j)
{
	bfsQueue.push(info(i, j));
	isVisited[i][j] = true;
	while (!bfsQueue.empty())
	{
		info currentFront = bfsQueue.front();
		if (arr[currentFront.x][currentFront.y] == 'P')
		{
			peopleCount++;
		}
		if (currentFront.x < N-1 && arr[currentFront.x+1][currentFront.y] != 'X' && isVisited[currentFront.x + 1][currentFront.y]==false)
		{
			isVisited[currentFront.x + 1][currentFront.y] = true;
			bfsQueue.push(info(currentFront.x + 1, currentFront.y));
		}
		if (currentFront.x > 0 && arr[currentFront.x - 1][currentFront.y] != 'X' && isVisited[currentFront.x - 1][currentFront.y] == false)
		{
			isVisited[currentFront.x - 1][currentFront.y] = true;
			bfsQueue.push(info(currentFront.x - 1, currentFront.y));
		}
		if (currentFront.y < M-1 && arr[currentFront.x][currentFront.y+1] != 'X' && isVisited[currentFront.x][currentFront.y+1] == false)
		{
			isVisited[currentFront.x][currentFront.y+1] = true;
			bfsQueue.push(info(currentFront.x, currentFront.y+1));
		}
		if (currentFront.y > 0 && arr[currentFront.x][currentFront.y - 1] != 'X' && isVisited[currentFront.x][currentFront.y - 1] == false)
		{
			isVisited[currentFront.x][currentFront.y - 1] = true;
			bfsQueue.push(info(currentFront.x, currentFront.y - 1));
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	string str;
	isVisited = new bool*[N];
	arr = new char*[N];
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		arr[i] = new char[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
			arr[i][j] = str.at(j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'I')
			{
				bfs(i, j);
			}
		}
	}
	if (peopleCount == 0)
	{
		cout << "TT" << "\n";
	}
	else
	{
		cout << peopleCount << "\n";
	}
	
	return 0;
}