#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* dp = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = 0;
	}
	dp[0] = 0;
	dp[1] = 1;
	if (N >= 2)
	{
		dp[2] = 2;
	}
	for (int i = 3; i < N + 1; i++)
	{
		dp[i]= dp[i-2] % 15746 + dp[i-1] % 15746;
		dp[i] = dp[i] % 15746;
	}
	cout << dp[N] << "\n";
	return 0;
}