#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long N, K, T;
	cin >> N >> K >> T;
	long long* arr = new long long[N];
	stack<long long> smaller;
	queue<long long> bigger;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < T)
		{
			smaller.push(arr[i]);
		}
		else
		{
			bigger.push(arr[i]);
		}
	}
	for (int i = 0; i < K; i++)
	{
		if (smaller.empty())
		{
			break;
		}
		else
		{
			long long currentTop = smaller.top();
			T += currentTop;
			smaller.pop();
			while (!bigger.empty() && T > bigger.front())
			{
				long long nextSize = bigger.front();
				bigger.pop();
				smaller.push(nextSize);
			}
		}
	}
	cout << T << "\n";
	return 0;
}