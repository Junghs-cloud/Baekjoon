#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>* preJobs;
bool* isVisited;
queue<int> bfsQueue;
int N, X, answer;

void bfs()
{
	bfsQueue.push(X);
	isVisited[X] = true;
	while (!bfsQueue.empty())
	{
		int current = bfsQueue.front();
		for (int i = 0; i < preJobs[current].size(); i++)
		{
			int next = preJobs[current].at(i);
			if (isVisited[next] == false)
			{
				isVisited[next] = true;
				bfsQueue.push(next);
				answer++;
			}
		}
		bfsQueue.pop();
	}
	cout << answer << "\n";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int M, A, B;
	answer = 0;
	cin >> N >> M;
	preJobs = new vector<int>[N+1];
	isVisited = new bool[N+1];
	for (int i = 0; i < N+1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		preJobs[B].push_back(A);
	}
	cin >> X;
	bfs();
	return 0;
}