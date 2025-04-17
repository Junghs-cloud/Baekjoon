#include <iostream>
#include <utility>
using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int N;
pair<char, bool>** arr;
int getMineCount(int x, int y)
{
	int adjMine = 0;
	for (int i = 0; i < 8; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && arr[nextX][nextY].first == '*')
		{
			adjMine++;
		}
	}
	return adjMine;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool isGameOver = false;
	char c;
	cin >> N;
	arr = new pair<char, bool>*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new pair<char, bool>[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j].first;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			if (c == '.')
			{
				arr[i][j].second = false;
			}
			else
			{
				arr[i][j].second = true;
				if (arr[i][j].first == '*')
				{
					isGameOver = true;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j].second == true)
			{
				if (arr[i][j].first == '.')
				{
					cout << getMineCount(i, j);
				}
				else if (arr[i][j].first == '*' && isGameOver == true)
				{
					cout << "*";
				}
				else
				{
					cout << ".";
				}
			}
			else
			{
				if (arr[i][j].first == '*' && isGameOver == true)
				{
					cout << "*";
				}
				else
				{
					cout << ".";
				}
			}
		}
		cout << "\n";
	}
	return 0;
}