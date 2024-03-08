#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <utility>
using namespace std;
bool* isVisited;
int* arr;
vector<int>* friends;
stack<int> dfsStack;
int answer = 0;
int K;
map<int, int> m;
vector<pair<int, int>> v;

void dfs(int firstNum)
{
	if (isVisited[firstNum] == true)
	{
		return;
	}
	isVisited[firstNum] = true;
	dfsStack.push(firstNum);
	int candy = 0;
	int friendsNumber = 0;
	while (!dfsStack.empty())
	{
		int current = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < friends[current].size(); i++)
		{
			int next = friends[current].at(i);
			if (isVisited[next] == false)
			{
				dfsStack.push(next);
				isVisited[next] = true;
				isAdjacent = true;
			}
		}
		if (isAdjacent == false)
		{
			candy += arr[current];
			friendsNumber++;
			dfsStack.pop();
		}
	}
	if (friendsNumber < K)
	{
		v.push_back(make_pair(friendsNumber, candy));
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int a, b;
	cin >> N>>M>>K;
	arr = new int[N];
	friends = new vector<int>[N];
	isVisited = new bool[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		isVisited[i] = false;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		friends[a - 1].push_back(b - 1);
		friends[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < N; i++)
	{
		dfs(i);
	}
	int size = v.size();
	int** dp = new int*[size+1];
	for (int i = 0; i < size+1; i++)
	{
		dp[i] = new int[K];
		for (int j = 0; j < K; j++)
		{
			dp[i][j] = 0;
		}
	}
	for (int i=0;i<size;i++)
	{
		int currentFriends = v.at(i).first;
		int currentCandy = v.at(i).second;
		for (int j = 0; j < K; j++)
		{
			if (j < currentFriends)
			{
				dp[i+1][j] = dp[i][j];
			}
			else if (j == currentFriends)
			{
				dp[i + 1][j] = max(dp[i][j], currentCandy);
			}
			else
			{
				dp[i + 1][j] = max(dp[i][j], dp[i][j - currentFriends] + currentCandy);
			}
		}
	}
	std::cout << dp[size][K-1] << "\n";
	return 0;
}