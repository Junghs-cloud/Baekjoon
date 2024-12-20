#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* dp = new int[N+1];
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < N+1; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N] <<" " << max(N - 2, 0) << "\n";
	return 0;
}