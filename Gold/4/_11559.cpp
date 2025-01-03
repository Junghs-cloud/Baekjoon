#include <iostream>
#include <queue>
using namespace std;
char** board;
bool** isVisited;
queue<pair<int, int>> bfsQueue;
queue<pair<int, int>> tempQueue;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
bool isStateChanged;

void bfs(int x, int y)
{
	int colorCount = 0;
	char color = board[x][y];
	bfsQueue.push(pair(x, y));
	while (!bfsQueue.empty())
	{
		pair<int, int> current = bfsQueue.front();
		for (int i = 0; i < 4; i++)
		{
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < 12 && nextY >= 0 && nextY < 6 && isVisited[nextX][nextY] == false && board[nextX][nextY] == color)
			{
				isVisited[nextX][nextY] = true;
				colorCount++;
				bfsQueue.push(pair(nextX, nextY));
			}
		}
		bfsQueue.pop();
		tempQueue.push(current);
	}
	if (colorCount >= 4)
	{
		while (!tempQueue.empty())
		{
			pair<int, int> front = tempQueue.front();
			board[front.first][front.second] = '.';
			tempQueue.pop();
		}
		isStateChanged = true;
		
	}
	else
	{
		while (!tempQueue.empty())
		{
			pair<int, int> front = tempQueue.front();
			tempQueue.pop();
		}
	}
}

void reset()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			isVisited[i][j] = false;
		}
	}
}

int findGround(int colNum)
{
	for (int i = 11; i >= 0; i--)
	{
		if (board[i][colNum] == '.')
		{
			return i;
		}
	}
	return -1;
}

void moveToGround()
{
	for (int i = 10; i >= 0; i--)
	{
		for (int j = 0; j < 6; j++)
		{
			if (board[i][j] != '.' && board[i + 1][j] == '.')
			{
				int groundIndex = findGround(j);
				board[groundIndex][j] = board[i][j];
				board[i][j] = '.';
			}
		}
	}
}

int main()
{
	board = new char*[12];
	isVisited = new bool*[12];
	isStateChanged = true;
	int chainCount = 0;
	for (int i = 0; i < 12; i++)
	{
		isVisited[i] = new bool[6];
		board[i] = new char[6];
		for (int j = 0; j < 6; j++)
		{
			cin >> board[i][j];
			isVisited[i][j] = false;
		}
	}
	while (true)
	{
		isStateChanged = false;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (board[i][j] != '.')
				{
					bfs(i, j);
				}
			}
		}
		reset();
		moveToGround();
		if (isStateChanged == false)
		{
			break;
		}
		else
		{
			chainCount++;
		}
	}
	cout << chainCount << "\n";
	return 0;
}