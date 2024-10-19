#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int prev;
	cin >> N;
	int* time = new int[N];
	int* totalTime = new int[N];
	int* inDegree = new int[N];
	vector<int>* connected = new vector<int>[N];
	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		cin >> time[i];
		totalTime[i] = 0;
		inDegree[i] = 0;
		while (true)
		{
			cin >> prev;
			if (prev == -1)
			{
				break;
			}
			connected[prev - 1].push_back(i);
			inDegree[i]++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
			totalTime[i] = time[i];
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		for (int i = 0; i < connected[current].size(); i++)
		{
			int next = connected[current].at(i);
			inDegree[next]--;
			totalTime[next] = max(totalTime[next], totalTime[current]);
			if (inDegree[next] == 0)
			{
				q.push(next);
				totalTime[next] += time[next];
			}
		}
		q.pop();
	}
	for (int i = 0; i < N; i++)
	{
		cout << totalTime[i] << "\n";
	}
	return 0;
}