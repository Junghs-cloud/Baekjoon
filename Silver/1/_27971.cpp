#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
bool* isVisited;

vector<pair<int, int>> v;
queue<pair<int, int>> bfsQueue;
int N, A, B;

bool isInClosedSection(int num)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (num >= v.at(i).first && num <= v.at(i).second)
		{
			return true;
		}
	}
	return false;
}

void bfs()
{
	bool isFind = false;
	bfsQueue.push(pair(0, 0));
	isVisited[0] = 0;
	while (!bfsQueue.empty())
	{
		pair<int, int> front = bfsQueue.front();
		if (front.first == N)
		{
			isFind = true;
			cout << front.second << "\n";
			return;
		}
		if (front.first + A <= N && !isInClosedSection(front.first+A) && isVisited[front.first+A] == false)
		{
			isVisited[front.first + A] = true;
			bfsQueue.push(pair(front.first + A, front.second + 1));
		}
		if (front.first + B <= N && !isInClosedSection(front.first+B) && isVisited[front.first + B] == false)
		{
			isVisited[front.first + B] = true;
			bfsQueue.push(pair(front.first + B, front.second + 1));
		}
		bfsQueue.pop();
	}
	cout << -1 << "\n";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int M, start, end;
	cin >> N >> M >> A >> B;
	isVisited = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		v.push_back(pair(start, end));
	}
	bfs();
	return 0;
}