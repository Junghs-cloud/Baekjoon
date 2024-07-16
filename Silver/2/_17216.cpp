#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* dp = new int[N];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp[0] = arr[0];
	for (int i = 1; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[j] + arr[i] > sum)
			{
				sum = dp[j] + arr[i];
			}
		}
		if (sum == 0)
		{
			dp[i] = arr[i];
		}
		else
		{
			dp[i] = sum;
		}
	}
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";
	return 0;
}