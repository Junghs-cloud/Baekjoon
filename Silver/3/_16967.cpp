#include <iostream>
using namespace std;
int H, W, X, Y;

bool isInOrigin(int i, int j)
{
	if (i >= 0 && i < H && j >= 0 && j < W)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isInMoved(int i, int j)
{
	if (i-X >= 0 && i-X < H && j- Y >= 0 && j-Y < W)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> H >> W >> X >> Y;
	int** B = new int*[H + X];
	int** A = new int*[H];
	for (int i = 0; i < H; i++)
	{
		A[i] = new int[W];
		for (int j = 0; j < W; j++)
		{
			A[i][j] = 0;
		}
	}
	for (int i = 0; i < H + X; i++)
	{
		B[i] = new int[W + Y];
		for (int j = 0; j < W + Y; j++)
		{
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < H + X; i++)
	{
		for (int j = 0; j < W + Y; j++)
		{
			if (isInOrigin(i, j) && isInMoved(i, j))
			{
				A[i][j] = B[i][j] - A[i- X][j - Y];
			}
			else if (isInOrigin(i, j))
			{
				A[i][j] = B[i][j];
			}
			else if (isInMoved(i, j))
			{
				A[i - X][j - Y] = B[i][j];
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << A[i][j]<<" ";
		}
		cout << "\n";
	}
	return 0;
}