#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* heights = new int[N];
	int* dp = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> heights[i];
	}
	dp[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		int prevPos = i + heights[i] + 1;
		if (prevPos < N)
		{
			dp[i] = dp[prevPos] + 1;
		}
		else
		{
			dp[i] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << dp[i] << " ";
	}
	return 0;
}