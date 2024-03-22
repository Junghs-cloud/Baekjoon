#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
int N, M;
long long* distances;

struct edge
{
	int start;
	int end;
	int cost;
	edge(int a, int b, int c)
	{
		start = a;
		end = b;
		cost = c;
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> N>>M;
	vector<edge> edges;
	distances = new long long[N + 1];
	bool hasNegativeCycle = false;
	for (int i = 0; i < N + 1; i++)
	{
		if (i == 1)
		{
			distances[i] = 0;
		}
		else
		{
			distances[i] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		edges.push_back(edge(a, b, c));
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < edges.size(); j++)
		{
			int currentNode = edges.at(j).start;
			int nextNode = edges.at(j).end;
			long long cost = edges.at(j).cost;
			if (distances[currentNode] != INF && distances[currentNode] + cost < distances[nextNode])
			{
				distances[nextNode] = distances[currentNode] + cost;
				if (i == N-1)
				{
					hasNegativeCycle = true;
				}
			}
		}
	}
	if (hasNegativeCycle == true)
	{
		cout <<  "-1" << "\n";
	}
	else
	{
		for (int i = 2; i < N + 1; i++)
		{
			if (distances[i] == INF)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << distances[i] << "\n";
			}
		}
	}
	return 0;
}