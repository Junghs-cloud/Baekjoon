#include <iostream>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int maxLength;
	stack<int> s;
	cin >> N;
	int* arr = new int[N];
	int* dp = new int[N];
	int* prev = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		prev[i] = -1;
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++)
	{
		maxLength = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j] > maxLength)
			{
				maxLength = dp[j];
				prev[i] = j;
			}
		}
		dp[i] = maxLength + 1;
	}
	maxLength = 0;
	int maxIndex = -1;
	for (int i = 0; i < N; i++)
	{
		if (dp[i] > maxLength)
		{
			maxLength = dp[i];
			maxIndex = i;
		}
	}
	while (true)
	{
		s.push(arr[maxIndex]);
		maxIndex = prev[maxIndex];
		if (maxIndex == -1)
		{
			break;
		}
	}
	cout << s.size() << "\n";
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}