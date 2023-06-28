#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct info
{
	int nodeNum;
	int weight;
	info(int a, int b)
	{
		nodeNum = a;
		weight = b;
	}
};

stack<info> dfsStack;
vector<info>* v;
int longgestLength = 0;
int longgestNode = 0;
bool* isVisited;

void dfs(int node)
{
	int cost = 0;
	dfsStack.push(info(node, 0));
	isVisited[node] = true;
	while (!dfsStack.empty())
	{
		info currentTop = dfsStack.top();
		int currentNode = currentTop.nodeNum;
		bool isAdjacent = false;
		if (isVisited[currentNode] == false)
		{
			cost += currentTop.weight;
			isVisited[currentNode] = true;
		}
		for (int i = 0; i < v[currentNode].size(); i++)
		{
			int nextNode = v[currentNode].at(i).nodeNum;
			int weight = v[currentNode].at(i).weight;
			if (isVisited[nextNode] == false)
			{
				isAdjacent = true;
				dfsStack.push(info(nextNode, weight));
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
			if (cost > longgestLength)
			{
				longgestLength = cost;
				longgestNode = currentNode;
			}
			cost -= currentTop.weight;
		}
	}
}

int main()
{
	int V;
	int node, input = 0;
	int weight;
	cin >> V;
	v = new vector<info>[V + 1];
	isVisited = new bool[V + 1];
	for (int i = 0; i < V + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < V; i++)
	{
		cin >> node;
		while (true)
		{
			cin >> input;
			if (input == -1)
			{
				break;
			}
			else
			{
				cin >> weight;
				v[node].push_back(info(input, weight));
			}
		}
	}
	dfs(1);
	for (int i = 0; i < V + 1; i++)
	{
		isVisited[i] = false;
	}
	dfs(longgestNode);
	cout << longgestLength << "\n";
	return 0;
}