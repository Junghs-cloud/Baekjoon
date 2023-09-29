#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#define INF 1e9;
using namespace std;

vector<pair<int, int>>* arr;
int* distArr;
int* parents;
stack<int> path;

struct cmp
{
	bool operator()(pair<int, int>& p1, pair<int, int>& p2)
	{
		if (p1.second < p2.second)
		{
			return false;
		}
		else if (p1.second == p2.second)
		{
			return p1.first < p2.first;
		}
		else
		{
			return true;
		}
	}
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b, cost;
	int start, end;
	cin >> N;
	cin >> M;
	arr = new vector<pair<int, int>>[N + 1];
	distArr = new int[N + 1];
	parents = new int[N + 1];
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < N+1; i++)
	{
		distArr[i] = INF;
		parents[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> cost;
		arr[a].push_back(make_pair(b, cost));
	}
	cin >> start >> end;
	distArr[start] = 0;
	pq.push(make_pair(start, 0));
	while (!pq.empty())
	{
		int costUntilCurrent = pq.top().second;
		int currentIndex = pq.top().first;

		pq.pop();
		if (distArr[currentIndex] < costUntilCurrent)
		{
			continue;
		}
		for (int i = 0; i < arr[currentIndex].size(); i++)
		{
			pair<int, int> adjacentNode = arr[currentIndex].at(i);

			int nextCost = distArr[currentIndex] + adjacentNode.second;
			if (nextCost < distArr[adjacentNode.first])
			{
				distArr[adjacentNode.first] = nextCost;
				parents[adjacentNode.first] = currentIndex;
				pq.push(make_pair(adjacentNode.first, nextCost));
			}
		}
	}
	int currentNode = end;
	while (currentNode != 0)
	{
		path.push(currentNode);
		currentNode = parents[currentNode];
	}
	cout << distArr[end] << "\n";
	cout << path.size() << "\n";
	while (!path.empty())
	{
		cout << path.top()<<" ";
		path.pop();
	}
	return 0;
}