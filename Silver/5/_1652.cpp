#include <iostream>
#include <string>
#include <stack>
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

stack<pos> position;
int N;
char** arr;
bool** isVisited;
int garo = 0;
int sero = 0;

void dfsGaro(int i, int j)
{
	position.push(pos(i, j, 1));
	isVisited[i][j] = true;
	while (!position.empty())
	{
		pos currentPos = position.top();
		int currentI = currentPos.i;
		int currentJ = currentPos.j;
		int currentLength = currentPos.length;
		if (currentJ < N - 1 && isVisited[currentI][currentJ + 1]==false && arr[currentI][currentJ+1] == '.')
		{
			position.push(pos(currentI, currentJ+1, currentLength+1));
			isVisited[currentI][currentJ + 1] = true;
		}
		else
		{
			if (currentLength >= 2)
			{
				garo++;
			}
			while (!position.empty())
			{
				position.pop();
			}
		}

	}
}

void dfsSero(int i, int j)
{
	position.push(pos(i, j, 1));
	isVisited[i][j] = true;
	while (!position.empty())
	{
		pos currentPos = position.top();
		int currentI = currentPos.i;
		int currentJ = currentPos.j;
		int currentLength = currentPos.length;
		if (currentI < N - 1 && isVisited[currentI + 1][currentJ] == false && arr[currentI + 1][currentJ] == '.')
		{
			position.push(pos(currentI + 1, currentJ, currentLength + 1));
			isVisited[currentI + 1][currentJ] = true;
		}
		else
		{
			if (currentLength >= 2)
			{
				sero++;
			}
			while (!position.empty())
			{
				position.pop();
			}
		}

	}
}

int main()
{
	int length = 0;

	string line;
	cin >> N;
	arr = new char*[N];
	isVisited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[N];
		isVisited[i] = new bool[N];
		cin >> line;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = line[j];
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j] == false && arr[i][j] == '.')
			{
				dfsGaro(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			isVisited[i][j] = false;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j]==false && arr[i][j] == '.')
			{
				dfsSero(i, j);
			}
		}
	}
	cout << garo<<" "<<sero << "\n";
	return 0;
}