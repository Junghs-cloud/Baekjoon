#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N+1];
	for (int i = 1; i < N+1; i++)
	{
		cin >> arr[i];
	}
	if (N == 1)
	{
		cout << arr[1] << "\n";
	}
	else
	{
		int** dp = new int*[100001];
		for (int i = 0; i < 100001; i++)
		{
			dp[i] = new int[3];
		}
		dp[1][0] = 0;
		dp[1][1] = arr[1];
		dp[1][2] = arr[1];

		dp[2][0] = arr[1];
		dp[2][1] = arr[2];
		dp[2][2] = arr[1] + arr[2] / 2;

		for (int i = 3; i <= N; i++)
		{
			dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
			dp[i][1] = dp[i - 1][0] + arr[i];
			dp[i][2] = dp[i - 1][1] + arr[i] / 2;
		}
		cout << max({ dp[N][0], dp[N][1], dp[N][2] });
	}
	return 0;
}