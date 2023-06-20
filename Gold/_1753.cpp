#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

struct info
{
	int node;
	int length;
	info(int a, int b)
	{
		node = a;
		length = b;
	}
};

struct compare
{
	bool operator()(info i1, info i2)
	{
		if (i1.length < i2.length)
		{
			return false;
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

	int V, E;
	int start;
	int a, b, cost;
	priority_queue<info, vector<info>, compare> pq;
	cin >> V >> E;
	cin >> start;
	vector<info>* v = new vector<info>[V + 1];
	int* distance = new int[V + 1];
	for (int i = 0; i < V + 1; i++)
	{
		if (i == start)
		{
			distance[i] = 0;
		}
		else
		{
			distance[i] = INF;
		}
	}
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> cost;
		v[a].push_back(info(b, cost));
	}
	pq.push(info(start, 0));
	while (!pq.empty())
	{
		info currentInfo = pq.top();
		int length = currentInfo.length;
		int node = currentInfo.node;
		pq.pop();
		if (distance[node] < length)
		{
			continue;
		}
		for (int i = 0; i < (signed) v[node].size(); i++)
		{
			info nextInfo = v[node].at(i);
			int cost = length + nextInfo.length;
			if (cost < distance[nextInfo.node])
			{
				distance[nextInfo.node] = cost;
				pq.push(info(nextInfo.node, cost));
			}
		}
	}
	for (int i = 1; i < V + 1; i++)
	{
		if (distance[i] == INF)
		{
			cout << "INF" << "\n";
		}
		else
		{
			cout << distance[i] << "\n";
		}
	}
	return 0;
}