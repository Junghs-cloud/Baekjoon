#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1, str2;
	cin >> str1 >> str2;
	int length1 = str1.length();
	int length2 = str2.length();
	int** dp = new int* [length2+1];
	stack<char> s;
	for (int i = 0; i < length2+1; i++)
	{
		dp[i] = new int[length1+1];
		for (int j = 0; j < length1+1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < length2+1; i++)
	{
		for (int j = 1; j < length1+1; j++)
		{
			if (str2.at(i-1) == str1.at(j-1))
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	int i = length2;
	int j = length1;
	while (i >= 1 && j >= 1)
	{
		if (dp[i][j] == dp[i - 1][j])
		{
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1])
		{
			j--;
		}
		else
		{
			s.push(str2.at(i-1));
			i--;
			j--;
		}
	}
	cout << dp[length2][length1] << "\n";
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}