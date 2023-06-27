#include <iostream>
using namespace std;
int* parent;

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void merge(int x, int y)
{
	int xRoot = find(x);
	int yRoot = find(y);
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
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b;
	bool isHaveCycle = false;
	int cycleNum = 0;
	cin >> N >> M;
	parent = new int[N];
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		if (isHaveCycle == false)
		{
			int aRoot = find(a);
			int bRoot = find(b);
			if (aRoot == bRoot)
			{
				cycleNum = i + 1;
				isHaveCycle = true;
			}
			else
			{
				merge(a, b);
			}
		}
	}
	cout << cycleNum<<"\n";
	return 0;
}