#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, X;
	cin >> N >> X;
	int* day = new int[N];
	long long* sum = new long long[N];
	int duration = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> day[i];
	}
	sum[0] = day[0];
	for (int i = 1; i < N; i++)
	{
		sum[i] = day[i] + sum[i - 1];
	}
	long long maxSum = sum[X-1];
	for (int i = X; i < N; i++)
	{
		if (maxSum < sum[i] - sum[i-X])
		{
			maxSum = sum[i] - sum[i - X];
			duration = 1;
		}
		else if (maxSum == sum[i] - sum[i-X])
		{
			duration++;
		}
	}
	if (maxSum == 0)
	{
		cout << "SAD" << "\n";
	}
	else
	{
		cout << maxSum << "\n" << duration << "\n";
	}
	return 0;
}