#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
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
			return p1.second > p2.second;
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

	int N, K;
	int M, V;
	int C;
	int value;
	int weight;
	cin >> N >> K;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> jewelry;
	priority_queue<int, vector<int>, greater<int>> q;
	priority_queue<int, vector<int>> tempQueue;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> M >> V;
		jewelry.push(make_pair(M, V));
	}
	for (int i = 0; i < K; i++)
	{
		cin >> C;
		q.push(C);
	}
	while (!q.empty())
	{
		int currentBag = q.top();
		while (!jewelry.empty())
		{
			weight = jewelry.top().first;
			value = jewelry.top().second;
			if (currentBag >= weight)
			{
				jewelry.pop();
				tempQueue.push(value);
			}
			else
			{
				break;
			}
		}
		if (!tempQueue.empty())
		{
			answer += tempQueue.top();
			tempQueue.pop();
		}
		q.pop();
	}
	cout << answer << "\n";
	return 0;
}