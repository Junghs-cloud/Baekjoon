#include <iostream>
using namespace std;

int main()
{
	int N, M, X, T;
	int a, b;
	cin >> N >> M >> X;
	int** arr = new int*[N + 1];
	bool* isVisited = new bool[N + 1];
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
				arr[i][j] = 99999999;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> T;
		arr[a][b] = T;
	}
	

	return 0;
}