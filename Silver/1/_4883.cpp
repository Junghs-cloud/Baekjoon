#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int testCase = 1;
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}
		int** arr = new int* [N];
		long long** dp = new long long* [N];
		for (int i = 0; i < N; i++)
		{
			arr[i] = new int[3];
			dp[i] = new long long[3];
			for (int j = 0; j < 3; j++)
			{
				cin >> arr[i][j];
				dp[i][j] = 0;
			}
		}
		dp[0][0] = MAX;
		dp[0][1] = arr[0][1];
		dp[0][2] = arr[0][1] + arr[0][2];
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == 0)
				{
					dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][j];
				}
				else if (j == 1)
				{
					dp[i][j] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] }) + arr[i][j];
				}
				else
				{
					dp[i][j] = min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] }) + arr[i][j];
				}
			}
		}
		cout <<testCase<<". " << dp[N - 1][1] << "\n";
		testCase++;
	}
	return 0;
}