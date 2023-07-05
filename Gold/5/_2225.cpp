#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	long long** arr = new long long*[K+1];
	for (int i = 0; i < K + 1; i++)
	{
		arr[i] = new long long[N+1];
		for (int j = 0; j < N + 1; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N + 1; i++)
	{
		arr[0][i] = 0;
		arr[1][i] = 1;
		if (K >= 2)
		{
			arr[2][i] = i + 1;
		}
	}
	for (int i = 3; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				arr[i][j] = arr[i][j] % 1000000000 + arr[i - 1][k] % 1000000000;
				arr[i][j] = arr[i][j] % 1000000000;
			}
		}
	}
	cout << arr[K][N] << "\n";
	return 0;
}