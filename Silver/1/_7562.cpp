#include <iostream>
#include <queue>
using namespace std;
int board[301][301];
bool isVisited[301][301];
int boardSize;
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int knightX, knightY;
int endX, endY;

struct info
{
	int x;
	int y;
	int count;
	info(int a, int b, int c)
	{
		x = a;
		y = b;
		count = c;
	}
};
queue<info> bfsQueue;

void bfs()
{
	bfsQueue.push(info(knightX, knightY, 0));
	isVisited[knightX][knightY] = true;
	while (!bfsQueue.empty())
	{
		info currentFront = bfsQueue.front();
		if (currentFront.x == endX && currentFront.y == endY)
		{
			cout << currentFront.count << "\n";
		}
		for (int i = 0; i < 8; i++)
		{
			int nextX = currentFront.x + dx[i];
			int nextY = currentFront.y + dy[i];
			if (nextX >= 0 && nextX < boardSize && nextY >= 0 && nextY < boardSize && isVisited[nextX][nextY] == false)
			{
				isVisited[nextX][nextY] = true;
				bfsQueue.push(info(nextX, nextY, currentFront.count + 1));
			}
		}
		bfsQueue.pop();
	}
}

void reset()
{
	while (!bfsQueue.empty())
	{
		bfsQueue.pop();
	}
	for (int i = 0; i< boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			isVisited[i][j] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		reset();
		cin >> boardSize;
		cin >> knightX >> knightY;
		cin >> endX >> endY;
		bfs();
	}

	return 0;
}