#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	int N = str.length();
	long long* dp = new long long[N];
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		if (str.at(i) == '0')
		{
			dp[i] = dp[i - 1];
			continue;
		}
		string prevStr = str.substr(i - 1, 2);
		int prevInt = stoi(prevStr);
		if (prevInt >= 10 && prevInt <= 34)
		{
			if (i == 1)
			{
				dp[i] = 2;
			}
			else
			{
				string currentStr = str.substr(i, 2);
				int currentInt = stoi(currentStr);
				if (currentInt == 10 || currentInt == 20 || currentInt == 30)
				{
					dp[i] = dp[i - 1];
				}
				else
				{
					dp[i] = dp[i - 1] + dp[i - 2];
				}
			}
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	cout << dp[N - 1] << "\n";
	return 0;
}