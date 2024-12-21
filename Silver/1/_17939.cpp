#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int* arr = new int[N];
	int* maxCost = new int[N];
	long long answer = 0;
	stack<int> s;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		maxCost[i] = 0;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		while (!s.empty())
		{
			int top = s.top();
			if (arr[i] >= top)
			{
				s.pop();
			}
			else
			{
				break;
			}
		}
		if (!s.empty())
		{
			maxCost[i] = s.top();
			if (arr[i] > s.top())
			{
				s.push(arr[i]);
			}
		}
		else
		{
			s.push(arr[i]);
		}
	}
	for (int i = 0; i < N; i++)
	{
		answer += max(maxCost[i] - arr[i], 0);
	}
	cout << answer << "\n";
	return 0;
}