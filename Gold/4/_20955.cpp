#include <iostream>
using namespace std;
int* parents;

int getParent(int x)
{
	if (parents[x] == x)
	{
		return x;
	}
	else
	{
		parents[x] = getParent(parents[x]);
		return parents[x];
	}
}

void merge(int x, int y)
{
	int xParent = getParent(x);
	int yParent = getParent(y);
	if (yParent > xParent)
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
	int A, B;
	int answer = 0;
	cin >> N >> M;
	parents = new int[N];
	for (int i = 0; i < N; i++)
	{
		parents[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		int aParent = getParent(A-1);
		int bParent = getParent(B-1);
		if (aParent == bParent)
		{
			answer++;
		}
		else
		{
			merge(A - 1, B - 1);
		}
	}
	for (int i = 1; i < N; i++)
	{
		int parent = getParent(i);
		if (parent != 0)
		{
			merge(0, i);
			answer++;
		}
	}
	cout << answer << "\n";
	return 0;
}