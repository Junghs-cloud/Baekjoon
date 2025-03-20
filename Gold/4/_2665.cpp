#include <iostream>
#include <queue>
#define MAX 123456789
using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int** arr;
int** minCount;
int N;

struct info
{
	int x;
	int y;
	int changeCount;
	info(int a, int b, int c)
	{
		x = a;
		y = b;
		changeCount = c;
	}
};

struct cmp
{
	bool operator()(info& i1, info& i2)
	{
		if (i1.changeCount < i2.changeCount)
		{
			return false;
		}
		else if (i1.changeCount == i2.changeCount)
		{
			if (i1.x > i2.x)
			{
				return false;
			}
			else if (i1.x == i2.x)
			{
				return i1.y < i2.y;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
};

priority_queue<info, vector<info>, cmp> pq;

void dijkstra()
{

	pq.push(info(0, 0, 0));
	minCount[0][0] = 0;
	while (!pq.empty())
	{
		info top = pq.top();
		pq.pop();
		if (top.changeCount > minCount[top.x][top.y])
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextX = top.x + dx[i];
			int nextY = top.y + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
			{
				if (arr[nextX][nextY] == 1 && top.changeCount < minCount[nextX][nextY])
				{
					pq.push(info(nextX, nextY, top.changeCount));
					minCount[nextX][nextY] = top.changeCount;
				}
				else if (arr[nextX][nextY]==0 && top.changeCount+1 < minCount[nextX][nextY])
				{
					pq.push(info(nextX, nextY, top.changeCount+1));
					minCount[nextX][nextY] = top.changeCount+1;
				}
			}
		}
	}
	cout << minCount[N - 1][N - 1] << "\n";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char c;
	cin >> N;
	arr = new int*[N];
	minCount = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		minCount[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			arr[i][j] = c - 48;
			minCount[i][j] = MAX;
		}
	}
	dijkstra();
	return 0;
}