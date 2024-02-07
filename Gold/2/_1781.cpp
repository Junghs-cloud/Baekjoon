#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

struct cmp
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.first < p2.first)
		{
			return false;
		}
		else if (p1.first == p2.first)
		{
			return p1.second < p2.second;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int deadline, cupRamyeon;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	priority_queue<int, vector<int>, greater<int>> v;
	int day = 1;
	long long sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> deadline >> cupRamyeon;
		pq.push(make_pair(deadline, cupRamyeon));
	}
	while (!pq.empty())
	{
		if (day <= pq.top().first )
		{
			v.push(pq.top().second);
			day++;
		}
		else
		{
			if (pq.top().second >= v.top())
			{
				v.pop();
				v.push(pq.top().second);
			}
		}
		pq.pop();
	}
	while (!v.empty())
	{
		sum += v.top();
		v.pop();
	}
	cout << sum << "\n";
	return 0;
}