#include <iostream>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	long long** dp = new long long*[31];
	for (int i = 0; i < 31; i++)
	{
		dp[i] = new long long[31];
		for (int j = 0; j < 31; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < 31; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	if (K == 0)
	{
		int n = N + M - 2;
		int r = M - 1;
		cout << dp[n][r];
	}
	else
	{
		int kPosX = (K-1) / M + 1;
		int kPosY = (K-1) % M + 1;
		int firstN = kPosX + kPosY - 2;
		int firstR = kPosY - 1;
		int lastN = N - kPosX + 1;
		int lastM = M - kPosY + 1;
		int secondN = lastN + lastM - 2;
		int secondR = lastM - 1;
		long long answer = dp[firstN][firstR] * dp[secondN][secondR];
		cout << answer << "\n";
	}
	return 0;
}