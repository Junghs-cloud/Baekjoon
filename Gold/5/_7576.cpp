#include <iostream>
#include <queue>

using namespace std;

struct tomato
{
	int i;
	int j;
	int currentDay;
	tomato(int a, int b, int c)
	{
		i = a;
		j = b;
		currentDay = c;
	}
};

queue<tomato> bfsQueue;
int** box;
bool** isVisited;
int M, N;
int currentDays = 0;

void bfs()
{
	int i, j;
	while (!bfsQueue.empty())
	{
		tomato currentFront = bfsQueue.front();
		currentDays = currentFront.currentDay;
		i = currentFront.i;
		j = currentFront.j;
		box[i][j] = 1;
		isVisited[i][j] = true;
		if (i > 0)
		{
			if (box[i - 1][j] == 0 && isVisited[i - 1][j]==false)
			{
				box[i - 1][j] = 1;
				isVisited[i-1][j] = true;
				bfsQueue.push(tomato(i - 1, j, currentDays + 1));
			}
		}
		if (i < N - 1)
		{
			if (box[i + 1][j] == 0 && isVisited[i + 1][j] == false)
			{
				box[i+1][j] = 1;
				isVisited[i+1][j] = true;
				bfsQueue.push(tomato(i + 1, j, currentDays + 1));
			}
		}
		if (j > 0)
		{
			if (box[i][j - 1] == 0 && isVisited[i][j - 1] == false)
			{
				box[i][j-1] = 1;
				isVisited[i][j-1] = true;
				bfsQueue.push(tomato(i, j - 1, currentDays + 1));
			}
		}
		if (j < M - 1)
		{
			if (box[i][j + 1] == 0 && isVisited[i][j + 1] == false)
			{
				box[i][j+1] = 1;
				isVisited[i][j+1] = true;
				bfsQueue.push(tomato(i, j + 1, currentDays + 1));
			}
		}
		bfsQueue.pop();
	}
}

bool canRipeAll()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isVisited[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

void findDays()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == -1)
			{
				isVisited[i][j] = true;
			}
			if (box[i][j] == 1 && isVisited[i][j]==false)
			{
				bfsQueue.push(tomato(i, j, 0));
			}
		}
	}
	bfs();
}

int main()
{
	cin >> M >> N;
	box = new int* [N];
	isVisited = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		box[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
			isVisited[i][j] = false;
		}
	}
	findDays();
	if (!canRipeAll())
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << currentDays << "\n";
	}
	return 0;
}