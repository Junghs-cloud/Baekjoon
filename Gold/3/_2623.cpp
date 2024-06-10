#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int counts, num;
	cin >> N >> M;
	vector<int>* graph = new vector<int>[N];
	vector<int>* assistant = new vector<int>[M];
	queue<int> q;
	queue<int> answerQueue;
	int* inDegree = new int[N];
	for (int i = 0; i < N; i++)
	{
		inDegree[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> counts;
		for (int j = 0; j < counts; j++)
		{
			cin >> num;
			assistant[i].push_back(num-1);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j < assistant[i].size(); j++)
		{
			int prev = assistant[i].at(j-1);
			int current = assistant[i].at(j);
			graph[prev].push_back(current);
			inDegree[current]++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int currentOrder = q.front();
		for (int i = 0; i < graph[currentOrder].size(); i++)
		{
			int next = graph[currentOrder].at(i);
			inDegree[next]--;
			if (inDegree[next] == 0)
			{
				q.push(next);
			}
		}
		answerQueue.push(currentOrder);
		q.pop();
	}
	if (answerQueue.size() == N)
	{
		while (!answerQueue.empty())
		{
			cout << answerQueue.front()+1<<"\n";
			answerQueue.pop();
		}
	}
	else
	{
		cout << 0 << "\n";
	}
	return 0;
}