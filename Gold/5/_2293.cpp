#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int* moneys = new int[N];
	int** arr = new int*[2];
	for (int i = 0; i < 2; i++)
	{
		arr[i] = new int[K + 1];
		for (int j = 0; j < K + 1; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0;i < N; i++)
	{
		cin >> moneys[i];
	}
	for (int i = 1; i < K+1; i++)
	{
		if (i % moneys[0] == 0)
		{
			arr[0][i] = 1;
			arr[1][i] = 1;
		}
		else
		{
			arr[0][i] = 0;
			arr[1][i] = 0;
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < K + 1; j++)
		{
			if (j == moneys[i])
			{
				arr[1][j] = arr[0][j] + 1;
			}
			else if (j > moneys[i])
			{
				arr[1][j] = arr[0][j] + arr[1][j-moneys[i]];
			}
			else
			{
				arr[1][j] = arr[0][j];
			}
		}
		for (int j = 0; j < K + 1; j++)
		{
			arr[0][j] = arr[1][j];
		}
	}
	cout << arr[1][K] << "\n";
	return 0;
}