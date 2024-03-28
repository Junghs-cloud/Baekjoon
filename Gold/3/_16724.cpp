#include <iostream>
#include <set>
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
	int parentX = findParent(x);
	int parentY = findParent(y);
	if (parentY < parentX)
	{
		parents[parentX] = parentY;
	}
	else
	{
		parents[parentY] = parentX;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	string str;
	cin >> N >> M;
	parents = new int[N * M];
	char** dir = new char* [N];
	set<int> s;
	set<int>::iterator it;
	bool isChanged = false;
	for (int i = 0; i < N; i++)
	{
		dir[i] = new char[M];
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			dir[i][j] = str.at(j);
		}
	}
	for (int i = 0; i < N * M; i++)
	{
		parents[i] = i;
	}
	while (true)
	{
		isChanged = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int x, y;
				if (dir[i][j] == 'D')
				{
					x = findParent(i * M + j);
					y = findParent((i + 1) * M + j);
				}
				else if (dir[i][j] == 'L')
				{
					x = findParent(i * M + j - 1);
					y = findParent(i * M + j);
				}
				else if (dir[i][j] == 'R')
				{
					x = findParent(i * M + j + 1);
					y = findParent(i * M + j);
				}
				else
				{
					x = findParent(i * M + j);
					y = findParent((i - 1) * M + j);
				}
				if (x != y)
				{
					merge(x, y);
					isChanged = true;
				}
			}
		}
		if (isChanged == false)
		{
			break;
		}
	}

	for (int i = 0; i < N*M; i++)
	{
		it = s.find(parents[i]);
		if (it == s.end())
		{
			s.insert(parents[i]);
		}
	}
	cout << s.size() << "\n";
	return 0;
}