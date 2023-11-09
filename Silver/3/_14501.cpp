#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* T = new int[N + 1];
	int* P = new int[N + 1];
	int* dp = new int[N + 1];
	T[0] = 0;
	P[0] = 0;
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = 0;
	}
	for (int i = 1; i < N+1; i++)
	{
		cin >> T[i] >> P[i];
	}
	if (T[0] <= N)
	{
		dp[T[0]] = P[0];
	}
	for (int i = 1; i < N + 1; i++)
	{
		dp[i + T[i] - 1] = max(dp[i + T[i] - 1], dp[i - 1] + P[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[N] << "\n";
	return 0;
}