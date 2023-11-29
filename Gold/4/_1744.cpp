#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int num;
	cin >> N;
	priority_queue<int> positive;
	priority_queue<int, vector<int>, greater<int>> negative;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num > 1)
		{
			positive.push(num);
		}
		else if (num == 1)
		{
			sum += 1;
		}
		else
		{
			negative.push(num);
		}
	}
	while (!negative.empty())
	{
		if (negative.size() >= 2)
		{
			int a = negative.top();
			negative.pop();
			int b = negative.top();
			negative.pop();
			sum += a * b;
		}
		else
		{
			sum += negative.top();
			negative.pop();
		}
	}

	while (!positive.empty())
	{
		if (positive.size() >= 2)
		{
			int a = positive.top();
			positive.pop();
			int b = positive.top();
			positive.pop();
			sum += a * b;
		}
		else
		{
			sum += positive.top();
			positive.pop();
		}
	}
	cout << sum << "\n";
	return 0;
}