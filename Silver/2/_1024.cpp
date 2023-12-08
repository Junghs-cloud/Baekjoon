#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N, M;
	long long* dp = new long long[151];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < 151; i++)
	{
		dp[i] = dp[i-1]+i;
	}
	cin >> N >> M;
	while (true)
	{
		long long temp = N - dp[M - 1];
		if (temp < 0 || M >= 101)
		{
			cout << -1 << "\n";
			break;
		}
		if (temp % M == 0)
		{
			for (int i = 0; i < M; i++)
			{
				cout << (temp/M) +i << " ";
			}
			cout << "\n";
			break;
		}
		else
		{
			M++;
		}
	}
	return 0;
}