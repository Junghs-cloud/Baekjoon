#include <iostream>
using namespace std;
bool** map;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int countBorder(int i, int j)
{
	int count = 0;
	for (int k = 0; k < 4; k++)
	{
		int nextX = i + dx[k];
		int nextY = j + dy[k];
		if ((nextX < 0 || nextY < 0 || nextX >= 100 || nextY >= 100) || map[nextX][nextY] == false)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map = new bool*[101];
	int answer = 0;
	for (int i = 0; i < 101; i++)
	{
		map[i] = new bool[101];
		for (int j = 0; j < 101; j++)
		{
			map[i][j]=false;
		}
	}
	int N, x, y;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				map[j][k] = true;
			}
		}
	}
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] == true)
			{
				answer += countBorder(i, j);
			}
		}
	}
	cout << answer << "\n";
	return 0;
}