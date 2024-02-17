#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int A, B;
	cin >> N>>M;
	int* inDegree = new int[N+1];
	vector<int>* next = new vector<int>[N+1];
	queue<int> bfsQueue;
	for (int i = 0; i < N+1; i++)
	{
		inDegree[i] = 0;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		next[A].push_back(B);
		inDegree[B]++;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (inDegree[i] == 0)
		{
			bfsQueue.push(i);
		}
	}
	while (!bfsQueue.empty())
	{
		int current = bfsQueue.front();
		cout << current << " ";
		for (int i = 0; i < next[current].size(); i++)
		{
			int nextNode = next[current].at(i);
			inDegree[nextNode]--;
			if (inDegree[nextNode] == 0)
			{
				bfsQueue.push(nextNode);
			}
		}
		bfsQueue.pop();
	}
	return 0;
}