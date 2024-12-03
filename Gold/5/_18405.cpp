#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

struct virus
{
	int num;
	int time;
	int x;
	int y;
	virus(int a, int d, int b, int c)
	{
		num = a;
		time = d;
		x = b;
		y = c;
	}
};

struct cmp
{
	bool operator()(virus& v1, virus& v2)
	{
		if (v1.time < v2.time)
		{
			return false;
		}
		else if (v1.time == v2.time)
		{
			if (v1.num < v2.num)
			{
				return false;
			}
			else if (v1.num == v2.num)
			{
				if (v1.x < v2.x)
				{
					return false;
				}
				else if (v1.x == v2.x)
				{
					return v1.y < v2.y;
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
		else
		{
			return true;
		}
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	int S, X,Y;
	cin >> N >> K;
	int** arr = new int*[N];
	priority_queue<virus, vector<virus>, cmp> pq;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] != 0)
			{
				pq.push(virus(arr[i][j], 0, i, j));
			}
		}
	}
	cin >> S >> X >> Y;
	if (S == 0)
	{
		cout << arr[X-1][Y-1] << "\n";
	}
	else
	{
		while (!pq.empty())
		{
			virus v = pq.top();
			for (int i = 0; i < 4; i++)
			{
				int nextX = v.x + dx[i];
				int nextY = v.y + dy[i];
				if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && arr[nextX][nextY] == 0 && v.time < S)
				{
					arr[nextX][nextY] = v.num;
					pq.push(virus(v.num, v.time + 1, nextX, nextY));
				}
			}
			pq.pop();
		}
		cout << arr[X - 1][Y - 1];
	}
	return 0;
}