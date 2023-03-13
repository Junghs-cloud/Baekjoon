#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long ** arr = new long long*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new long long[N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = -999;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			long long temp1 = arr[i - 1][j] + arr[i][j];
			if (j != 0)
			{
				long long temp2 = arr[i - 1][j - 1] + arr[i][j];
				arr[i][j] = max(temp1, temp2);
			}
			else
			{
				arr[i][j] = temp1;
			}
		}
	}
	long long maxSum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[N - 1][i] > maxSum)
		{
			maxSum = arr[N - 1][i];
		}
	}
	cout << maxSum<<"\n";
	return 0;
}