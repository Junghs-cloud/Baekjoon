#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
queue<int> bfsQueue;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int C, M;
	cin >> N;
	int* input = new int[N];
	int* time = new int[N];
	vector<int>* next = new vector<int>[N];
	int* totalTime = new int[N];
	int answer = 0;
	for (int i = 0; i < N; i++)
	{

		cin >> time[i];
		totalTime[i] = time[i];
		cin >> C;
		if (C == 0)
		{
			bfsQueue.push(i);
		}
		for (int j = 0; j < C; j++)
		{
			cin >> M;
			next[M-1].push_back(i);
		}
		input[i] = C;
	}
	while (!bfsQueue.empty())
	{
		int current = bfsQueue.front();
		for (int i = 0; i < next[current].size(); i++)
		{
			int nextNode = next[current].at(i);
			totalTime[nextNode]= max(time[nextNode] + totalTime[current], totalTime[nextNode]);
			input[nextNode]--;
			if (input[nextNode] == 0)
			{
				bfsQueue.push(nextNode);
			}
		}
		bfsQueue.pop();
	}
	for (int i = 0; i < N; i++)
	{
		answer = max(answer, totalTime[i]);
	}
	cout << answer << "\n";
	return 0;
}