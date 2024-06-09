#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
stack<pair<int, int>> dfsStack;
vector<pair<int, int>>* graph;
bool* isVisited;
int N, M;

void dfs(int startPos, int endPos)
{
	isVisited[startPos] = true;
	dfsStack.push(pair(startPos, 0));
	while (!dfsStack.empty())
	{
		pair<int, int> current = dfsStack.top();
		bool isAdjacent = false;
		if (current.first == endPos)
		{
			cout << current.second<<"\n";
			break;
		}
		for (int i = 0; i < graph[current.first].size(); i++)
		{
			pair<int, int> next = graph[current.first].at(i);
			if (isVisited[next.first] == false)
			{
				isVisited[next.first] = true;
				dfsStack.push(pair(next.first, current.second + next.second));
				isAdjacent = true;
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
}

void reset()
{
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	while (!dfsStack.empty())
	{
		dfsStack.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B, C;
	cin >> N >> M;
	graph = new vector<pair<int, int>>[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < N-1; i++)
	{
		cin >> A >> B>>C;
		graph[A - 1].push_back(pair(B - 1, C));
		graph[B - 1].push_back(pair(A - 1, C));
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		reset();
		dfs(A - 1, B - 1);
	}
	return 0;
}