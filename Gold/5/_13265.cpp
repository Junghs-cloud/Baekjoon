#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int>* edges;
char* colors;
bool* isVisited;
bool isPossible;

queue<int> bfsQueue;

void bfs(int startNum)
{
	colors[startNum] = 'R';
	isVisited[startNum] = true;
	bfsQueue.push(startNum);
	while (!bfsQueue.empty())
	{
		int current = bfsQueue.front();
		for (int i = 0; i < edges[current].size(); i++)
		{
			int next = edges[current].at(i);
			if (isVisited[next] == false)
			{
				bfsQueue.push(next);
				isVisited[next] = true;
				if (colors[current] == 'R')
				{
					colors[next] = 'B';
				}
				else
				{
					colors[next] = 'R';
				}
			}
			else
			{
				if (colors[current] == colors[next])
				{
					isPossible = false;
				}
			}
		}
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
		cin >> N >> M;
		isPossible = true;
		int a, b;
		edges = new vector<int>[N + 1];
		colors = new char[N + 1];
		isVisited = new bool[N + 1];
		for (int i = 0; i < N + 1; i++)
		{
			isVisited[i] = false;
		}
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		for (int i = 1; i <= N; i++)
		{
			if (isVisited[i] == false)
			{
				bfs(i);
			}
		}
		if (isPossible == false)
		{
			cout << "impossible" << "\n";
		}
		else
		{
			cout << "possible" << "\n";
		}
	}
	return 0;
}