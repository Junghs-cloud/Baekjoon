#include <iostream>
#include <queue>
using namespace std;
int** arr;
bool* isVisited;

struct info
{
	int index;
	int depth;
	info(int a, int b)
	{
		index = a;
		depth = b;
	}
};

queue<info> bfsQueue;

bool checkFriend(int index)
{
	for (int i = 1; i < 13; i++)
	{
		if (arr[index][i] == 1)
		{
			int friends = 0;
			for (int j = 1; j < 13; j++)
			{
				if (arr[i][j] == 1)
				{
					friends++;
				}
			}
			if (friends == 1)
			{
				return true;
			}
		}
	}
	return false;
}

int bfs(int index)
{
	isVisited[index] = true;
	int maxDepth = 0;
	bfsQueue.push(info(index, 0));
	while (!bfsQueue.empty())
	{
		info current = bfsQueue.front();
		if (current.depth > maxDepth)
		{
			maxDepth = current.depth;
		}
		for (int i = 1; i < 13; i++)
		{
			if (arr[current.index][i] == 1 && isVisited[i] == false)
			{
				isVisited[i] = true;
				bfsQueue.push(info(i, current.depth+1));
			}
		}
		bfsQueue.pop();
	}
	return maxDepth;
}

int main()
{
	int x, y;
	arr = new int*[13];
	isVisited = new bool[13];
	for (int i = 0; i < 13; i++)
	{
		arr[i] = new int[13];
		isVisited[i] = false;
	}
	for (int i = 0; i < 12; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	for (int i = 1; i < 13; i++)
	{
		int linkSize = 0;
		for (int j = 1; j < 13; j++)
		{
			isVisited[j] = false;
			if (arr[i][j] == 1)
			{
				linkSize++;
			}
		}
		if (linkSize == 3)
		{
			int depth = bfs(i);
			bool isSpica = false;
			if (depth == 5)
			{
				isSpica = checkFriend(i);
			}
			if (isSpica == true)
			{
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}