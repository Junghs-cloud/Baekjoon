#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int* distances;
vector<int>* connected;
void bfs()
{
	queue<int> bfsQueue;
	distances[0] = 0;
	bfsQueue.push(0);
	while (!bfsQueue.empty())
	{
		int currentFront = bfsQueue.front();
		for (int i = 0; i < connected[currentFront].size(); i++)
		{
			int next = connected[currentFront].at(i);
			if (distances[next] == -1)
			{
				distances[next] = distances[currentFront] + 1;
				bfsQueue.push(next);
			}
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> answers;
	int maxLength = 0;
	int N, M;
	int a, b;
	cin >> N >> M;
	connected = new vector<int>[N];
	distances = new int[N];
	for (int i = 0; i < N; i++)
	{
		distances[i] = -1;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		connected[a - 1].push_back(b - 1);
		connected[b - 1].push_back(a - 1);
	}
	bfs();
	for (int i = 0; i < N; i++)
	{
		if (distances[i] > maxLength)
		{
			maxLength = distances[i];
			answers.clear();
			answers.push_back(i);
		}
		else if (distances[i] == maxLength)
		{
			answers.push_back(i);
		}
	}
	int hideNum = answers.front();
	cout << hideNum+1<<" " << distances[hideNum] <<" "<<answers.size() << "\n";
	return 0;
}