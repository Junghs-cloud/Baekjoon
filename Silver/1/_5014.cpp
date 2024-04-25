#include <iostream>
#include <queue>
#include <utility>
using namespace std;
bool* isVisited;
int F, S, G, U, D;

void bfs()
{
	isVisited[S] = true;
	queue<pair<int, int>> bfsQueue;
	bool canGo = false;
	bfsQueue.push(pair(S, 0));
	while (!bfsQueue.empty())
	{
		pair<int, int> current = bfsQueue.front();
		if (current.first == G)
		{
			cout << current.second << "\n";
			canGo = true;
		}
		if (current.first + U <= F && isVisited[current.first + U] == false)
		{
			isVisited[current.first + U] = true;
			bfsQueue.push(pair(current.first + U, current.second+1));
		}
		if (current.first - D >= 1 && isVisited[current.first - D] == false)
		{
			isVisited[current.first - D] = true;
			bfsQueue.push(pair(current.first - D, current.second+1));
		}
		bfsQueue.pop();
	}
	if (canGo == false)
	{
		cout << "use the stairs" << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	isVisited = new bool[1000001];
	cin >> F >> S >>G>> U >> D;
	for (int i = 0; i < 1000001; i++)
	{
		isVisited[i] = false;
	}
	bfs();
	return 0;
}