#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int** arr = new int*[N];
	int** costSum = new int* [N];
	int costMin = 99999999;

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[3];
		costSum[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		costSum[0][i] = arr[0][i];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			costSum[i][j] = 0;
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int temp1;
			int temp2;
			if (j == 0)
			{
				costSum[i][1] = costSum[i - 1][j] + arr[i][1];
				costSum[i][2] = costSum[i - 1][j] + arr[i][2];
			}
			else if (j == 1)
			{
				costSum[i][0] = costSum[i - 1][j] + arr[i][0];
				temp2 = costSum[i - 1][j] + arr[i][2];

				costSum[i][2] = min(costSum[i][2], temp2);
			}
			else
			{
				temp1 = costSum[i - 1][j] + arr[i][0];
				temp2 = costSum[i - 1][j] + arr[i][1];

				costSum[i][0] = min(costSum[i][0], temp1);
				costSum[i][1] = min(costSum[i][1], temp2);
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (costSum[N - 1][i] < costMin)
		{
			costMin = costSum[N - 1][i];
		}
	}
	cout << costMin<<"\n";
	return 0;
}