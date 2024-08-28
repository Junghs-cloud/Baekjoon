#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int>** classes;
pair<int, vector<int>>* friends;
int N;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

pair<int, int> getCount(int x, int y, int order)
{
	vector<int> like = friends[order].second;
	int friendsCount = 0;
	int vacancyCount = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && find(like.begin(), like.end(), classes[nextX][nextY].first) != like.end())
		{
			friendsCount++;
		}
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && classes[nextX][nextY] .first== -1)
		{
			vacancyCount++;
		}
	}
	return pair(friendsCount, vacancyCount);
}

void findPosition(int order)
{
	int studentNum = friends[order].first;
	pair<int, int> maxCount = pair(-1, -1);
	pair<int, int> sitPosition;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (classes[i][j].first == -1)
			{
				pair<int, int> current = getCount(i, j, order);
				if (current > maxCount)
				{
					maxCount = current;
					sitPosition = pair(i, j);
				}
			}
		}
	}
	classes[sitPosition.first][sitPosition.second].first = studentNum;
	classes[sitPosition.first][sitPosition.second].second = order;
}

int getSatisfaction(int x, int y)
{
	int studentNum = classes[x][y].first;
	int order = classes[x][y].second;
	vector<int> like = friends[order].second;
	int friendsCount = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && find(like.begin(), like.end(), classes[nextX][nextY].first) != like.end())
		{
			friendsCount++;
		}
	}
	if (friendsCount == 0)
	{
		return 0;
	}
	else if (friendsCount == 1)
	{
		return 1;
	}
	else if (friendsCount == 2)
	{
		return 10;
	}
	else if (friendsCount==3)
	{
		return 100;
	}
	else
	{
		return 1000;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int friendsNum;
	long long answer = 0;
	cin >> N;
	friends = new pair<int, vector<int>>[N * N];
	classes = new pair<int, int>* [N];
	for (int i = 0; i < N; i++)
	{
		classes[i] = new pair<int, int>[N];
		for (int j = 0; j < N; j++)
		{
			classes[i][j] = pair(-1, -1);
		}
	}
	for (int i = 0; i < N * N; i++)
	{
		cin >> friends[i].first;
		for (int j = 0; j < 4; j++)
		{
			cin >> friendsNum;
			friends[i].second.push_back(friendsNum);
		}
	}
	for (int i = 0; i < N * N; i++)
	{
		findPosition(i);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			answer+= getSatisfaction(i, j);
		}
	}
	cout << answer << "\n";
	return 0;
}