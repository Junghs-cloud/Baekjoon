#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, T, num;
	cin >> N >> M;
	queue<int>* q = new queue<int>[200001];
	int* sushiCounts = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> T;
		sushiCounts[i] = 0;
		for (int j = 0; j < T; j++)
		{
			cin >> num;
			q[num].push(i);
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (!q[num].empty())
		{
			int current = q[num].front();
			sushiCounts[current]++;
			q[num].pop();
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << sushiCounts[i]<<" ";
	}
	return 0;
}