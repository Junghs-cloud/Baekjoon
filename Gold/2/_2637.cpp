#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, X, Y, K;
	queue<int> q;
	vector<int> basic;
	cin >> N;
	cin >> M;
	int* inDegree = new int[N + 1];
	vector<pair<int, int>>* next = new vector<pair<int, int>>[N + 1];
	int** usedParts = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		inDegree[i] = 0;
		usedParts[i] = new int[N + 1];
		for (int j = 0; j < N + 1; j++)
		{
			usedParts[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> K;
		next[Y].push_back(pair(X, K));
		inDegree[X]++;
	}
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
			basic.push_back(i);
			usedParts[i][i] = 1;
		}
	}
	while (!q.empty())
	{
		int current = q.front();
		int* currentUsedParts = usedParts[current];
		for (int i = 0; i < next[current].size(); i++)
		{
			int nextPart = next[current].at(i).first;
			int needCount = next[current].at(i).second;
			for (int j = 0; j < N + 1; j++)
			{
				usedParts[nextPart][j] += currentUsedParts[j] * needCount;
			}
			inDegree[nextPart]--;
			if (inDegree[nextPart] == 0)
			{
				q.push(nextPart);
			}
		}
		q.pop();
	}
	for (int i = 0; i < basic.size(); i++)
	{
		cout<<basic.at(i)<<" " << usedParts[N][basic.at(i)] << "\n";
	}
	return 0;
}