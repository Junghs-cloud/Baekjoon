#include <iostream>
using namespace std;
int* parent;
int N;

int findRoot(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = findRoot(parent[x]);
	}
}

void merge(int x, int y)
{
	int xRoot = findRoot(x);
	int yRoot = findRoot(y);
	if (xRoot == yRoot)
	{
		return;
	}
	if (xRoot < yRoot)
	{
		parent[yRoot] = xRoot;
	}
	else
	{
		parent[xRoot] = yRoot;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> N;
	parent = new int[N + 1];
	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < N - 2; i++)
	{
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 2; i <= N; i++)
	{
		int bridge1 = findRoot(i - 1);
		int bridge2 = findRoot(i);
		if (bridge1 != bridge2)
		{
			merge(i - 1, i);
			cout << bridge1 << " " << bridge2 << "\n";
		}
	}
	return 0;
}