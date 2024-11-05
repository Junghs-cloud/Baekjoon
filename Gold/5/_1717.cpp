#include <iostream>
using namespace std;
int* parents;

int findParent(int x)
{
	if (parents[x] == x)
	{
		return x;
	}
	else
	{
		return parents[x] = findParent(parents[x]);
	}
}

void merge(int x, int y)
{
	int xParent = findParent(x);
	int yParent = findParent(y);
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

	int N, M;
	int query, a, b;
	cin >> N >> M;
	parents = new int[N+1];
	for (int i = 0; i < N+1; i++)
	{
		parents[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> query >> a >> b;
		if (query == 0)
		{
			merge(a, b);
		}
		else
		{
			int aParent = findParent(a);
			int bParent = findParent(b);
			if (aParent == bParent)
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
	}
	return 0;
}