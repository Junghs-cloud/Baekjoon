#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, R;
	int a, b, length;
	cin >> N>>M>>R;
	int* items = new int[N+1];
	int** arr = new int*[N+1];
	for (int i = 0; i < N+ 1; i++)
	{
		arr[i] = new int[N+1];
		for (int j = 0; j < N + 1; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 9999999;
			}
		}
	}
	items[0] = 0;
	for (int i = 1; i < N+1; i++)
	{
		cin >> items[i];
	}
	for (int i = 0; i < R; i++)
	{
		cin >> a >> b >> length;
		arr[a][b] = length;
		arr[b][a] = length;
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
	int maxCount = 0;
	for (int i = 1; i < N + 1; i++)
	{
		int currentCount = 0;
		for (int j = 1; j < N + 1; j++)
		{
			if (arr[i][j] <= M)
			{
				currentCount += items[j];
			}
		}
		if (currentCount > maxCount)
		{
			maxCount = currentCount;
		}
	}
	cout << maxCount << "\n";
	return 0;
}