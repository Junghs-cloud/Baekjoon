#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> dfsStack;
vector<int>* edge;
bool* isVisited;
int virusComputer = 0;

void dfs()
{
	int currentTop;
	bool isAdjacent;
	dfsStack.push(1);
	isVisited[1] = true;
	while (!dfsStack.empty())
	{
		currentTop = dfsStack.top();
		isAdjacent = false;
		for (int i = 0; i < (signed) edge[currentTop].size(); i++)
		{
			int nextVertex = edge[currentTop].at(i);
			if (isVisited[nextVertex] == false)
			{
				isVisited[nextVertex] = true;
				dfsStack.push(nextVertex);
				virusComputer++;
				isAdjacent = true;
				break;
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
}

int main()
{
	int N, M;
	int v1, v2;
	cin >> N;
	cin >> M;
	edge = new vector<int>[N + 1];
	isVisited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2;
		edge[v1].push_back(v2);
		edge[v2].push_back(v1);
	}
	dfs();
	cout << virusComputer << "\n";
	return 0;
}