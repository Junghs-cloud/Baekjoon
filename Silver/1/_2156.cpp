#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int** sum = new int*[N];
	int maxJuice = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum[i] = new int[2];
	}
	sum[0][0] = arr[0];
	sum[0][1] = arr[0];
	if (N >= 2)
	{
		sum[1][0] = arr[1];
		sum[1][1] = arr[1] + arr[0];
		for (int i = 2; i < N; i++)
		{
			sum[i][0] = 0;
			for (int j = 0; j <= i - 2; j++)
			{	
				if (sum[j][0] + arr[i] > sum[i][0])
				{
					sum[i][0] = sum[j][0] + arr[i];
				}
				if (sum[j][1] + arr[i] > sum[i][0])
				{
					sum[i][0] = sum[j][1] + arr[i];
				}
			}
			sum[i][1] = sum[i - 1][0] + arr[i];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (sum[i][j] > maxJuice)
			{
				maxJuice = sum[i][j];
			}
		}
	}
	cout << maxJuice << "\n";
	return 0;
}