#include <iostream>
#include <stack>
#include <utility>
using namespace std;
char** arr;

int minAnswer;
int maxAnswer;
int N;

int dx[] = { 0, 2, 1, 1 };
int dy[] = { 2, 0, 1 , 1};
int opDx[] = { 0, 1, 1, 0 };
int opDy[] = { 1, 0, 0, 1 };

int calc(int x, int y, char op)
{
	if (op == '+')
	{
		return x + y;
	}
	if (op == '-')
	{
		return x - y;
	}
	return x * y;
}

void dfs(int x, int y, int value)
{
	if (x == N-1 && y == N-1)
	{
		maxAnswer = max(value, maxAnswer);
		minAnswer = min(value, minAnswer);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			int opX = x + opDx[i];
			int opY = y + opDy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
			{
				int calcuatedValue = calc(value, arr[nextX][nextY] - 48, arr[opX][opY]);
				dfs(nextX, nextY, calcuatedValue);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new char* [N];
	minAnswer = 123456789;
	maxAnswer = -123456789;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, arr[0][0] - 48);
	cout << maxAnswer << " " << minAnswer << "\n";
	return 0;
}