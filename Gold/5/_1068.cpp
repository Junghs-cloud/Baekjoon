#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, erasedNode;
bool* isVisited;
stack<int> dfsStack;
vector<int>* childs;

void dfs(int eraseNodeNum)
{
	dfsStack.push(eraseNodeNum);
	isVisited[eraseNodeNum] = true;
	while (!dfsStack.empty())
	{
		int currentTop = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < childs[currentTop].size(); i++)
		{
			int child = childs[currentTop].at(i);
			if (isVisited[child] == false)
			{
				isVisited[child] = true;
				isAdjacent = true;
				dfsStack.push(child);
			}
		}
		if (isAdjacent == false)
		{
			erasedNode++;
			dfsStack.pop();
		}
	}
}

int findLeafNode()
{
	int leafNodeNum = 0;
	for (int i = 0; i < N; i++)
	{
		if (isVisited[i] == false)
		{
			bool isLeafNode = true;
			for (int j = 0; j < childs[i].size(); j++)
			{
				int childNode = childs[i].at(j);
				if (isVisited[childNode] == false)
				{
					isLeafNode = false;
				}
			}
			if (isLeafNode == true)
			{
				leafNodeNum++;
			}
		}
	}
	return leafNodeNum;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int nodeNum;
	cin >> N;
	childs = new vector<int>[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		cin >> nodeNum;
		isVisited[i] = false;
		if (nodeNum == -1)
		{
			continue;
		}
		childs[nodeNum].push_back(i);
	}
	cin >> nodeNum;
	dfs(nodeNum);
	cout << findLeafNode() << "\n";
	return 0;
}