#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
	int start;
	int end;
	info(int a, int b)
	{
		start = a;
		end = b;
	}
};

bool compare(info& i1, info& i2)
{
	if (i1.start > i2.start)
	{
		return false;
	}
	else if (i1.start == i2.start)
	{
		return i1.end < i2.end;
	}
	else
	{
		return true;
	}
}

struct cmp
{
	bool operator()(info& i1, info& i2)
	{
		if (i1.end > i2.end)
		{
			return true;
		}
		else if (i1.end == i2.end)
		{
			return i1.start > i2.start;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int start, end;
	int confCount = 1;
	cin >> N;
	priority_queue<info, vector<info>, cmp> pq;
	vector<info> v;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		v.push_back(info(start, end));
	}
	sort(v.begin(), v.end(), compare);
	pq.push(v.at(0));
	for (int i = 1; i < N; i++)
	{
		if (v[i].start >= pq.top().end)
		{
			pq.pop();
			pq.push(v[i]);
		}
		else
		{
			if (pq.size() == confCount)
			{
				confCount++;
			}
			pq.push(v[i]);
		}
	}
	cout << confCount;
	return 0;
}