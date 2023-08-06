#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string* dp = new string[N + 1];
	if (N >= 1)
	{
		dp[1] = "CY";
	}
	if (N >= 2)
	{
		dp[2] = "SK";
	}
	if (N >= 3)
	{
		dp[3] = "CY";
	}
	for (int i = 4; i < N+1; i++)
	{
		if (dp[i - 1] == "CY" && dp[i - 3] == "CY")
		{
			dp[i] = "SK";
		}
		else if (dp[i - 1] == "SK" && dp[i - 3] == "SK")
		{
			dp[i] = "CY";
		}
		else
		{
			dp[i] = "SK";
		}
	}
	cout << dp[N] << "\n";
	return 0;
}