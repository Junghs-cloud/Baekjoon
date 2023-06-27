#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct pos
{
	int x;
	int y;
	pos(int a, int b)
	{
		x = a;
		y = b;
	}
};

queue<pos> bfsQueue;
int N;
int safeCount = 0;
int** arr;
bool** isVisited;
vector<int> safeCountVector;

void bfs(pos startPos, int height)
{
	int i;
	int j;
	bfsQueue.push(startPos);
	isVisited[startPos.x][startPos.y] = true;
	while (!bfsQueue.empty())
	{
		pos currentFront = bfsQueue.front();
		i = currentFront.x;
		j = currentFront.y;
		if ((i > 0) && (arr[i - 1][j] > height) && (isVisited[i - 1][j]==false))
		{
			isVisited[i- 1][j] = true;
			bfsQueue.push(pos(i - 1, j));
		}
		if (i < N - 1 && arr[i + 1][j]> height && isVisited[i + 1][j] == false)
		{
			isVisited[i + 1][j] = true;
			bfsQueue.push(pos(i + 1, j));
		}
		if (j > 0 && arr[i][j - 1] > height && isVisited[i][j - 1] == false)
		{
			isVisited[i][j- 1] = true;
			bfsQueue.push(pos(i, j - 1));
		}
		if (j < N- 1 && arr[i][j + 1] > height && isVisited[i][j + 1] == false)
		{
			isVisited[i][j+ 1] = true;
			bfsQueue.push(pos(i, j + 1));
		}
		bfsQueue.pop();
	}
}

void searchInHeight(int height)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j] == false && arr[i][j]> height)
			{
				isVisited[i][j] = true;
				bfs(pos(i, j), height);
				safeCount++;
			}
		}
	}
	safeCountVector.push_back(safeCount);
}

void reset()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			isVisited[i][j] = false;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int min;
	int max;
	cin >> N;
	arr = new int*[N];
	isVisited = new bool*[N];
	for (int i = 0;i < N; i++)
	{
		arr[i] = new int[N];
		isVisited[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			isVisited[i][j] = false;
		}
	}
	min = arr[0][0];
	max = arr[0][0];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}

	for (int i = min - 1; i <= max; i++)
	{
		safeCount = 0;
		searchInHeight(i);
		reset();
	}
	sort(safeCountVector.begin(), safeCountVector.end());
	cout << safeCountVector.at(safeCountVector.size() - 1)<<"\n";
	return 0;
}