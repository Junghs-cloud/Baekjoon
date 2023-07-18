#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int* arr;

struct info
{
	int start;
	int end;
	int weight;
	info(int a, int b, int c)
	{
		start = a;
		end = b;
		weight = c;
	}
};

bool cmp(info& i1, info& i2)
{
	if (i1.weight < i2.weight)
	{
		return true;
	}
	else if (i1.weight == i2.weight)
	{
		return i1.start < i2.start;
	}
	else
	{
		return false;
	}
}

int findParent(int num)
{
	if (arr[num] == num)
	{
		return num;
	}
	else
	{
		return arr[num] = findParent(arr[num]);
	}
}

bool haveCycle(int x, int y)
{
	int xParent = findParent(x);
	int yParent = findParent(y);
	if (xParent == yParent)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void merge(int x, int y)
{
	int xParent = findParent(x);
	int yParent = findParent(y);
	arr[xParent] = yParent;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b, weight;
	cin >> N;
	cin >> M;
	vector<info> information;
	arr = new int[N+1];
	int length = 0;
	for (int i = 0; i < N+1; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b>> weight;
		information.push_back(info(a, b, weight));
	}
	sort(information.begin(), information.end(), cmp);
	for (int i = 0; i < M; i++)
	{
		info currentInfo = information.at(i);
		if (haveCycle(currentInfo.start, currentInfo.end) == false)
		{
			merge(currentInfo.start, currentInfo. end);
			length += currentInfo.weight;
		}
	}
	cout << length << "\n";
	return 0;
}