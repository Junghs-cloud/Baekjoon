#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 987654321;
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>>* v;
int* distArr;

void get()
{
	pq.push(make_pair(0, 1));
	while (!pq.empty())
	{
		int currentNode = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		if (distArr[currentNode] <cost)
		{
			continue;
		}
		for (int i = 0; i < v[currentNode].size(); i++)
		{
			int nextNode = v[currentNode].at(i).second;
			int lengthToNext = v[currentNode].at(i).first;
			if (cost + lengthToNext < distArr[nextNode])
			{
				distArr[nextNode] = cost + lengthToNext;
				pq.push(make_pair(cost + lengthToNext, nextNode));
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int start, end, length;
	cin >> N>>M;
	v = new vector<pair<int, int>>[N+1];
	distArr = new int[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		distArr[i] = MAX;
	}
	distArr[1] = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end >> length;
		v[start].push_back(make_pair(length, end));
		v[end].push_back(make_pair(length, start));
	}
	get();
	cout << distArr[N] << "\n";
	return 0;
}