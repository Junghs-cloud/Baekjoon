#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	int** arr = new int* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int sum = N * M * 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j == 0)
			{
				sum += arr[i][j];
			}
			else
			{
				if (arr[i][j] > arr[i][j - 1])
				{
					sum += arr[i][j]-arr[i][j-1];
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = M-1; j >=0; j--)
		{
			if (j == M - 1)
			{
				sum += arr[i][j];
			}
			else
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					sum += arr[i][j]- arr[i][j+1];
				}
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j == 0)
			{
				sum += arr[j][i];
			}
			else
			{
				if (arr[j][i] > arr[j - 1][i])
				{
					sum += arr[j][i] - arr[j - 1][i];
				}
			}
		}
	}

	for (int i = 0 ; i < M ; i++)
	{
		for (int j = N-1; j >= 0 ; j--)
		{
			if (j == N-1)
			{
				sum += arr[j][i];
			}
			else
			{
				if (arr[j][i] > arr[j + 1][i])
				{
					sum += arr[j][i] - arr[j + 1][i];
				}
			}
		}
	}

	cout << sum << "\n";
	return 0;
}