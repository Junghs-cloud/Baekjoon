#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b, cost;
	cin >> N;
	cin >> M;
	int** arr = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[N + 1];
		for (int j = 0; j < N + 1; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 99999999;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> cost;
		if (cost < arr[a][b])
		{
			arr[a][b] = cost;
		}
	}
	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (arr[i][k] + arr[k][j] < arr[i][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (arr[i][j] == 99999999)
			{
				cout << "0" << " ";
			}
			else
			{
				cout << arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}