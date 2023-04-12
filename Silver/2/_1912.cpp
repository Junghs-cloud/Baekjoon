#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* dp = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> dp[i];
	}
	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i-1] + dp[i], dp[i]);
	}
	int currentMax = -9999;
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > currentMax)
		{
			currentMax = dp[i];
		}
	}
	cout << currentMax << "\n";
	return 0;
}