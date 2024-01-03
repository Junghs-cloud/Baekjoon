#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int* dp = new int[N + 1];
	dp[0] = 1;
	dp[1] = 0;
	if (N >= 2)
	{
		dp[2] = 3;
		for (int i = 3; i < N + 1; i++)
		{
			if (i % 2 == 1)
			{
				dp[i] = 0;
			}
			else
			{
				dp[i] = dp[i - 2] * 3;
				for (int j = i - 4; j >= 0; j -= 2)
				{
					dp[i] += dp[j] * 2;
				}
			}
		}
	}
	cout << dp[N] << "\n";
	return 0;
}