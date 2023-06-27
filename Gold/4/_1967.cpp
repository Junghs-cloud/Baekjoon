#include <iostream>
#include <vector>
using namespace std;
int maxLength = 0;
int length = 0;
int N;
bool* isVisited;

struct node
{
	int nodeNum;
	int value;
	node(int a, int b)
	{
		nodeNum = a;
		value = b;
	}
};
vector<node>* v;

void dfs(int depth, int nodeNum)
{
	if (depth != 0 && v[nodeNum].size() == 1)
	{
		if (maxLength < length)
		{
			maxLength = length;
		}
		return;
	}
	else
	{
		for (int i = 0; i <(signed) v[nodeNum].size(); i++)
		{
			node nextNode = v[nodeNum].at(i);
			if (isVisited[nextNode.nodeNum] == false)
			{
				isVisited[nextNode.nodeNum] = true;
				length += nextNode.value;
				dfs(depth + 1, nextNode.nodeNum);
				length -= nextNode.value;
				isVisited[nextNode.nodeNum] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, cost;
	cin >> N;
	v = new vector<node>[N + 1];
	isVisited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b >> cost;
		v[a].push_back(node(b, cost));
		v[b].push_back(node(a, cost));
	}
	for (int i = 1; i < N + 1; i++)
	{
		length = 0;
		isVisited[i] = true;
		dfs(0, i);
		isVisited[i] = false;
	}
	cout << maxLength << "\n";
	return 0;
}