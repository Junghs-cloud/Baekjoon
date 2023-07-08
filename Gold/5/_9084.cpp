#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		int make;
		cin >> N;
		int* moneys = new int[N];
		for (int i = 0; i < N; i++)
		{
			cin >> moneys[i];
		}
		cin >> make;
		int** arr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[make + 1];
			for (int j = 0; j < make + 1; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i < make + 1; i++)
		{
			if (i % moneys[0] == 0)
			{
				arr[0][i] = 1;
			}
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < make + 1; j++)
			{
				if (j == moneys[i])
				{
					arr[i][j] = arr[i - 1][j] + 1;
				}
				else if (j > moneys[i])
				{
					arr[i][j] = arr[i - 1][j] + arr[i][j - moneys[i]];
				}
				else
				{
					arr[i][j] = arr[i - 1][j];
				}
			}
		}
		cout << arr[N - 1][make] << "\n";
	}
	return 0;
}