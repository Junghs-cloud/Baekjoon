#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> dfsStack;
vector<int>* heavier;
vector<int>* lighter;
bool* isVisited;
int N;

int find(int start, vector<int>* v)
{
	dfsStack.push(start);
	int depthCount = -1;
	while (!dfsStack.empty())
	{
		int current = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current].at(i);
			if (isVisited[next] == false)
			{
				dfsStack.push(v[current].at(i));
				isVisited[next] = true;
				isAdjacent = true;
			}
		}
		if (isAdjacent == false)
		{
			depthCount++;
			dfsStack.pop();
		}
	}
	return depthCount;
}

void reset()
{
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int M;
	int a, b;
	int answer = 0;
	cin >> N >> M;
	heavier = new vector<int>[N+1];
	lighter = new vector<int>[N+1];
	isVisited = new bool[N + 1];
	reset();
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		lighter[a].push_back(b);
		heavier[b].push_back(a);
	}
	for (int i =1; i < N+1; i++)
	{
		int heavierCount = find(i, heavier);
		reset();
		int lighterCount = find(i, lighter);
		reset();
		if (heavierCount >= (N + 1) / 2 || lighterCount >= (N + 1) / 2)
		{
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}