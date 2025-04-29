#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		int* arr = new int[N];
		long long* dp = new long long[N];
		long long answer = -2500000001;
		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			dp[i] = arr[i];
		}
		for (int i = 1; i < N; i++)
		{
			if (dp[i - 1] >= 0)
			{
				dp[i] += dp[i - 1];
			}
			answer = max(answer, dp[i]);
		}
		std::cout << answer << "\n";
	}
	return 0;
}