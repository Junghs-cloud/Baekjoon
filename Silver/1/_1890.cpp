#include <iostream>
using namespace std;

int main()
{
	int N, M, Q;
	int r1, r2, c1, c2;
	cin >> N >> M>>Q;
	int** arr = new int*[N];
	int** sum = new int* [N + 1];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N + 1; i++)
	{
		sum[i] = new int[M + 1];
		for (int j = 0; j < M + 1; j++)
		{
			if (i == 0 || j == 0)
			{
				sum[i][j] = 0;
			}
			else
			{
				sum[i][j] = arr[i-1][j-1];
			}
		}
	}
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = 0; i < N+1; i++)
	{
		for (int j = 1; j < M+1; j++)
		{
			sum[i][j] += sum[i][j - 1];
		}
	}
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 0; j < M+1; j++)
		{
			sum[i][j] += sum[i-1][j];
		}
	}
	for (int i = 0; i < N+1; i++)
	{
		for (int j = 0; j < M+1; j++)
		{
			cout << sum[i][j] << " ";
		}
		cout << "\n";
	}
	int answer = sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1][c1];
	int part = r2 * c2 - ((r1 - 1) * c2) - (r2 * (c1 - 1)) + r1 * c1;
	cout << answer / part << "\n";
	return 0;
}