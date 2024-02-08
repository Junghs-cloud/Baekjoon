#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int* distanceArr;
int N;
vector<pair<int, int>>* v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int startNode)
{
	distanceArr[startNode] = 0;
	pq.push(make_pair(0, startNode));
	while (!pq.empty())
	{
		pair<int, int> current = pq.top();
		int cost = current.first;
		int currentNode = current.second;
		
		pq.pop();
		if (cost > distanceArr[currentNode])
		{
			continue;
		}
		else
		{
			for (int i = 0; i < v[currentNode].size(); i++)
			{
				pair<int, int> next = v[currentNode].at(i);
				int nextNode = next.first;
				int dist = next.second;
				if (cost + dist < distanceArr[nextNode])
				{
					distanceArr[nextNode] = cost + dist;
					pq.push(make_pair(cost + dist, nextNode));
				}
			}
		}
	}
}

void resetDistanceArr()
{
	for (int i = 0; i < N + 1; i++)
	{
		distanceArr[i] = 987654321;
	}
}

int getMinCost(int first, int second)
{
	int cost;
	dijkstra(1);
	if (distanceArr[first] == 987654321)
	{
		return -1;
	}
	cost = distanceArr[first];
	resetDistanceArr();
	dijkstra(first);
	if (distanceArr[N] == 987654321)
	{
		return -1;
	}
	cost += distanceArr[second];
	resetDistanceArr();
	dijkstra(second);
	if (distanceArr[N] == 987654321)
	{
		return -1;
	}
	cost += distanceArr[N];
	return cost;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int E;
	int start, end, cost;
	int vertex1, vertex2;
	cin >> N>>E;
	v=new vector<pair<int, int>>[N+1];
	distanceArr = new int[N + 1];
	resetDistanceArr();
	for (int i = 0; i < E; i++)
	{
		cin >> start >> end >> cost;
		v[start].push_back(make_pair(end, cost));
		v[end].push_back(make_pair(start, cost));
	}
	cin >> vertex1 >> vertex2;
	int firstRouteCost = getMinCost(vertex1, vertex2);
	resetDistanceArr();
	int secondRouteCost = getMinCost(vertex2, vertex1);
	if (firstRouteCost == -1 && secondRouteCost == -1)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << min(firstRouteCost, secondRouteCost) << "\n";
	}
	return 0;
}