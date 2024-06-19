#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
int factoryA, factoryB;
vector<pair<int, int>>* bridges;
bool* isVisited;
int answer = 0;
queue<int> bfsQueue;

void reset()
{
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	while (!bfsQueue.empty())
	{
		bfsQueue.pop();
	}
}

bool canMove(int weight)
{
	reset();
	isVisited[factoryA-1] = true;
	bfsQueue.push(factoryA-1);
	while (!bfsQueue.empty())
	{
		int currentIsland = bfsQueue.front();
		if (currentIsland == factoryB-1)
		{
			return true;
		}
		for (int i = 0; i < bridges[currentIsland].size(); i++)
		{
			pair<int, int> nodeInfo = bridges[currentIsland].at(i);
			if (isVisited[nodeInfo.first] == false && nodeInfo.second >= weight)
			{
				isVisited[nodeInfo.first] = true;
				bfsQueue.push(nodeInfo.first);
			}
		}
		bfsQueue.pop();
	}
	return false;
}

void binarySearch(int left, int right)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (canMove(mid) == true)
		{
			answer = max(answer, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, w;
	cin >> N>>M;
	bridges = new vector<pair<int, int>>[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> w;
		bridges[a - 1].push_back(pair(b - 1, w));
		bridges[b - 1].push_back(pair(a - 1, w));
	}
	cin >> factoryA >> factoryB;
	binarySearch(1, 1000000000);
	cout << answer << "\n";
	return 0;
}