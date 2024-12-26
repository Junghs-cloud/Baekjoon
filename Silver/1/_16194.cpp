#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* cards = new int[N+1];
	int** dp = new int*[N+1];
	for (int i = 0; i < N+1; i++)
	{
		dp[i] = new int[N+1];
		for (int j = 0; j < N+1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i < N+1; i++)
	{
		cin >> cards[i];
	}
	for (int i = 0;i < N + 1; i++)
	{
		dp[1][i] = cards[1] * i;
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (j >= i)
			{
				dp[i][j] = dp[i - 1][j];
				for (int cardCount = 1; cardCount <= j / i; cardCount++)
				{
					int restCard = j - (cardCount * i);
					int currentCardMoney = cardCount * cards[i];
					dp[i][j] = min(dp[i][j], dp[i][restCard] + currentCardMoney);
				}
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[N][N] << "\n";
	return 0;
}