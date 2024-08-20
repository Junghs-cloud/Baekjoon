#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

queue<pair<int, int>> bfsQueue;
pair<int, int>* convenienceStores;
pair<int, int> destination;
bool* isVisited;
bool canGo;
int N;

int calcDistance(pair<int, int>& p1, pair<int, int>& p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void bfs()
{
	while (!bfsQueue.empty())
	{
		pair<int, int> currentPos = bfsQueue.front();
		if (calcDistance(currentPos, destination) <= 1000)
		{
			canGo = true;
		}
		for (int i = 0; i < N; i++)
		{
			int distance = calcDistance(currentPos, convenienceStores[i]);
			if (distance <= 1000 && isVisited[i] == false)
			{
				isVisited[i] = true;
				bfsQueue.push(convenienceStores[i]);
			}
		}
		bfsQueue.pop();
	}
	if (canGo == true)
	{
		cout << "happy" << "\n";
	}
	else
	{
		cout << "sad" << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int x, y;
		cin >> N;
		convenienceStores = new pair<int, int>[N];
		isVisited = new bool[N];
		canGo = false;
		cin >> x >> y;
		bfsQueue.push(pair(x, y));
		for (int i = 0; i < N; i++)
		{
			cin >> convenienceStores[i].first >> convenienceStores[i].second;
			isVisited[i] = false;
		}
		cin >> destination.first >> destination.second;
		bfs();
	}
	return 0;
}