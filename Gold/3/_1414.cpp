#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
int* parents;
int N;

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

struct cmp
{
	bool operator()(info& i1, info& i2)
	{
		if (i1.cost <= i2.cost)
		{
			return false;
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
	int xParent = findParent(x);
	int yParent = findParent(y);
	if (yParent < xParent)
	{
		parents[xParent] = yParent;
	}
	else
	{
		parents[yParent] = xParent;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int answer = 0;
	int connectedNode = 1;
	string str;
	cin >> N;
	parents = new int[N];
	priority_queue<info, vector<info>, cmp> pq;
	for (int i = 0; i < N; i++)
	{
		parents[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			if (str.at(j) != '0')
			{
				int length = 0;
				if (str.at(j) >= 97)
				{
					length = str.at(j) - 96;
				}
				else
				{
					length = str.at(j) - 38;
				}
				pq.push(info(i, j, length));
			}
		}
		
	}
	while (!pq.empty())
	{
		info current = pq.top();
		int startParent = findParent(current.start);
		int endParent = findParent(current.end);
		if (startParent != endParent)
		{
			merge(startParent, endParent);
			connectedNode++;
		}
		else
		{
			answer += current.cost;
		}
		pq.pop();
	}
	if (connectedNode == N)
	{
		cout << answer << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}
	return 0;
}