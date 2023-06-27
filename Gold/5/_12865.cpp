#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N, K;
	int W, V;
	cin >> N >> K;
	int** arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[K+1];
		cin >> W >> V;
		if (i == 0)
		{
			for (int j = 0; j < K + 1; j++)
			{
				if (j < W)
				{
					arr[i][j] = 0;
				}
				else
				{
					arr[i][j] = V;
				}
			}
		}
		else
		{
			for (int j = 0; j < K + 1; j++)
			{
				arr[i][j] = arr[i - 1][j];
				if (j == W)
				{
					arr[i][j] = max(arr[i - 1][j], V);
				}
				else if (j > W)
				{
					arr[i][j] = max(arr[i - 1][j], V + arr[i - 1][j - W]);
				}
			}
		}
	}
	cout << arr[N - 1][K] << "\n";
	return 0;
}