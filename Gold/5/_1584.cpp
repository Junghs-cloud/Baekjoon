#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

struct info
{
	int x;
	int y;
	int life;
	info(int a, int b, int c)
	{
		x = a;
		y = b;
		life = c;
	}
};

struct cmp
{
	bool operator()(info& i1, info& i2)
	{
		if (i1.life > i2.life)
		{
			return false;
		}
		else if (i1.life == i2.life)
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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int** map = new int*[501];
	int** life = new int*[501];
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < 501; i++)
	{
		map[i] = new int[501];
		life[i] = new int[501];
		for (int j = 0; j < 501; j++)
		{
			map[i][j] = 0;
			life[i][j] = INF;
		}
	}
	life[0][0] = 1000;
	int N, M;
	int x1, x2, y1, y2;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = min(x1, x2); i <= max(x1, x2); i++)
		{
			for (int j = min(y1, y2); j <= max(y1, y2); j++)
			{
				map[i][j] = -1;
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = min(x1, x2); i <= max(x1, x2); i++)
		{
			for (int j = min(y1, y2); j <= max(y1, y2); j++)
			{
				map[i][j] = -2;
			}
		}
	}
	pq.push(info(0, 0, 1000));
	while (!pq.empty())
	{
		info current = pq.top();
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextX = current.x + dx[i];
			int nextY = current.y + dy[i];
			if (nextX >= 0 && nextX <= 500 && nextY >= 0 && nextY <= 500 && map[nextX][nextY] != -2)
			{
				if (map[nextX][nextY] == -1 && (current.life - 1 > life[nextX][nextY] || life[nextX][nextY]== INF))
				{
					life[nextX][nextY] = current.life - 1;
					pq.push(info(nextX, nextY, current.life - 1));
				}
				else if (map[nextX][nextY]==0 && (current.life > life[nextX][nextY] || life[nextX][nextY] == INF))
				{
					life[nextX][nextY] = current.life;
					pq.push(info(nextX, nextY, current.life));
				}
			}
		}
	}
	if (life[500][500] == INF)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << 1000 - life[500][500] << "\n";
	}
	return 0;
}