#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, M;
	int* colInput;
	int* rowInput;
	int c = 0;
	int r = 0;
	cin >> N >> M;
	colInput = new int[N];
	rowInput = new int[M];
	bool** isPromising = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		isPromising[i] = new bool[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			isPromising[i][j] = true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cin >> colInput[i];

	}
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (abs(k - i) + j != colInput[k])
				{
					isPromising[i][j] = false;
				}
			}
		}
	}

	for (int i = 1; i < M; i++)
	{
		cin >> rowInput[i];
	}
	for (int k = 1; k < M; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (N-1-i + abs(j-k) != rowInput[k])
				{
					isPromising[i][j] = false;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (isPromising[i][j] == true)
			{
				c = i + 1;
				r = j + 1;
			}
		}
	}
	cout << c << " " << r << "\n";
	return 0;
}