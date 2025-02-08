#include <iostream>
#include <queue>
#include <utility>
using namespace std;
bool* isVisited;
queue<pair<int, int>> bfsQueue;
int A, B, N, M;

bool isInRange(int N)
{
	if (N >= 0 && N <= 100000)
	{
		return true;
	}
	return false;
}

void bfs()
{
	bfsQueue.push(pair(N, 0));
	isVisited[N] = true;
	while (true)
	{
		pair<int, int> f = bfsQueue.front();
		int current = f.first;
		if (current == M)
		{
			cout << f.second << "\n";
			break;
		}
		int nextPos[] = {current - 1, current + 1, current - A, current + A, current - B, current + B, current * A, current * B};
		for (int i = 0; i < 8; i++)
		{
			int next = nextPos[i];

			if (isInRange(next) && isVisited[next] == false)
			{
				isVisited[next] = true;
				bfsQueue.push(pair(next, f.second+1));
			}
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >>A>>B>> N >> M;
	isVisited = new bool[100001];
	for (int i = 0; i < 100001; i++)
	{
		isVisited[i] = false;
	}
	bfs();
	return 0;
}