#include <iostream>
#include <queue>
using namespace std;
struct pos
{
	int i;
	int j;
	int length;
	pos(int a, int b, int c)
	{
		i = a;
		j = b;
		length = c;
	}
};

queue<pos> bfsQueue;
int N, M;
int** maze;
bool** isVisited;

void bfs()
{
	bfsQueue.push(pos(0, 0, 1));
	isVisited[0][0] = true;
	while (!bfsQueue.empty())
	{
		pos currentPos = bfsQueue.front();
		int currentI = currentPos.i;
		int currentJ = currentPos.j;
		int currentLength = currentPos.length;
		if (currentI == N - 1 && currentJ == M - 1)
		{
			cout << currentLength << "\n";
			break;
		}
		if (currentI < N - 1 && maze[currentI + 1][currentJ] == 1 && isVisited[currentI + 1][currentJ] == false)
		{
			isVisited[currentI + 1][currentJ] = true;
			bfsQueue.push(pos(currentI + 1, currentJ, currentLength + 1));
		}
		if (currentI > 0 && maze[currentI - 1][currentJ] == 1 && isVisited[currentI - 1][currentJ] == false)
		{
			isVisited[currentI - 1][currentJ] = true;
			bfsQueue.push(pos(currentI - 1, currentJ, currentLength + 1));
		}
		if (currentJ < M - 1 && maze[currentI][currentJ + 1] == 1 && isVisited[currentI][currentJ + 1] == false)
		{
			isVisited[currentI][currentJ + 1] = true;
			bfsQueue.push(pos(currentI, currentJ + 1, currentLength + 1));
		}
		if (currentJ > 0 && maze[currentI][currentJ - 1] == 1 && isVisited[currentI][currentJ - 1] == false)
		{
			isVisited[currentI][currentJ - 1] = true;
			bfsQueue.push(pos(currentI, currentJ - 1, currentLength + 1));
		}
		bfsQueue.pop();
	}
}

int main()
{
	string line;
	cin >> N >> M;
	maze = new int*[N];
	isVisited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		maze[i] = new int[M];
		isVisited[i] = new bool[M];
		cin >> line;
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
			maze[i][j] = line[j] - 48;
		}
	}
	bfs();
	return 0;
}