#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* dp = new int[N];
	int maxLength = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		int currentMax = -1;
		int currentMaxIndex = -1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j] > currentMax)
			{
				currentMax = dp[j];
				currentMaxIndex = j;
			}
		}
		if (currentMaxIndex == -1)
		{
			dp[i] = 1;
		}
		else
		{
			dp[i] = currentMax + 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > maxLength)
		{
			maxLength = dp[i];
		}
	}
	cout << N - maxLength << "\n";
	return 0;
}