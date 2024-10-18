#include <iostream>
#include <queue>
using namespace std;

struct score
{
	int s;
	int t;
	int count;
	score(int a, int b, int c)
	{
		s = a;
		t = b;
		count = c;
	}
};
queue<score> bfsQueue;

void popAll()
{
	while (!bfsQueue.empty())
	{
		bfsQueue.pop();
	}
}

void bfs(int s, int t)
{
	bfsQueue.push(score(s, t, 0));
	while (!bfsQueue.empty())
	{
		score current = bfsQueue.front();
		if (current.s == current.t)
		{
			cout << current.count << "\n";
			break;
		}
		if (current.s * 2 <= current.t + 3)
		{
			bfsQueue.push(score(current.s * 2, current.t + 3, current.count + 1));
		}
		bfsQueue.push(score(current.s + 1, current.t, current.count + 1));
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int C, S, T;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> S >> T;
		bfs(S, T);
		popAll();
	}
	return 0;
}