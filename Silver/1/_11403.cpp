#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (arr[j][i] == 1 && arr[i][k] == 1)
				{
					arr[j][k] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}