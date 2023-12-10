#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int** arr;
int N, M;
pair<bool, int>** isVisited;
vector<pair<int, int>> v;
int cctvNum;
int minCount = 64;

void searchUp(int x, int y, int depth)
{
	x--;
	while (x >= 0 && arr[x][y] != 6)
	{
		isVisited[x][y].first = true;
		if (isVisited[x][y].second == -1)
		{
			isVisited[x][y].second = depth;
		}
		x--;
	}
}

void searchRight(int x, int y, int depth)
{
	y++;
	while (y <= M - 1 && arr[x][y] != 6)
	{
		isVisited[x][y].first = true;
		if (isVisited[x][y].second == -1)
		{
			isVisited[x][y].second = depth;
		}
		y++;
	}
}

void searchDown(int x, int y, int depth)
{
	x++;
	while (x <= N-1 && arr[x][y] != 6)
	{
		isVisited[x][y].first = true;
		if (isVisited[x][y].second == -1)
		{
			isVisited[x][y].second = depth;
		}
		x++;
	}
}

void searchLeft(int x, int y, int depth)
{
	y--;
	while (y >= 0 && arr[x][y] != 6)
	{
		isVisited[x][y].first = true;
		if (isVisited[x][y].second == -1)
		{
			isVisited[x][y].second = depth;
		}
		y--;
	}
}

void fillArr(int x, int y, int cctv, string dir, int depth)
{
	if (cctv == 1)
	{
		if (dir == "up")
		{
			searchUp(x, y, depth);
		}
		else if (dir == "right")
		{
			searchRight(x, y, depth);
		}
		else if (dir == "down")
		{
			searchDown(x, y, depth);
		}
		else
		{
			searchLeft(x, y, depth);
		}
	}
	else if (cctv == 2)
	{
		if (dir == "up" || dir=="down")
		{
			searchUp(x, y, depth);
			searchDown(x, y, depth);
		}
		else
		{
			searchRight(x, y, depth);
			searchLeft(x, y, depth);
		}
	}
	else if (cctv == 3)
	{
		if (dir == "up")
		{
			searchUp(x, y, depth);
			searchRight(x, y, depth);
		}
		else if (dir == "right")
		{
			searchRight(x, y, depth);
			searchDown(x, y, depth);
		}
		else if (dir == "down")
		{
			searchDown(x, y, depth);
			searchLeft(x, y, depth);
		}
		else
		{
			searchLeft(x, y, depth);
			searchUp(x, y, depth);
		}
	}
	else if (cctv == 4)
	{
		if (dir == "up")
		{
			searchUp(x, y, depth);
			searchRight(x, y, depth);
			searchLeft(x, y, depth);
		}
		else if (dir == "right")
		{
			searchRight(x, y, depth);
			searchDown(x, y, depth);
			searchUp(x, y, depth);
		}
		else if (dir == "down")
		{
			searchDown(x, y, depth);
			searchLeft(x, y, depth);
			searchRight(x, y, depth);
		}
		else
		{
			searchLeft(x, y, depth);
			searchUp(x, y, depth);
			searchDown(x, y, depth);
		}
	}
	else
	{
		searchUp(x, y, depth);
		searchRight(x, y, depth);
		searchDown(x, y, depth);
		searchLeft(x, y, depth);
	}
}

void reset(int depth)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isVisited[i][j].first == true && isVisited[i][j].second == depth)
			{
				isVisited[i][j].first = false;
				isVisited[i][j].second = -1;
			}
		}
	}
}

void backTracking(int depth)
{
	if (depth == cctvNum)
	{
		int currentCount = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j]==0 && isVisited[i][j].first == false)
				{
					currentCount++;
				}
			}
		}
		if (currentCount < minCount)
		{
			minCount = currentCount;
		}
		return;
	}
	else
	{
		int currentX = v.at(depth).first;
		int currentY = v.at(depth).second;
		if (arr[currentX][currentY] != 0 && arr[currentX][currentY]!=6)
		{
			fillArr(currentX, currentY, arr[currentX][currentY], "up", depth);
			backTracking(depth + 1);
			reset(depth);
			fillArr(currentX, currentY, arr[currentX][currentY], "right", depth);
			backTracking(depth + 1);
			reset(depth);
			fillArr(currentX, currentY, arr[currentX][currentY], "down", depth);
			backTracking(depth + 1);
			reset(depth);
			fillArr(currentX, currentY, arr[currentX][currentY], "left", depth);
			backTracking(depth + 1);
			reset(depth);
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new int*[N];
	isVisited = new pair<bool, int>*[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		isVisited[i] = new pair<bool, int>[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			isVisited[i][j] = make_pair(false, -1);
			if (arr[i][j] != 0 && arr[i][j] != 6)
			{
				cctvNum++;
				isVisited[i][j].first = true;
				v.push_back(make_pair(i, j));
			}
			else if (arr[i][j] == 6)
			{
				isVisited[i][j].first = true;
			}
		}
	}
	backTracking(0);
	cout << minCount << "\n";
	return 0;
}