#include <iostream>
using namespace std;

int returnMax(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
		{
			return a;
		}
		else
		{
			return c;
		}
	}
	else
	{
		if (b < c)
		{
			return c;
		}
		else
		{
			return b;
		}
	}
}

int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int N;
		cin >> N;
		int** points = new int* [2];
		int** dp = new int* [3];
		//0: skip, 1: first row sticker select 2:second row sticker select;
		for (int i = 0; i < 3; i++)
		{
			dp[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			points[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				cin >> points[i][j];
			}
		}
		dp[1][0] = points[0][0];
		dp[2][0] = points[1][0];
		for (int i = 1; i < N; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + points[0][i];
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + points[1][i];
		}
		cout << returnMax(dp[1][N - 1], dp[2][N - 1], dp[0][N - 1]) << "\n";
	}
	return 0;
}