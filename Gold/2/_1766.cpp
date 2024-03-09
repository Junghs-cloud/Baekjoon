#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int first, next;
	cin >> N >> M;
	int* indegree = new int[N + 1];
	vector<int>* v = new vector<int>[N + 1];
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N + 1; i++)
	{
		indegree[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> first >> next;
		indegree[next]++;
		v[first].push_back(next);
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (indegree[i] == 0)
		{
			pq.push(i);
		}
	}
	while (!pq.empty())
	{
		int current = pq.top();
		cout << current << " ";
		pq.pop();
		for (int i = 0; i < v[current].size(); i++)
		{
			int adjacent = v[current].at(i);
			indegree[adjacent]--;
			if (indegree[adjacent] == 0)
			{
				pq.push(adjacent);
			}
		}
	}
	return 0;
}