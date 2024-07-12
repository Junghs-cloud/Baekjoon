#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
vector<int>* nodes;
pair<bool, char>* isVisited;
queue<int> bfsQueue;

int V, E;
bool isBipartiteGraph;

void bfs(int startNode)
{
	isVisited[startNode].first = true;
	isVisited[startNode].second = 'R';
	bfsQueue.push(startNode);
	while (!bfsQueue.empty())
	{
		if (isBipartiteGraph == false)
		{
			break;
		}
		int current = bfsQueue.front();
		for (int i = 0; i < nodes[current].size(); i++)
		{
			int nextNode = nodes[current].at(i);
			if (isVisited[nextNode].first == true)
			{
				if (isVisited[current].second == isVisited[nextNode].second)
				{
					isBipartiteGraph = false;
					break;
				}
			}
			else
			{
				if (isVisited[current].second == 'R')
				{
					isVisited[nextNode].second = 'B';
				}
				else
				{
					isVisited[nextNode].second = 'R';
				}
				isVisited[nextNode].first = true;
				bfsQueue.push(nextNode);
			}
		}
		bfsQueue.pop();
	}
}

void checkisBipartiteGraph()
{
	if (isBipartiteGraph == false)
	{
		cout << "NO" << "\n";
	}
	else
	{
		cout << "YES" << "\n";
	}
}

void reset()
{
	for (int i = 1; i <= V; i++)
	{
		nodes[i].clear();
		isVisited[i] = pair(false, '\0');
	}
	while (!bfsQueue.empty())
	{
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int a, b;
		cin >> V >> E;
		nodes = new vector<int>[20001];
		isVisited = new pair<bool, char>[200001];
		for (int i = 1; i <= V; i++)
		{
			isVisited[i] = pair(false, '\0');
		}
		for (int i = 0; i < E; i++)
		{
			cin >> a >> b;
			nodes[a].push_back(b);
			nodes[b].push_back(a);
		}
		isBipartiteGraph = true;
		for (int nodeNum = 1; nodeNum <= V; nodeNum++)
		{
			if (isVisited[nodeNum].first == false)
			{
				bfs(nodeNum);
			}
		}
		checkisBipartiteGraph();
		reset();
	}
	return 0;
}