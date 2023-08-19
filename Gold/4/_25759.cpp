#include <iostream>
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
	for (int i = 0; i < N; i++)
	{
		cin >>arr[i];
	}
	dp[0] = 0;
	for (int i = 1; i < N; i++)
	{
		int max = 0;
		for (int j = i - 201; j < i; j++)
		{
			if (j < 0)
			{
				j = 0;
			}
			int current = abs(arr[i] - arr[j]);
			current = current * current;
			if (dp[j] + current > max)
			{
				max = dp[j] + current;
			}
		}
		dp[i] = max;
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > answer)
		{
			answer = dp[i];
		}
	}
	cout << answer << "\n";
	return 0;
}