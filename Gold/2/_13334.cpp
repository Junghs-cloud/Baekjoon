#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool cmp(pair<long long, long long>& p1, pair<long long, long long>& p2)
{
	if (p1.second < p2.second)
	{
		return true;
	}
	else if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	long long a, b, d;
	cin >> N;
	pair<long long, long long>* arr = new pair<long long, long long>[N];
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (a <= b)
		{
			arr[i] = pair(a, b);
		}
		else
		{
			arr[i] = pair(b, a);
		}
	}
	cin >> d;
	sort(arr, arr + N, cmp);
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		pq.push(arr[i].first);
		while (!pq.empty())
		{
			if (pq.top() < arr[i].second - d)
			{
				pq.pop();
			}
			else
			{
				break;
			}
		}
		answer = max(answer, (int) pq.size());
	}
	std::cout << answer << "\n";
	return 0;
}