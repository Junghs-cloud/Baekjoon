#include <iostream>
using namespace std;

int countBit(long long temp)
{
	if (temp == 0)
	{
		return 0;
	}
	return temp % 2 + countBit(temp / 2);
}

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
	}
	if (N == 1)
	{
		cout << 0 << "\n";
	}
	else
	{
		int num = arr[0] ^ arr[1];
		dp[1] = countBit(num);
		if (N >= 3)
		{
			dp[2] = countBit(arr[0] ^ arr[1] ^ arr[2]);
		}
		for (int i = 3; i < N; i++)
		{
			int second = arr[i - 1] ^ arr[i];
			int third = arr[i - 2] ^ arr[i - 1] ^ arr[i];
			dp[i] = dp[i - 2] + countBit(second);
			if (i != 3)
			{
				dp[i] = max(dp[i], dp[i - 3] + countBit(third));
			}
		}
		cout << dp[N - 1] << "\n";
	}
	return 0;
}