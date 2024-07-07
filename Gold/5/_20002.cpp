#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int** arr = new int*[N];
	long long** sums = new long long*[N + 1];
	long long answer = -200000000;
	for (int i = 0; i < N+1; i++)
	{
		sums[i] = new long long[N + 1];
		for (int j = 0; j < N + 1; j++)
		{
			sums[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			sums[i + 1][j + 1] = sums[i+1][j] + sums[i][j+1] - sums[i][j]  + arr[i][j];
		}
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			int minLength = min(i, j);
			for (int size = 1; size <= minLength; size++)
			{
				long long  currentSum = sums[i][j] - sums[i - size][j] - sums[i][j - size] + sums[i - size][j - size];
				answer =  max(answer, currentSum);
			}
		}
	}
	cout << answer << "\n";
	return 0;
}