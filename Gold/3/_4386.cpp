#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
int* parents;
float answer = 0;
int N;

struct info
{
	int start;
	int end;
	float dist;
	info(int s, int e, float distance)
	{
		start = s;
		end = e;
		dist = distance;
	}
};

vector<pair<float, float>> v;
vector<info> edges;

bool cmp(info& i1, info& i2)
{
	if (i1.dist < i2.dist)
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
	if (parentX < parentY)
	{
		parents[parentY] = parentX;
	}
	else
	{
		parents[parentX] = parentY;
	}
}

void calcAllDistance()
{
	for (int i = 1; i < N; i++)
	{
		pair<float, float> currentStar = v.at(i);
		for (int j = 0; j < N; j++)
		{
			pair<float, float> adjacentStar = v.at(j);
			if (i <= j)
			{
				break;
			}
			if (i != j)
			{
				float x = adjacentStar.first - currentStar.first;
				float y = adjacentStar.second - currentStar.second;
				float distance = sqrt(x * x + y * y);
				edges.push_back(info(i, j, distance));
			}
		}
	}
}

void kruskal()
{
	sort(edges.begin(), edges.end(), cmp);
	for (int i = 0; i < edges.size(); i++)
	{
		info current = edges.at(i);
		if (findParent(current.start) == findParent(current.end))
		{
			continue;
		}
		else
		{
			merge(current.start, current.end);
			answer += current.dist;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	float x, y;
	cin >> N;
	parents = new int[N];
	for (int i = 0; i < N; i++)
	{
		parents[i] = i;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	calcAllDistance();
	kruskal();
	cout.precision(2);
	cout << fixed;
	cout << answer << "\n";
	return 0;
}