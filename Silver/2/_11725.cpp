#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int>* arr;
int* parents;
bool* isVisited;
queue<int> bfsQueue;

void bfs()
{
	bfsQueue.push(0);
	isVisited[0] = false;
	while (!bfsQueue.empty())
	{
		int currentNode = bfsQueue.front();
		for (int i = 0; i < arr[currentNode].size(); i++)
		{
			int adjacentNode = arr[currentNode].at(i);
			if (isVisited[adjacentNode] == false)
			{
				isVisited[adjacentNode] = true;
				bfsQueue.push(adjacentNode);
				parents[adjacentNode] = currentNode;
			}
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N;
	arr = new vector<int>[N];
	parents = new int[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		parents[i] = 0;
		isVisited[i] = false;
	}
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		arr[a-1].push_back(b-1);
		arr[b-1].push_back(a-1);

	}
	bfs();
	for (int i = 1; i < N; i++)
	{
		cout << parents[i] + 1 << "\n";
	}
	return 0;
}