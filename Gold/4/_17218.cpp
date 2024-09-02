#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	int N = str1.length();
	int M = str2.length();
	int** dp = new int*[M+1];
	for (int i = 0; i < M+1; i++)
	{
		dp[i] = new int[N+1];
		for (int j = 0; j < N+1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < M+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			if (str2[i-1] == str1[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
			}
		}
	}
	int i = M;
	int j = N;
	stack<char> s;
	while (i > 0 && j > 0)
	{
		if (str2[i - 1] == str1[j - 1])
		{
			s.push(str2[i - 1]);
			i--;
			j--;
		}
		else
		{
			if (dp[i-1][j] < dp[i][j-1])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	return 0;
}