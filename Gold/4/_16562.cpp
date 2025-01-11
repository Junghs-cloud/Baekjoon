#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int* moneys;
int* parents;

int getParent(int x)
{
	if (parents[x] == x)
	{
		return x;
	}
	else
	{
		return parents[x] = getParent(parents[x]);
	}
}

void merge(int x, int y)
{
	int xParent = getParent(x);
	int yParent = getParent(y);
	if (xParent < yParent)
	{
		parents[yParent] = xParent;
	}
	else
	{
		parents[xParent] = yParent;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K;
	int a, b;
	int answer = 0;
	cin >> N >> M >> K;
	moneys = new int[N+1];
	parents = new int[N+1];
	int* connectedMoneys = new int[N + 1];
	for (int i = 1; i <= N; i++)
	{
		cin >> moneys[i];
		parents[i] = i;
		connectedMoneys[i] = moneys[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		int aParent = getParent(a);
		int bParent = getParent(b);
		if (aParent != bParent)
		{
			merge(a, b);
			connectedMoneys[aParent] = min(connectedMoneys[aParent], connectedMoneys[bParent]);
			connectedMoneys[bParent] = min(connectedMoneys[aParent], connectedMoneys[bParent]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (parents[i] == i)
		{
			answer += connectedMoneys[i];
		}
	}
	if (answer <= K)
	{
		cout << answer << "\n";
	}
	else
	{
		cout << "Oh no" << "\n";
	}
	return 0;
}