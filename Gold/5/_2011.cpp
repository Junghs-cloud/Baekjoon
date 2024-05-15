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
	bool canMake = true;
	long long* dp = new long long[N];
	if (str.at(0) == '0')
	{
		canMake = false;
	}
	else
	{
		dp[0] = 1;
		for (int i = 1; i < N; i++)
		{
			string prevStr = str.substr(i - 1, 2);
			int prevInt = stoi(prevStr);
			if (str.at(i) == '0' && prevInt != 10 && prevInt != 20)
			{
				canMake = false;
				break;
			}
			if (prevInt == 10 || prevInt == 20)
			{
				if (i == 1)
				{
					dp[i] = 1;
				}
				else
				{
					dp[i] = dp[i - 2];
				}
			}
			else if (prevInt >= 10 && prevInt <= 26)
			{
				if (i == 1)
				{
					dp[i] = 2;
				}
				else
				{
					dp[i] = dp[i - 1] % 1000000 + dp[i - 2] % 1000000;
					dp[i] %= 1000000;
				}
			}
			else
			{
				dp[i] = dp[i - 1];
			}
		}
	}
	if (canMake == false)
	{
		cout << 0 << "\n";
	}
	else
	{
		cout << dp[N - 1] << "\n";
	}
	return 0;
}