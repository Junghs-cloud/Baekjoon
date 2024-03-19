#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, num;
	cin >> N;
	cin >> M;
	bool* isVIP = new bool[N+1];
	int* dp = new int[N+1];
	int current = 0;
	for (int i = 0; i < N+1; i++)
	{
		isVIP[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		isVIP[num] = true;
	}
	if (isVIP[1] == false)
	{
		current = 1;
	}
	else
	{
		current = 0;
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < N+1; i++)
	{
		if (isVIP[i] == false)
		{
			current++;
			if (current == 1)
			{
				dp[i] = dp[i - 1];
			}
			else
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
		}
		else
		{
			current = 0;
			dp[i] = dp[i - 1];
		}
	}
	cout << dp[N] << "\n";
	return 0;
}