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
	int* dp = new int[N];
	int answer = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		int maxLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[j] > maxLength)
			{
				maxLength = dp[j];
			}
		}
		dp[i] = maxLength + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";
	return 0;
}