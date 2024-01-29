#include <iostream>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int** arr = new int*[N+1];
	if (K == 0)
	{
		cout << 1 << "\n";
	}
	else
	{
		for (int i = 0; i < N + 1; i++)
		{
			arr[i] = new int[i + 1];
			for (int j = 0; j < i + 1; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 1; i < N + 1; i++)
		{
			arr[i][0] = 1;
			arr[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
		cout << arr[N][K] << "\n";
	}
	return 0;
}