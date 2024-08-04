#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> bfsQueue;
queue<int> answerQueue;
vector<int>* arr;
bool* isVisited;
int maxNum = 0;
int N, M, A, B;

int bfs(int start)
{
	int count = 0;
	bfsQueue.push(start);
	isVisited[start] = true;
	while (!bfsQueue.empty())
	{
		int current = bfsQueue.front();
		count++;
		for (int i = 0; i < arr[current].size(); i++)
		{
			int nextTarget = arr[current].at(i);
			if (isVisited[nextTarget] == false)
			{
				isVisited[nextTarget] = true;
				bfsQueue.push(nextTarget);
			}
		}
		bfsQueue.pop();
	}
	return count;
}

void reset()
{
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new vector<int>[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		arr[B - 1].push_back(A - 1);
	}
	for (int i = 0; i < N; i++)
	{
		int currentNum = bfs(i);
		if (currentNum > maxNum)
		{
			maxNum = currentNum;
			while (!answerQueue.empty())
			{
				answerQueue.pop();
			}
			answerQueue.push(i);
		}
		else if (currentNum == maxNum)
		{
			answerQueue.push(i);
		}
		reset();
	}
	while (!answerQueue.empty())
	{
		cout << answerQueue.front() + 1 << " ";
		answerQueue.pop();
	}
	return 0;
}