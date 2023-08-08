#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* front = new int[N];
	int* end = new int[N];
	int* dp = new int[N];
	int sameCount = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (i != 0)
		{
			if (arr[0] == arr[i])
			{
				sameCount++;
			}
		}
	}
	if (sameCount == N)
	{
		cout << 1 << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		int length = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && front[j] > length)
			{
				length = front[j];
			}
		}
		front[i] = length + 1;
		int endLength = 0;
		for (int j = i + 1; j < N; j++)
		{
			int longgest = 0;
			for (int k = i + 1; k < j; k++)
			{
				if (arr[i] > arr[k] && arr[k] > arr[j] && end[k] > longgest)
				{
					longgest = end[k];
				}
			}
			end[j] = longgest + 1;

			if (end[j] > endLength)
			{
				endLength = end[j];
			}
		}
		for (int a = 0; a < N; a++)
		{
			end[a] = 0;
		}
		dp[i] = front[i] + endLength;
	}
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > answer)
		{
			answer = dp[i];
		}
	}
	cout << answer << "\n";
	return 0;
}