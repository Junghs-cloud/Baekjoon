#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int* parent;
struct edge
{
	int v1;
	int v2;
	int weight;
	edge(int a, int b, int c)
	{
		v1 = a;
		v2 = b;
		weight = c;
	}
};

bool compare(const edge& e1, const edge& e2)
{
	if (e1.weight < e2.weight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int findRoot(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = findRoot(parent[x]);
	}
}

void merge(int x, int y)
{
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);
	if (xRoot == yRoot)
	{
		return;
	}
	if (xRoot < yRoot)
	{
		parent[yRoot] = xRoot;
	}
	else
	{
		parent[xRoot] = yRoot;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int V, E;
	int v1, v2, weight;
	long long sum = 0;
	vector<edge> edges;
	cin >> V >> E;
	parent = new int[V];
	for (int i = 0; i < V; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < E; i++)
	{
		cin >> v1 >> v2 >> weight;
		edges.push_back(edge(v1, v2, weight));
	}
	sort(edges.begin(), edges.end(), compare);
	for (int i = 0; i < (signed) edges.size(); i++)
	{
		int currentV1 = edges.at(i).v1;
		int currentV2 = edges.at(i).v2;
		if (findRoot(currentV1 - 1) == findRoot(currentV2 - 1))
		{
			continue;
		}
		else
		{
			merge(currentV1 - 1, currentV2 - 1);
			sum += (long long)edges.at(i).weight;
		}
	}
	cout << sum << "\n";
	return 0;
}