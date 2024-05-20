#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
queue<pair<int, int>> bfsQueue;
vector<int> candidate;
vector<int>* friends;
bool* isVisited;
int N;
int minPoints = 100;

void bfs(int num)
{
	int points = 0;
	bfsQueue.push(pair(num, 0));
	isVisited[num] = true;
	while (!bfsQueue.empty())
	{
		pair<int, int> current = bfsQueue.front();
		int currentNum = current.first;
		points = current.second;
		for (int i = 0; i < friends[currentNum].size(); i++)
		{
			if (isVisited[friends[currentNum].at(i)] == false)
			{
				isVisited[friends[currentNum].at(i)] = true;
				bfsQueue.push(pair(friends[currentNum].at(i), points + 1));
			}
		}
		bfsQueue.pop();
	}
	if (points < minPoints)
	{
		candidate.clear();
		candidate.push_back(num + 1);
		minPoints = points;
	}
	else if (points == minPoints)
	{
		candidate.push_back(num+1);
	}
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

	int A, B;
	cin >> N;
	friends = new vector<int>[N];
	isVisited = new bool[N];
	reset();
	while (true)
	{
		cin >> A >> B;
		if (A == -1 && B == -1)
		{
			break;
		}
		else
		{
			friends[A - 1].push_back(B - 1);
			friends[B - 1].push_back(A - 1);
		}
	}
	for (int i = 0; i < N; i++)
	{
		bfs(i);
		reset();
	}
	cout << minPoints <<" " << candidate.size() << "\n";
	for (int i = 0; i < candidate.size(); i++)
	{
		cout << candidate.at(i) << " ";
	}
	return 0;
}