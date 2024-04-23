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
	int* dp = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		dp[i] = i;
		for (int j = 1; j <= sqrt(i); j++)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N] << "\n";
	return 0;
}