#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
vector<int>* edges;
pair<int, int>* fields;
bool* isVisited;

int fieldCount = 1;
stack<int> dfsStack;

void search(int root)
{
	dfsStack.push(root);
	isVisited[root] = true;
	fields[root].first = fieldCount;
	while (!dfsStack.empty())
	{
		int top = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < edges[top].size() && isAdjacent == false; i++)
		{
			int next = edges[top].at(i);
			if (isVisited[next] == false)
			{
				isAdjacent = true;
				isVisited[next] = true;
				dfsStack.push(next);
				fieldCount++;
				fields[next].first = fieldCount;
			}
		}
		if (isAdjacent == false)
		{
			fieldCount++;
			fields[top].second = fieldCount;
			dfsStack.pop();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int nodeNum, connected, root;
	cin >> N;
	edges = new vector<int>[N+1];
	isVisited = new bool[N + 1];
	fields = new pair<int, int>[N + 1];
	for (int i = 0; i < N; i++)
	{
		isVisited[i + 1] = false;
		cin >> nodeNum;
		while (true)
		{
			cin >> connected;
			if (connected == -1)
			{
				break;
			}
			edges[nodeNum].push_back(connected);
		}
		sort(edges[nodeNum].begin(), edges[nodeNum].end());
	}
	cin >> root;
	search(root);
	for (int i = 1; i <= N; i++)
	{
		cout <<i <<" " << fields[i].first << " " << fields[i].second << "\n";
	}
	return 0;
}