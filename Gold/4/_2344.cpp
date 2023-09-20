#include <iostream>
using namespace std;
int N, M;
int** arr;

void moveLight(string direction, int i, int j)
{
	if (direction == "up")
	{
		if (i < 0)
		{
			cout << 2 * (M + N) - j << " ";
		}
		else
		{
			for (int x = i; x >= 0; x--)
			{
				if (arr[x][j] == 1)
				{
					moveLight("right", x, j + 1);
					break;
				}
				else
				{
					if (x == 0)
					{
						cout << 2 * (M + N) - j << " ";
					}
				}
			}
		}
	}
	else if (direction == "right")
	{
		if (j >= M)
		{
			cout << 2 * N + M - i << " ";
		}
		else
		{
			for (int y = j; y < M; y++)
			{
				if (arr[i][y] == 1)
				{
					moveLight("up", i - 1, y);
					break;
				}
				else
				{
					if (y == M-1)
					{
						cout << 2 * N + M - i << " ";
					}
				}
			}
		}
	}
	else if (direction == "left")
	{
		if (j < 0)
		{
			cout << i + 1 << " ";
		}
		else
		{
			for (int y = j; y >= 0; y--)
			{
				if (arr[i][y] == 1)
				{
					moveLight("down", i + 1, y);
					break;
				}
				else
				{
					if (y == 0)
					{
						cout << i + 1 << " ";
					}
				}
			}
		}
	}
	else
	{
		if (i == N)
		{
			cout << N + 1 + j << " ";
		}
		else
		{
			for (int x = i; x < N; x++)
			{
				if (arr[x][j] == 1)
				{
					moveLight("left", x, j - 1);
					break;
				}
				else
				{
					if (x == N - 1)
					{
						cout << N + 1 + j << " ";
					}
				}
			}
		}
	}

}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N>>M;
	arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		moveLight("right", i, 0);
	}
	for (int j = 0; j < M; j++)
	{
		moveLight("up", N - 1, j);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		moveLight("left", i, M - 1);
	}
	for (int j = M - 1; j >= 0; j--)
	{
		moveLight("down", 0, j);
	}

	return 0;
}