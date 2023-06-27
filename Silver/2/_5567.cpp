#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>* friends;
bool* isVisited;

void findFriends()
{
	for (int i = 0; i < (signed) friends[1].size(); i++)
	{
		int f = friends[1].at(i);
		isVisited[f] = true;
		for (int j = 0; j < (signed) friends[f].size(); j++)
		{
			int ff = friends[f].at(j);
			isVisited[ff] = true;
		}
	}
}

int main()
{
	int N, M;
	int a, b;
	cin >> N;
	cin >> M;
	friends = new vector<int>[N + 1];
	isVisited = new bool[N + 1];
	int inviteCount = 0;

	for (int i = 0; i < N + 1; i++)
	{
		isVisited[i] = false;
	}
	isVisited[1] = true;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	findFriends();
	for (int i = 2; i < N + 1; i++)
	{
		if (isVisited[i] == true)
		{
			inviteCount++;
		}
	}
	cout << inviteCount << "\n";
	return 0;
}