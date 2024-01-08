#include <iostream>
using namespace std;
int* parent;
int N, M;

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
	if (parentX == parentY)
	{
		return;
	}
	else
	{
		if (parentX < parentY)
		{
			parent[parentY] = parentX;
		}
		else
		{
			parent[parentY] = parentY;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int information;
	bool canTravel = true;
	cin >> N;
	cin >> M;
	parent = new int[N];
	int* travelCities = new int[M];
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> information;
			if (information == 1)
			{
				merge(i, j);
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> travelCities[i];
	}
	for (int i = 0; i < M-1; i++)
	{
		int current = travelCities[i];
		int next = travelCities[i+1];
		current--;
		next--;
		if (findParent(current) != findParent(next))
		{
			canTravel = false;
		}
	}
	if (canTravel == true)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << "\n";
	}
	return 0;
}