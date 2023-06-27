#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b, cost;
	cin >> N;
	int** arr = new int*[N + 1];
	bool* isVisited = new bool[N + 1];
	cin >> M;
	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[N + 1];
		isVisited[i] = false;
		for (int j = 0; j < N + 1; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 999999999;
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
	cin >> a >> b;
	isVisited[a] = true;
	arr[a][a] = 0;
	for (int loop = 1; loop <= N-1; loop++)
	{
		int min = 999999999;
		int index = 0;
		for (int i = 1; i < N + 1; i++)
		{
			if (isVisited[i] == false && arr[a][i] < min)
			{
				min = arr[a][i];
				index = i;
			}
		}
		isVisited[index] = true;
		for (int i = 1; i < N + 1; i++)
		{
			if (arr[a][i] > arr[a][index] + arr[index][i])
			{
				arr[a][i] = arr[a][index] + arr[index][i];
			}
		}
	}
	cout << arr[a][b] << "\n";
	return 0;
}