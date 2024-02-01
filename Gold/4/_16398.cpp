#include <iostream>
#include <queue>
using namespace std;
int* parents;

struct info
{
	int A;
	int B;
	int cost;
	info(int a, int b, int c)
	{
		A = a;
		B = b;
		cost = c;
	}
};

struct cmp
{
	bool operator()(info& i1, info& i2)
	{
		if (i1.cost < i2.cost)
		{
			return false;
		}
		else if (i1.cost == i2.cost)
		{
			if (i1.A < i2.A)
			{
				return false;
			}
			else if (i1.A == i2.A)
			{
				return i1.B > i2.B;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}
};

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
	int parentX = findParent(x);
	int parentY = findParent(y);
	if (parentY > parentX)
	{
		parents[parentY] = parentX;
	}
	else
	{
		parents[parentX] = parentY;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int cost;
	long long sum = 0;
	cin >> N;
	priority_queue<info, vector<info>, cmp> pq;
	parents = new int[N];
	for (int i = 0; i < N; i++)
	{
		parents[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost;
			if (j > i)
			{
				pq.push(info(i, j, cost));
			}
		}
	}
	while (!pq.empty())
	{
		info current = pq.top();
		if (findParent(current.A) == findParent(current.B))
		{
			pq.pop();
		}
		else
		{
			merge(current.A, current.B);
			sum += current.cost;
			pq.pop();
		}
	}
	cout << sum << "\n";
	return 0;
}