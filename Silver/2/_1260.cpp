#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int N;
int** arr;
bool* isVisited;
stack<int> dfsStack;
queue<int> bfsQueue;

void dfs(int vertex)
{

	dfsStack.push(vertex);
	isVisited[vertex] = true;
	cout << dfsStack.top() << " ";
	while (!dfsStack.empty())
	{
		int currentTop = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < N + 1; i++)
		{
			if (isVisited[i] == false && arr[currentTop][i] == 1)
			{
				isVisited[i] = true;
				isAdjacent = true;
				dfsStack.push(i);
				cout << dfsStack.top() << " ";
				break;
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
	cout << "\n";
}

void bfs(int vertex)
{
	bfsQueue.push(vertex);
	isVisited[vertex] = true;
	while (!bfsQueue.empty())
	{
		int currentFront = bfsQueue.front();
		cout << currentFront << " ";
		for (int i = 0; i < N + 1; i++)
		{
			if (isVisited[i] == false && arr[currentFront][i] == 1)
			{
				isVisited[i] = true;
				bfsQueue.push(i);
			}
		}
		bfsQueue.pop();
	}
	cout << "\n";
}

int main()
{
	int M, V;
	int a, b;
	cin >> N >> M >> V;
	
	arr = new int*[N + 1];
	isVisited = new bool[N + 1];

	for (int i = 0; i < N + 1; i++)
	{
		arr[i] = new int[N + 1];
	}
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
		for (int j = 0; j < N + 1; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	dfs(V);
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	bfs(V);

	return 0;
}