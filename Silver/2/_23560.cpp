#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* dp = new int[N+1];
	dp[1] = 2;
	for (int i = 2; i < N+1; i++)
	{
		dp[i] = 3 * dp[i - 1];
	}
	cout << dp[N] << "\n";
	return 0;
}