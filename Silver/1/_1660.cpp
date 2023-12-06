#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int* part = new int[151];
	int* dp = new int[151];
	int* answers = new int[300001];
	part[0] = 0;
	dp[0] = 0;
	part[1] = 1;
	for (int i = 2; i < 151; i++)
	{
		part[i] = part[i-1]+i;
	}
	for (int i = 1; i < 151; i++)
	{
		dp[i] = dp[i - 1] + part[i];
	}
	for (int i = 0; i < 300001; i++)
	{
		answers[i] = i;
	}
	for (int i = 1; i < 151; i++)
	{
		for (int j = dp[i]; j < 300001; j++)
		{
			if (j % dp[i] == 0)
			{
				answers[j] =min(answers[j], j / dp[i]);
			}
			else
			{
				answers[j] = min(answers[j], answers[j - dp[i]] + answers[dp[i]]);
			}
		}
	}
	cin >> N;
	cout << answers[N];
	return 0;
}