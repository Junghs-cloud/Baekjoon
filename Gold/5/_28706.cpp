#include <iostream>
using namespace std;

int calcRemain(char op, int num, int j)
{
	if (op == '*')
	{
		return (num * j) % 7;
	}
	else
	{
		return (num + j) % 7;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, T;
	char op1, op2;
	int num1, num2;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		bool** dp = new bool* [N + 1];
		for (int i = 0; i < N + 1; i++)
		{
			dp[i] = new bool[7];
			for (int j = 0; j < 7; j++)
			{
				dp[i][j] = false;
			}
		}
		dp[0][1] = true;
		for (int i = 1; i <= N; i++)
		{
			cin >> op1 >> num1 >> op2 >> num2;
			for (int j = 0; j < 7; j++)
			{
				if (dp[i - 1][j] == true)
				{
					dp[i][calcRemain(op1, num1, j)] = true;
					dp[i][calcRemain(op2, num2, j)] = true;
				}
			}
		}
		if (dp[N][0] == false)
		{
			cout << "UNLUCKY" << "\n";
		}
		else
		{
			cout << "LUCKY" << "\n";
		}
	}
	return 0;
}