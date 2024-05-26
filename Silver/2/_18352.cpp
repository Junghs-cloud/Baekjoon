#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 987654321
using namespace std;
int* distances;
vector<pair<int, int>>* roads;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, K, X;
	int start, end;
	bool canFind = false;
	cin >> N>>M>>K>>X;
	distances = new int[N];
	roads = new vector<pair<int, int>>[N];
	for (int i = 0; i < N; i++)
	{
		distances[i] = MAX;
		if (i == X - 1)
		{
			distances[i] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		roads[start-1].push_back(pair(1, end-1));
	}
	pq.push(pair(0, X - 1));
	while (!pq.empty())
	{
		pair<int, int> current = pq.top();
		int cityNum = current.second;
		int cost = current.first;
		pq.pop();
		if (cost > distances[cityNum])
		{
			continue;
		}
		for (int i = 0; i < roads[cityNum].size(); i++)
		{
			int nextCity = roads[cityNum].at(i).second;
			if (cost + 1 < distances[nextCity])
			{
				distances[nextCity] = cost + 1;
				pq.push(pair(cost+1, nextCity));
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (distances[i] == K)
		{
			cout << i + 1 << "\n";
			canFind = true;
		}
	}
	if (canFind == false)
	{
		cout << -1 << "\n";
	}
	return 0;
}