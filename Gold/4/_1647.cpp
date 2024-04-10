#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int* parent;

struct info
{
	int start;
	int end;
	int cost;
	info(int a, int b, int c)
	{
		start = a;
		end = b;
		cost = c;
	}
};

bool cmp(info& i1, info& i2)
{
	if (i1.cost < i2.cost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int findParent(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		return parent[x] = findParent(parent[x]);
	}
}

void merge(int x, int y)
{
	int parentX = findParent(x);
	int parentY = findParent(y);
	if (parentX < parentY)
	{
		parent[parentY] = parentX;
	}
	else
	{
		parent[parentX] = parentY;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b, c;
	cin >> N>>M;
	parent = new int[N + 1];
	vector<info> v;
	long long answer = 0;
	int maxMSTLength = 0;
	for (int i = 0; i < N + 1; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		v.push_back(info(a, b, c));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i=0;i<M;i++)
	{
		info current = v.at(i);
		int parentX = findParent(current.start);
		int parentY = findParent(current.end);
		if (parentX != parentY)
		{
			merge(current.start, current.end);
			answer += current.cost;
			maxMSTLength = current.cost;
		}
	}
	cout << answer - maxMSTLength << "\n";
	return 0;
}