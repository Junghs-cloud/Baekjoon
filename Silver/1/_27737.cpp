#include <iostream>
#include <stack>

using namespace std;
bool** isVisited;
int** arr;
int N, M, K;
int useMushroom = 0;
struct pos
{
	int x = 0;
	int y = 0;
	pos(int a, int b)
	{
		x = a;
		y = b;
	}
};

stack<pos> posStack;
void dfs(int i, int j)
{
	posStack.push(pos(i, j));
	isVisited[i][j] = true;
	int mushroomCount = 0;
	while (!posStack.empty())
	{
		pos currentPos = posStack.top();
		bool isAdjacent = false;
		
		if (currentPos.x > 0 && arr[currentPos.x - 1][currentPos.y] == 0 && isVisited[currentPos.x - 1][currentPos.y]== false)
		{
			if (isAdjacent == false)
			{
				isAdjacent = true;
				isVisited[currentPos.x - 1][currentPos.y] = true;
				posStack.push(pos(currentPos.x - 1, currentPos.y));
			}
		}
		if (currentPos.x < N - 1 && arr[currentPos.x + 1][currentPos.y] == 0 && isVisited[currentPos.x + 1][currentPos.y] == false)
		{
			if (isAdjacent == false)
			{
				isAdjacent = true;
				isVisited[currentPos.x + 1][currentPos.y] = true;
				posStack.push(pos(currentPos.x + 1, currentPos.y));
			}
		}
		if (currentPos.y > 0 && arr[currentPos.x][currentPos.y - 1] == 0 && isVisited[currentPos.x][currentPos.y - 1] == false)
		{
			if (isAdjacent == false)
			{
				isAdjacent = true;
				isVisited[currentPos.x][currentPos.y - 1] = true;
				posStack.push(pos(currentPos.x, currentPos.y - 1));
			}
		}
		if (currentPos.y < N - 1 && arr[currentPos.x][currentPos.y + 1] == 0 && isVisited[currentPos.x][currentPos.y + 1] == false)
		{
			if (isAdjacent == false)
			{
				isAdjacent = true;
				isVisited[currentPos.x][currentPos.y + 1] = true;
				posStack.push(pos(currentPos.x, currentPos.y + 1));
			}
		}
		if (isAdjacent == false)
		{
			mushroomCount++;
			posStack.pop();
		}
	}
	if (mushroomCount % K == 0)
	{
		useMushroom += (mushroomCount / K);
	}
	else
	{
		useMushroom += (mushroomCount / K) + 1;
	}
}

int main()
{
	cin >> N >> M >> K;
	arr = new int*[N];
	isVisited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		isVisited[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			isVisited[i][j] = false;
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j] == false && arr[i][j] == 0)
			{
				dfs(i, j);
			}
		}
	}
	if (useMushroom == 0)
	{
		cout << "IMPOSSIBLE" << "\n";
	}
	else if (useMushroom <= M)
	{
		cout << "POSSIBLE" << "\n";
		cout << M - useMushroom << "\n";
	}
	else
	{
		cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}