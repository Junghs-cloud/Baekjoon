#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string* dp = new string[1001];
	dp[0] = "";
	dp[1] = "SK";
	dp[2] = "CY";
	dp[3] = "SK";
	dp[4] = "SK";
	for (int i = 5; i < 1001; i++)
	{
		if (dp[i - 1] == "SK" && dp[i - 3] == "SK" && dp[i - 4] == "SK")
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