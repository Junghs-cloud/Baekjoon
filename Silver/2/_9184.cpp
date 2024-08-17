#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int*** dp = new int**[21];
	int a, b, c;
	for (int i = 0; i < 21; i++)
	{
		dp[i] = new int* [21];
		for (int j = 0; j < 21; j++)
		{
			dp[i][j] = new int[21];
			for (int k = 0; k < 21; k++)
			{
				dp[i][j][k] = 1;
			}
		}
	}
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			for (int k = 1; k < 21; k++)
			{
				if (i < j && j < k)
				{
					dp[i][j][k] = dp[i][j][k-1]+ dp[i][j-1][k-1]-dp[i][j-1][k];
				}
				else
				{
					dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j - 1][k] + dp[i - 1][j][k-1] - dp[i-1][j-1][k-1];
				}
			}
		}
	}
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}
		else
		{
			int answer = 0;
			if (a <= 0 || b <= 0 || c <= 0)
			{
				answer = 1;
			}
			else if (a > 20 || b > 20 || c > 20)
			{
				answer = dp[20][20][20];
			}
			else
			{
				answer = dp[a][b][c];
			}
			cout << "w(" << a << ", " << b << ", " << c << ") = " << answer << "\n";
		}
	}
	return 0;
}