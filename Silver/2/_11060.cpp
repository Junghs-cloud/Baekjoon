#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* dp = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1000000;
	}
	dp[0] = 0;
	for (int i = 0; i < N; i++)
	{
		int currentJump = dp[i];
		for (int j = i + 1; (j <= arr[i] + i && j <N); j++)
		{
			if (currentJump + 1 < dp[j])
			{
				dp[j] = currentJump + 1;
			}
		}
	}
	if (dp[N - 1] == 1000000)
	{
		cout << "-1" << "\n";
	}
	else
	{
		cout << dp[N - 1] << "\n";
	}
	return 0;
}