#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a, b;
vector<int>* v;
bool* isVisited;

struct change
{
	int num;
	int changeCount;
	change(int a, int b)
	{
		num = a;
		changeCount = b;
	}
};
queue<change> bfsQueue;

int bfs()
{
	bfsQueue.push(change(a, 0));
	isVisited[a] = true;
	while (!bfsQueue.empty())
	{
		change currentFront = bfsQueue.front();
		if (currentFront.num == b)
		{
			return currentFront.changeCount;
		}
		for (int i = 0; i < (signed) v[currentFront.num].size(); i++)
		{
			int friends = v[currentFront.num].at(i);
			if (isVisited[friends] == false)
			{
				bfsQueue.push(change(friends, currentFront.changeCount + 1));
				isVisited[friends] = true;
			}
		}
		bfsQueue.pop();
	}
	return -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int first, second;
	cin >> a >> b;
	cin >> N >> M;
	v = new vector<int>[N + 1];
	isVisited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> first >> second;
		v[first].push_back(second);
		v[second].push_back(first);
	}
	int totalCount = bfs();
	cout << totalCount << "\n";
	return 0;
}