#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
vector<int>* v;
map<int, int> compliments;
map<int, int>::iterator it;
bool* isVisited;
int* dp;

void dfs()
{
	stack<int> dfsStack;
	dfsStack.push(1);
	isVisited[1] = true;
	while (!dfsStack.empty())
	{
		int current = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < v[current].size() && isAdjacent == false ; i++)
		{
			int nextPerson = v[current].at(i);
			if (isVisited[nextPerson] == false)
			{
				isVisited[nextPerson] = true;
				dfsStack.push(nextPerson);
				isAdjacent = true;
				dp[nextPerson] = dp[current];
				it = compliments.find(nextPerson);
				if (it != compliments.end())
				{
					dp[nextPerson] += it->second;
				}
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, i, w;
	int num;
	cin >> N >> M;
	v = new vector<int>[N + 1];
	isVisited = new bool[N + 1];

	dp = new int[N+1];
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		dp[i] = 0;
		isVisited[i] = false;
		if (num == -1)
		{
			continue;
		}
		v[num].push_back(i);
	}
	for (int j = 0; j < M; j++)
	{
		cin >> i >> w;
		it = compliments.find(i);
		if (it == compliments.end())
		{
			compliments.insert({i, w});
		}
		else
		{
			it->second += w;
		}
	}
	dfs();
	for (int i = 1; i <= N; i++)
	{
		cout << dp[i] << " ";
	}
	return 0;
}