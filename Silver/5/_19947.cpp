#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int* dp = new int[M + 1];
	dp[0] = N;
	for (int i = 1; i < M+1; i++)
	{
		dp[i] = (int) (dp[i-1] * 1.05);
		if (i >= 3)
		{
			dp[i] = max(dp[i], (int)(dp[i - 3] * 1.2));
		}
		if (i >= 5)
		{
			dp[i] = max(dp[i], (int)(dp[i - 5] * 1.35));
		}
	}
	cout << dp[M] << "\n";
	return 0;
}