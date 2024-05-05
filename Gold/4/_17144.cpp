#include <iostream>
using namespace std;
int** arr;
int** delta;
int R, C, T;

void diffuse()
{
	int moveCount = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			delta[i][j] = 0;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] != 0 && arr[i][j] != -1)
			{
				moveCount = 0;
				if (i > 0 && arr[i-1][j] != -1)
				{
					delta[i-1][j] += arr[i][j] / 5;
					moveCount++;
				}
				if (i < R-1 && arr[i+1][j] != -1)
				{
					delta[i+1][j] += arr[i][j] / 5;
					moveCount++;
				}
				if (j > 0 && arr[i][j - 1] != -1)
				{
					delta[i][j - 1] += arr[i][j] / 5;
					moveCount++;
				}
				if (j < C-1 && arr[i][j + 1] != -1)
				{
					delta[i][j + 1] += arr[i][j] / 5;
					moveCount++;
				}
				delta[i][j] -= arr[i][j] / 5 * moveCount;
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			arr[i][j] += delta[i][j];
			delta[i][j] = arr[i][j];
		}
	}
}

void upWind(int x)
{
	arr[x][1] = 0;
	for (int j = 2; j < C; j++)
	{
		arr[x][j] = delta[x][j-1];
	}
	for (int i = x-1; i >= 0; i--)
	{
		arr[i][C-1] = delta[i + 1][C-1];
	}
	for (int j = C - 2; j >= 0; j--)
	{
		arr[0][j] = delta[0][j+1];
	}
	for (int i = 1; i < x; i++)
	{
		arr[i][0] = delta[i - 1][0];
	}
}


void downWind(int x)
{
	arr[x][1] = 0;
	for (int j = 2; j < C; j++)
	{
		arr[x][j] = delta[x][j-1];
	}
	for (int i = x+1; i < R; i++)
	{
		arr[i][C - 1] = delta[i - 1][C - 1];
	}
	for (int j = C - 2; j >= 0; j--)
	{
		arr[R-1][j] = delta[R-1][j + 1];
	}
	for (int i = R - 2; i > x; i--)
	{
		arr[i][0] = delta[i+1][0];
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int upWindPos = -1;
	int downWindPos = -1;
	long long answer = 0;
	cin >> R >>C >> T;
	arr = new int*[R];
	delta = new int* [R];
	for (int i = 0; i < R; i++)
	{
		arr[i] = new int[C];
		delta[i] = new int[C];
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			delta[i][j] = 0;
			if (arr[i][j] == -1 && upWindPos == -1)
			{
				upWindPos = i;
			}
			else if (arr[i][j] == -1)
			{
				downWindPos = i;
			}
		}
	}
	for (int t = 0; t < T; t++)
	{
		diffuse();
		upWind(upWindPos);
		downWind(downWindPos);
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] != -1)
			{
				answer += arr[i][j];
			}
		}
	}
	cout << answer << "\n";
	return 0;
}